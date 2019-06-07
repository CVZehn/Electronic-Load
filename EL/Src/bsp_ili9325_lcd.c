

#include "bsp_ili9325_lcd.h"
#include "delay.h" 


static uint16_t CurrentTextColor   = BLACK;//前景色
static uint16_t CurrentBackColor   = WHITE;//背景色

__inline void                 WriteComm           ( uint16_t usCmd );
__inline void                 WriteData          ( uint16_t usData );
__inline uint16_t             ILI9325_Read_Data           ( void );
static void                   ILI9325_Delay               ( __IO uint32_t nCount );



/**
  * @brief  向ILI9325写入命令
  * @param  usCmd :要写入的命令（表寄存器地址）
  * @retval 无
  */	
__inline void WriteComm ( uint16_t usCmd )
{
	* ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_CMD ) = usCmd;
	
}


/**
  * @brief  向ILI9325写入数据
  * @param  usData :要写入的数据
  * @retval 无
  */	
__inline void WriteData ( uint16_t usData )
{
	* ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_DATA ) = usData;
	
}


/**
  * @brief  从ILI9325读取数据
  * @param  无
  * @retval 读取到的数据
  */	
__inline uint16_t ILI9325_Read_Data ( void )
{
	return ( * ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_DATA ) );
	
}


/**
  * @brief  用于 ILI9325 简单延时函数
  * @param  nCount ：延时计数值
  * @retval 无
  */	
static void ILI9325_Delay ( __IO uint32_t nCount )
{
  for ( ; nCount != 0; nCount -- );
	
}



/**
 * @brief  ILI9341初始化函数，如果要用到lcd，一定要调用这个函数
 * @param  无
 * @retval 无
 */
void ILI9325_Init ( void )
{
	ILI9325_Rst();


//--------------Start Initial Sequence--------------//
	WriteComm(0x0001);WriteData(0x0000); // set SS and SM bit
	WriteComm(0x0003);WriteData(0x1018); // set GRAM write direction and BGR=1.
	WriteComm(0x0060);WriteData(0x2700); // Gate Scan Line
	
	WriteComm(0x0002);WriteData(0x0700);// set 1 line inversion
	WriteComm(0x0004);WriteData(0x0000);// Resize register
	WriteComm(0x0008);WriteData(0x0207);// set the back porch and front porch
	WriteComm(0x0009);WriteData(0x0000);// set non-display area refresh cycle ISC[3:0]
	WriteComm(0x000A);WriteData(0x0000);// FMARK function
	WriteComm(0x000C);WriteData(0x0000);// RGB interface setting
	WriteComm(0x000D);WriteData(0x0000);// Frame marker Position
	WriteComm(0x000F);WriteData(0x0000);// RGB interface polarity
	
	//-------------Power On sequence------------//
	WriteComm(0x0010);WriteData(0x0000);// SAP, BT[3:0], AP, DSTB, SLP, STB
	WriteComm(0x0011);WriteData(0x0007);// DC1[2:0], DC0[2:0], VC[2:0]
	WriteComm(0x0012);WriteData(0x0000);// VREG1OUT voltage
	WriteComm(0x0013);WriteData(0x0000);// VDV[4:0] for VCOM amplitude
	WriteComm(0x0007);WriteData(0x0001);
	delay_ms(200); // Dis-charge capacitor power voltage
	
	WriteComm(0x0010);WriteData(0x1490);// SAP, BT[3:0], AP, DSTB, SLP, STB
	WriteComm(0x0011);WriteData(0x0227);// DC1[2:0], DC0[2:0], VC[2:0]
	delay_ms(50); // Delay 50ms
	
	WriteComm(0x0012);WriteData(0x0019);// Internal reference voltage= Vci;
	delay_ms(50); // Delay 50ms
	
	WriteComm(0x0013);WriteData(0x1000);// Set VDV[4:0] for VCOM amplitude
	WriteComm(0x0029);WriteData(0x0013);// Set VCM[5:0] for VCOMH
	WriteComm(0x002B);WriteData(0x000C);// Set Frame Rate
	delay_ms(50); // Delay 50ms
	
	WriteComm(0x0020);WriteData(0x0000);// GRAM horizontal Address
	WriteComm(0x0021);WriteData(0x0000);// GRAM Vertical Address
	
	// ----------- Adjust the Gamma Curve ----------//
	WriteComm(0x0030);WriteData(0x0000);
	WriteComm(0x0031);WriteData(0x0707);
	WriteComm(0x0032);WriteData(0x0307);
	WriteComm(0x0035);WriteData(0x0200);
	WriteComm(0x0036);WriteData(0x0008);
	WriteComm(0x0037);WriteData(0x0004);
	WriteComm(0x0038);WriteData(0x0000);
	WriteComm(0x0039);WriteData(0x0707);
	WriteComm(0x003C);WriteData(0x0002);
	WriteComm(0x003D);WriteData(0x0804);
	
	//------------------ Set GRAM area ---------------//
	WriteComm(0x0050);WriteData(0x0000);// Horizontal GRAM Start Address
	WriteComm(0x0051);WriteData(0x00EF);// Horizontal GRAM End Address
	WriteComm(0x0052);WriteData(0x0000);// Vertical GRAM Start Address
	WriteComm(0x0053);WriteData(0x013F);// Vertical GRAM Start Address
	WriteComm(0x0061);WriteData(0x0000);// NDL,VLE, REV
	
	//-------------- Partial Display Control ---------//
	WriteComm(0x0080);WriteData(0x0000);
	WriteComm(0x0081);WriteData(0x0000);
	WriteComm(0x0082);WriteData(0x0000);
	WriteComm(0x0083);WriteData(0x0000);
	WriteComm(0x0084);WriteData(0x0000);
	WriteComm(0x0085);WriteData(0x0000);
	
	//-------------- Panel Control -------------------//
	WriteComm(0x0090);WriteData(0x0010);
	WriteComm(0x0092);WriteData(0x0600);
	WriteComm(0x0007);WriteData(0x0133);// 262K color and display ON
}





