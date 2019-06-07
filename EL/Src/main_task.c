#include "main_task.h"
#include "lvgl.h"
#include "stdlib.h"
#include "gpio.h"
#include "key.h"

LV_IMG_DECLARE(img_bubble_pattern);

lv_chart_series_t *ser1;
lv_obj_t *scr ;
lv_obj_t *scr1 ;
lv_obj_t *chart;
lv_obj_t *box1;
lv_obj_t *title1;


lv_obj_t *temperature;
lv_obj_t *model1;
lv_obj_t *model2;
lv_obj_t *banner;
lv_obj_t *box2;
lv_obj_t *box3;
lv_obj_t *box_cursor;
lv_obj_t *sw;
lv_obj_t *text1;
lv_obj_t *text2;
lv_obj_t *text3;
lv_obj_t *text4;
lv_obj_t *text5;
lv_obj_t *text6;
lv_obj_t *text7;//P
lv_obj_t *text8;//O V
lv_obj_t *text9;//P
lv_obj_t *text10;//O V


lv_obj_t *text_BA;//O V
lv_obj_t *text_TEMP;//P
lv_obj_t *text_TIME;//O V
lv_obj_t *text_OK;//O V


lv_obj_t *text11;//提示框


char textC_set[]={"C:123A"};
char textV_set[]={"C:123A"};
char textVO_set[]={"C:123A"};
char textP_set[]={"C:123A"};
float valu_C= 11.23;
float valu_V= 11.23;
float valu_P= 11.23;
float valu_VO= 11.23;

static lv_style_t style1;
static lv_style_t style2;
static lv_style_t style_box;
static lv_style_t style_R;
static lv_style_t style_G;
static lv_style_t style_B;
static lv_style_t style_O;
static lv_style_t style3;   


unsigned char cursor_position_V[3]={110,120,135};
unsigned char cursor_position_V_p[3]={110,125,135};
unsigned char cursor_position_C[3]={30,40,55};
unsigned char cursor_position_C_p[3]={30,45,55};
unsigned char cursor_num=1;
float *model=&valu_V;


void main_task()
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
    
    lv_style_copy(&style_box,&lv_style_plain);
    style_box.body.main_color =  LV_COLOR_WHITE;
    style_box.body.grad_color = LV_COLOR_SILVER;
    
    lv_style_copy(&style2,&lv_style_plain);
    style2.body.main_color = LV_COLOR_GRAY;
    style2.body.grad_color = LV_COLOR_GRAY;
    style2.body.radius = 0;
    style2.line.width = 1;
    style2.body.opa = LV_OPA_50;
    style2.line.color = LV_COLOR_SILVER;
    style2.line.opa =120;
    
    lv_style_copy(&style3, &lv_style_pretty); 
    style3.body.main_color = LV_COLOR_GREEN; 
    style3.body.grad_color = LV_COLOR_RED;   
    style3.body.padding.hor = 6;       
    style3.body.padding.inner = 10;   
    style3.body.padding.ver = 8;       
    style3.body.border.color= LV_COLOR_GRAY;   
    style3.line.width = 2; 
    style3.text.font = &lv_font_dejavu_10;
    
    scr1= lv_obj_create(NULL,NULL);
    lv_scr_load(scr1);
    
    scr= lv_obj_create(NULL,NULL);
    lv_scr_load(scr);
    
    
    box1 = lv_btn_create(scr,NULL);
    lv_obj_set_style(box1,&style_box);
    lv_obj_set_size(box1,320,240);
    lv_obj_set_pos(box1,0,0);
    
    
    box2 = lv_btn_create(scr,NULL);
    lv_obj_set_style(box2,&lv_style_pretty);
    lv_obj_set_size(box2,320,20);
    lv_obj_set_pos(box2,0,0);
    

    box3 = lv_btn_create(scr,box2);
    lv_obj_set_size(box3,170,319);
    lv_obj_set_pos(box3,0,20);
    
    
    box_cursor = lv_btn_create(scr,NULL);
    lv_obj_set_style(box_cursor,&lv_style_btn_ina);
    lv_obj_set_size(box_cursor,8,20);
    lv_obj_set_pos(box_cursor,110,120);
    
    
    temperature =lv_gauge_create(scr,NULL);
    lv_obj_set_style(temperature,&style3);
    lv_obj_set_size(temperature,100,100);
    lv_obj_set_pos(temperature,200,35);
    
    model1 = lv_cb_create(scr,NULL);
    lv_obj_set_pos(model1,5,40);
    lv_cb_set_text(model1,"CC");
    model2 = lv_cb_create(scr,model1);
    lv_obj_set_pos(model2,5,70);
    lv_cb_set_text(model2,"CV");
    lv_cb_set_checked(model1,1);
    
    chart = lv_chart_create(scr,NULL);
    lv_obj_set_style(chart,&style2);
    lv_chart_set_series_opa(chart, LV_OPA_50);
    lv_chart_set_point_count(chart,100);
    lv_chart_set_series_width(chart,2);
    lv_chart_set_range(chart,0,4095);
    lv_obj_set_size(chart,150,110);
    lv_obj_set_pos(chart,170,130);
    
    
    sw = lv_sw_create(scr,NULL);
    lv_obj_set_style(sw,&lv_style_pretty);
    lv_obj_set_pos(sw,80,45);
    
    
