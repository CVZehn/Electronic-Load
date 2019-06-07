/**
 * @file demo.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"

#ifdef USE_DEMO
#include "demo.h"  

lv_chart_series_t *ser1;
lv_chart_series_t *ser2;
lv_chart_series_t *ser3;
lv_chart_series_t *ser4;
lv_obj_t *scr ;
lv_obj_t *chart;
lv_obj_t *ch1;
lv_obj_t *ch2;
lv_obj_t *ch3;
lv_obj_t *ch4;
lv_obj_t *box1;
lv_obj_t *title1;

static lv_style_t style1;
static lv_style_t style2;
static lv_style_t style_R;
static lv_style_t style_G;
static lv_style_t style_B;
static lv_style_t style_O;




void demo()
{
    lv_style_copy(&style1,&lv_style_plain);
    style1.body.main_color = LV_COLOR_BLACK;
    style1.line.width = 1;
    
    
    lv_style_copy(&style_R,&lv_style_plain);//红色字体
//    style1.body.main_color = LV_COLOR_RED;
    style_R.text.color = LV_COLOR_RED;
    style_R.text.opa = 100;
    
    lv_style_copy(&style_G,&lv_style_plain);//绿色字体
//    style1.body.main_color = LV_COLOR_GREEN;
    style_G.text.color = LV_COLOR_GREEN;
    style_G.text.opa = 100;
    
    lv_style_copy(&style_B,&lv_style_plain);//蓝色字体
//    style1.body.main_color = LV_COLOR_BLUE;
    style_B.text.color = LV_COLOR_BLUE;
    style_B.text.opa = 100;
    
    lv_style_copy(&style_O,&lv_style_plain);//橙色字体
//    style1.body.main_color = LV_COLOR_ORANGE;
    style_O.text.color = LV_COLOR_ORANGE;
    style_O.text.opa = 100;
    
    
    lv_style_copy(&style2,&lv_style_plain);
    style2.body.main_color = LV_COLOR_GRAY;
    style2.body.grad_color = LV_COLOR_SILVER;
    style2.body.radius = 0;
    style2.line.width = 1;
    
    scr= lv_obj_create(NULL,NULL);
    lv_scr_load(scr);
    lv_obj_set_style(scr,&style1);
    
    box1 = lv_btn_create(scr,NULL);
    lv_obj_set_style(box1,&lv_style_pretty);
    lv_obj_set_size(box1,320,240);
    lv_obj_set_pos(box1,0,0);
    
    chart = lv_chart_create(scr,NULL);
    lv_obj_set_style(chart,&style2);
    lv_chart_set_series_opa(chart, LV_OPA_50);
    lv_chart_set_point_count(chart,100);
    ser1=lv_chart_add_series(chart,LV_COLOR_RED);
    ser2=lv_chart_add_series(chart,LV_COLOR_GREEN);
    ser3=lv_chart_add_series(chart,LV_COLOR_BLUE);
    ser4=lv_chart_add_series(chart,LV_COLOR_ORANGE);
    lv_chart_set_series_width(chart,2);
    lv_chart_set_range(chart,0,4095);
    lv_obj_set_size(chart,250,180);
    lv_obj_set_pos(chart,50,20);
    
//    
    
    ch1 = lv_label_create (scr,NULL);
    ch2 = lv_label_create (scr,NULL);
    ch3 = lv_label_create (scr,NULL);
    ch4 = lv_label_create (scr,NULL);
    
    
    lv_label_set_text(ch1,"CH1");
    lv_label_set_text(ch2,"CH2");
    lv_label_set_text(ch3,"CH3");
    lv_label_set_text(ch4,"CH4");
    
    
    lv_obj_set_pos(ch1,8,35);
    lv_obj_set_pos(ch2,8,75);
    lv_obj_set_pos(ch3,8,115);
    lv_obj_set_pos(ch4,8,155);
    
    lv_obj_set_style(ch1,&style_R);
    lv_obj_set_style(ch2,&style_G);
    lv_obj_set_style(ch3,&style_B);
    lv_obj_set_style(ch4,&style_O);
    
    title1 = lv_label_create(scr,NULL);
    lv_label_set_text(title1,"TIME WAVE");
    lv_obj_set_pos(title1,120,210);
    
    
    
}
#endif