/**
 * @brief  ILI9341 软件复位
 * @param  无
 * @retval 无
 */
void ILI9325_Rst ( void )
{			
	LL_GPIO_SetOutputPin ( LCD_RESET_GPIO_Port, LCD_RESET_Pin );		 	 

	delay_ms ( 800 ); 	
	LL_GPIO_ResetOutputPin ( LCD_RESET_GPIO_Port, LCD_RESET_Pin );	 //低电平复位

	delay_ms ( 800 ); 					   

	LL_GPIO_SetOutputPin ( LCD_RESET_GPIO_Port, LCD_RESET_Pin );		 	 

	delay_ms ( 800 ); 	
	
}

//设置光标位置
//Xpos:横坐标
//Ypos:纵坐标
void LCD_SetCursor(unsigned int Xpos, unsigned int Ypos)
{	 
	Xpos=320-1-Xpos;//横屏其实就是调转x,y坐标
	WriteComm(0x0021); 
	WriteData(Xpos); 	

	WriteComm(0x0020);  
	WriteData(Ypos); 
}

void LCD_Set_Window(unsigned int sx,unsigned int sy,unsigned int width,unsigned int height)
{
    u8 hsareg,heareg,vsareg,veareg;
	u16 hsaval,heaval,vsaval,veaval; 
	u16 twidth,theight;
	twidth=sx+width-1;
	theight=sy+height-1;		
    
	hsaval=sy;				
	heaval=theight;
	vsaval=320-twidth-1;
	veaval=320-sx-1;	

    WriteComm(0x0050);WriteData(hsaval);
    WriteComm(0x0051);WriteData(heaval);	
    
    WriteComm(0x0052);WriteData(vsaval);    
    WriteComm(0x0053);WriteData(veaval);	
	LCD_SetCursor(sx,sy);	//设置光标位置
}

void LCD_Fill(unsigned int sx,unsigned int sy,unsigned int ex,unsigned int ey,unsigned int color)
{          
	u16 i,j;
	u16 xlen=0;
	u16 temp;
	xlen=ex-sx+1;	 
	for(i=sy;i<=ey;i++)
	{
	 	LCD_SetCursor(sx,i);      				//设置光标位置 
        WriteComm(0x0022);  
		for(j=0;j<xlen;j++)WriteData(color);	//显示颜色 	    
	}
} 



