#ifndef      __BSP_ILI9325_LCD_H
#define	     __BSP_ILI9325_LCD_H


#include "stm32f1xx.h"
#include "gpio.h"


/***************************************************************************************
2^26 =0X0400 0000 = 64MB,ÿ�� BANK ��4*64MB = 256MB
64MB:FSMC_Bank1_NORSRAM1:0X6000 0000 ~ 0X63FF FFFF
64MB:FSMC_Bank1_NORSRAM2:0X6400 0000 ~ 0X67FF FFFF
64MB:FSMC_Bank1_NORSRAM3:0X6800 0000 ~ 0X6BFF FFFF
64MB:FSMC_Bank1_NORSRAM4:0X6C00 0000 ~ 0X6FFF FFFF

ѡ��BANK1-BORSRAM1 ���� TFT����ַ��ΧΪ0X6000 0000 ~ 0X63FF FFFF
FSMC_A16 ��LCD��DC(�Ĵ���/����ѡ��)��
�Ĵ�������ַ = 0X60000000
RAM����ַ = 0X60020000 = 0X60000000+2^16*2 = 0X60000000 + 0X20000 = 0X60020000
��ѡ��ͬ�ĵ�ַ��ʱ����ַҪ���¼���  
****************************************************************************************/

/******************************* ILI9341 ��ʾ���� FSMC �������� ***************************/
//FSMC_Bank1_NORSRAM����LCD��������ĵ�ַ
#define      FSMC_Addr_ILI9325_CMD         ( ( uint32_t ) 0x60000000 )

//FSMC_Bank1_NORSRAM����LCD���ݲ����ĵ�ַ      
#define      FSMC_Addr_ILI9325_DATA        ( ( uint32_t ) 0x60800000 )

//��Ƭѡ���ž�����NOR/SRAM��
#define      FSMC_Bank1_NORSRAMx           FSMC_Bank1_NORSRAM1


/******************************* ���� ILI934 ��ʾ��������ɫ ********************************/
#define      BACKGROUND		                BLACK   //Ĭ�ϱ�����ɫ

#define      WHITE		 		                  0xFFFF	   //��ɫ
#define      BLACK                         0x0000	   //��ɫ 
#define      GREY                          0xF7DE	   //��ɫ 
#define      BLUE                          0x001F	   //��ɫ 
#define      BLUE2                         0x051F	   //ǳ��ɫ 
#define      RED                           0xF800	   //��ɫ 
#define      MAGENTA                       0xF81F	   //����ɫ�����ɫ 
#define      GREEN                         0x07E0	   //��ɫ 
#define      CYAN                          0x7FFF	   //����ɫ����ɫ 
#define      YELLOW                        0xFFE0	   //��ɫ 
#define      BRED                          0xF81F
#define      GRED                          0xFFE0
#define      GBLUE                         0x07FF

/***************************** ILI934 ��ʾ�������ʼ������������� ***************************/
#define      ILI9325_DispWindow_X_Star		    0     //��ʼ���X����
#define      ILI9325_DispWindow_Y_Star		    0     //��ʼ���Y����

#define 			ILI9325_LESS_PIXEL	  							240			//Һ�����϶̷�������ؿ��
#define 			ILI9325_MORE_PIXEL	 								320			//Һ�����ϳ���������ؿ��

//����Һ��ɨ�跽����仯��XY���ؿ��
//����ILI9341_GramScan�������÷���ʱ���Զ�����
extern uint16_t LCD_X_LENGTH,LCD_Y_LENGTH; 




void                     ILI9325_Init                    ( void );
void                     ILI9325_Rst                     ( void );
void                     BlockWrite                      (unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend); 

void                     Set_ColorBox                    (unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend,unsigned int Color);

void                    LCD_Fill                        (unsigned int sx,unsigned int sy,unsigned int ex,unsigned int ey,unsigned int color);
void                    LCD_SetCursor                   (unsigned int  Xpos, unsigned int  Ypos);
void test();

#endif /* __BSP_ILI9341_ILI9341_H */


