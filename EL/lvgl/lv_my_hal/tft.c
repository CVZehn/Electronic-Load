/**
 * @file disp.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include  "../lv_conf.h"
#include "lv_core/lv_vdb.h"
#include "lv_hal/lv_hal.h"
#include <string.h>
#include "sys.h"
#include "bsp_ili9325_lcd.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/*These 3 functions are needed by LittlevGL*/
void tft_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color);
static void tft_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p);
static void tft_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p);
//#if TFT_USE_GPU != 0
////static void gpu_mem_blend(lv_color_t * dest, const lv_color_t * src, uint32_t length, lv_opa_t opa);
////static void gpu_mem_fill(lv_color_t * dest, uint32_t length, lv_color_t color);
//#endif


/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Initialize your display here
 */
void tft_init(void)
{
	lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);

//#if TFT_EXT_FB != 0
//	SDRAM_Init();
//#endif
//	LCD_Config();
//	DMA_Config();

	disp_drv.disp_fill = tft_fill;
	disp_drv.disp_map = tft_map;
	disp_drv.disp_flush = tft_flush;
//#if TFT_USE_GPU != 0
//	DMA2D_Config();
//	disp_drv.mem_blend = gpu_mem_blend;
//	disp_drv.mem_fill = gpu_mem_fill;
//#endif
	lv_disp_drv_register(&disp_drv);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Flush a color buffer
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
static void tft_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
	uint16_t height,width;
	uint16_t i,j;
	width=x2-x1+1; 			//得到填充的宽度
	height=y2-y1+1;			//高度
//    BlockWrite(x1,x2,y1,y2);
 	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
            LCD_SetCursor(x1+j,y1+i);
            * ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_CMD ) = 0x0022;
            * ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_DATA ) = color_p->full;
			color_p++;	
		}
	}	
	lv_flush_ready();
}

/**
 * Fill a rectangular area with a color
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color fill color
 */
void tft_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color)
{
//    Set_ColorBox(x1,x2,y1,y2,color.full);
    LCD_Fill(x1,y1,x2,y2,color.full);
    
}


/**
 * Put a color map to a rectangular area
 * @param x1 left coordinate of the rectangle
 * @param x2 right coordinate of the rectangle
 * @param y1 top coordinate of the rectangle
 * @param y2 bottom coordinate of the rectangle
 * @param color_p pointer to an array of colors
 */
static void tft_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t * color_p)
{
	u16 height,width;
	u16 i,j;
	width=x2-x1+1; 			//得到填充的宽度
	height=y2-y1+1;			//高度
//    BlockWrite(x1,x2,y1,y2);
 	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
            LCD_SetCursor(x1+j,y1+i);
            * ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_CMD ) = 0x0022;
            * ( __IO uint16_t * ) ( FSMC_Addr_ILI9325_DATA ) = color_p->full;

			color_p++;	
		}
	}
}