//    
//    
    text1 = lv_label_create (scr,NULL);
    text2 = lv_label_create (scr,NULL);
    text3 = lv_label_create (scr,NULL);
    text4 = lv_label_create (scr,NULL);
    text5 = lv_label_create (scr,NULL);
    text6 = lv_label_create (scr,NULL);
    
    text7 = lv_label_create (scr,NULL);
    text8 = lv_label_create (scr,NULL);
    text9 = lv_label_create (scr,NULL);
    text10 = lv_label_create (scr,NULL);
    text11 = lv_label_create (scr,NULL);
    text_BA = lv_label_create (scr,NULL);
    
    text_OK = lv_label_create (scr,NULL);
    text_TEMP = lv_label_create (scr,NULL);
//    
//    
    lv_label_set_text(text1,"Charge");
    lv_label_set_text(text2,SYMBOL_SETTINGS);
    
    sprintf(textC_set,"%3.1f",valu_C);
    lv_label_set_array_text(text3,textC_set ,7);
    lv_label_set_text(text4,"C:     A");
    
    sprintf(textV_set,"%3.1f",valu_V);
    lv_label_set_array_text(text5,textV_set ,7);
    lv_label_set_text(text6,"V:     V");
    
    
    sprintf(textP_set,"%3.1f",valu_P);
    lv_label_set_array_text(text7,textP_set ,7);
    lv_label_set_text(text8,"P:     W");
    
    sprintf(textVO_set,"%3.1f",valu_VO);
    lv_label_set_array_text(text9,textVO_set ,7);
    lv_label_set_text(text10,SYMBOL_CHARGE":     V");

    lv_label_set_text(text11,SYMBOL_LOOP":No load");
    lv_label_set_text(text11,SYMBOL_SHUFFLE":Work");
    lv_label_set_text(text11,SYMBOL_WARNING":Unconstant\n    current");
    lv_label_set_text(text11,SYMBOL_WARNING":Unconstant\n    pressure");
    
    lv_label_set_text(text_BA,SYMBOL_BATTERY_EMPTY);
    lv_label_set_text(text_OK,SYMBOL_OK);
    
    lv_label_set_text(text_TEMP,"temperature");
    
//    
    lv_obj_set_pos(text1,80,75);
    lv_obj_set_pos(text2,300,0);
    lv_obj_set_pos(text3,30,120);
    lv_obj_set_pos(text4,10,120);
    lv_obj_set_pos(text5,110,120);
    lv_obj_set_pos(text6,90,120);
    lv_obj_set_pos(text7,30,150);
    lv_obj_set_pos(text8,10,150);
    lv_obj_set_pos(text9,110,150);
    lv_obj_set_pos(text10,90,150);
    lv_obj_set_pos(text11,10,185);
    lv_obj_set_pos(text_BA,270,0);
    lv_obj_set_pos(text_OK,130,45);
    lv_obj_set_pos(text_TEMP,190,110);
    
    title1 = lv_label_create(scr,NULL);
    lv_label_set_text(title1," Electronic Load");
    lv_obj_set_pos(title1,0,0);
    
    
}
void Input_value()
{
    unsigned char keyvalue;
    keyvalue=Get_keynum();
    if(keyvalue==1)
    {
        if(*model==valu_V)
        {
            model=&valu_C;
            lv_cb_set_checked(model1,1);
            lv_cb_set_checked(model2,0);
        }
        else if(*model==valu_C)
        {
            model=&valu_V;
            lv_cb_set_checked(model1,0);
            lv_cb_set_checked(model2,1);
        }
    }
    if(keyvalue==6)
    {
        if(cursor_num==0)//小数位
        {
            *model=*model+0.1;
        }
        if(cursor_num==2)//十数位
        {
            *model=*model+1;
        }
        
        if(cursor_num==1)//个数位
        {
            *model=*model+10;
        }
        if(*model>99)
        {
            *model=99;
        }
        if(*model==valu_V)
        {
            sprintf(textV_set,"%03.1f",*model);
            lv_label_set_text(text5,textV_set);
        }
        else if(*model==valu_C)
        {
            sprintf(textC_set,"%03.1f",*model);
            lv_label_set_text(text3,textC_set);
        }
    }
    if(keyvalue==2)
    {
        if(cursor_num==0)//小数位
        {
            *model=*model-0.1;
        }
        if(cursor_num==2)//十数位
        {
            *model=*model-1;
        }
        
        if(cursor_num==1)//个数位
        {
            *model=*model-10;
        }
        if(*model<0)
        {
            *model=0;
        }
        if(*model==valu_V)
        {
            sprintf(textV_set,"%03.1f",*model);
            lv_label_set_text(text5,textV_set);
        }
        else if(*model==valu_C)
        {
            sprintf(textC_set,"%03.1f",*model);
            lv_label_set_text(text3,textC_set);
        }
    }
   if(keyvalue==3)
    {
        if(*model==valu_V)
        {
            if(valu_V<10)
            {
                lv_obj_set_pos(box_cursor,cursor_position_V_p[cursor_num],120);
            }
            else
            {
                lv_obj_set_pos(box_cursor,cursor_position_V[cursor_num],120);
            }
        }
        if(*model==valu_C)
        {
            if(valu_V<10)
            {
                lv_obj_set_pos(box_cursor,cursor_position_C_p[cursor_num],120);
            }
            else
            {
                lv_obj_set_pos(box_cursor,cursor_position_C[cursor_num],120);
            }
        }
        cursor_num++;
        if(cursor_num>2)
        {
            cursor_num=0;
        }
    }
}