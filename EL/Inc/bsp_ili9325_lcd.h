#ifndef      __BSP_ILI9325_LCD_H
#define	     __BSP_ILI9325_LCD_H


#include "stm32f1xx.h"
#include "gpio.h"


/***************************************************************************************
2^26 =0X0400 0000 = 64MB,每个 BANK 有4*64MB = 256MB
64MB:FSMC_Bank1_NORSRAM1:0X6000 0000 ~ 0X63FF FFFF
64MB:FSMC_Bank1_NORSRAM2:0X6400 0000 ~ 0X67FF FFFF
64MB:FSMC_Bank1_NORSRAM3:0X6800 0000 ~ 0X6BFF FFFF
64MB:FSMC_Bank1_NORSRAM4:0X6C00 0000 ~ 0X6FFF FFFF

选择BANK1-BORSRAM1 连接 TFT，地址范围为0X6000 0000 ~ 0X63FF FFFF
FSMC_A16 接LCD的DC(寄存器/数据选择)脚
寄存器基地址 = 0X60000000
RAM基地址 = 0X60020000 = 0X60000000+2^16*2 = 0X60000000 + 0X20000 = 0X60020000
当选择不同的地址线时，地址要重新计算  
****************************************************************************************/

/******************************* ILI9341 显示屏的 FSMC 参数定义 ***************************/
//FSMC_Bank1_NORSRAM用于LCD命令操作的地址
#define      FSMC_Addr_ILI9325_CMD         ( ( uint32_t ) 0x60000000 )

//FSMC_Bank1_NORSRAM用于LCD数据操作的地址      
#define      FSMC_Addr_ILI9325_DATA        ( ( uint32_t ) 0x60800000 )

//由片选引脚决定的NOR/SRAM块
#define      FSMC_Bank1_NORSRAMx           FSMC_Bank1_NORSRAM1


/******************************* 定义 ILI934 显示屏常用颜色 ********************************/
#define      BACKGROUND		                BLACK   //默认背景颜色

#define      WHITE		 		                  0xFFFF	   //白色
#define      BLACK                         0x0000	   //黑色 
#define      GREY                          0xF7DE	   //灰色 
#define      BLUE                          0x001F	   //蓝色 
#define      BLUE2                         0x051F	   //浅蓝色 
#define      RED                           0xF800	   //红色 
#define      MAGENTA                       0xF81F	   //红紫色，洋红色 
#define      GREEN                         0x07E0	   //绿色 
#define      CYAN                          0x7FFF	   //蓝绿色，青色 
#define      YELLOW                        0xFFE0	   //黄色 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

/***************************** ILI934 显示区域的起始坐标和总行列数 ***************************/
#define      ILI9325_DispWindow_X_Star		    0     //起始点的X坐标
#define      ILI9325_DispWindow_Y_Star		    0     //起始点的Y坐标

#define 			ILI9325_LESS_PIXEL	  							240			//液晶屏较短方向的像素宽度
#define 			ILI9325_MORE_PIXEL	 								320			//液晶屏较长方向的像素宽度

//根据液晶扫描方向而变化的XY像素宽度
//调用ILI9341_GramScan函数设置方向时会自动更改
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH; 




void                     ILI9325_Init                    ( void );
void                     ILI9325_Rst                     ( void );
void                     BlockWrite                      (unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend); 

void                     Set_ColorBox                    (unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend,unsigned int Color);

void                    LCD_Fill                        (unsigned int sx,unsigned int sy,unsigned int ex,unsigned int ey,unsigned int color);
void                    LCD_SetCursor                   (unsigned int  Xpos, unsigned int  Ypos);
void test();

#endif /* __BSP_ILI9341_ILI9341_H */


