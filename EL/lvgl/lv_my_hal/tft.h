/**
 * @file disp.h
 * 
 */

#ifndef TFT_H
#define TFT_H

/*********************
 *      INCLUDES
 *********************/
#include <stdint.h>
#include "lv_misc/lv_color.h"
#include "lv_misc/lv_area.h"

/*********************
 *      DEFINES
 *********************/
#define TFT_HOR_RES lcddev.width
#define TFT_VER_RES lcddev.height

#define TFT_EXT_FB		1		/*Frame buffer is located into an external SDRAM*/
#define TFT_USE_GPU		1		/*Enable hardware accelerator*/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
 void tft_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color);
void tft_init(void);

/**********************
 *      MACROS
 **********************/

#endif
