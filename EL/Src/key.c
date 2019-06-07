#include "key.h"

/******************************************************
KEY1  短按：充电开关 
KEY2  短按：模式切换
KEY3  短按: 移动光标
KEY4:
KEY5:
KEY6:
******************************************************/


unsigned char Get_keynum()
{
   unsigned char keynum;
   if(LL_GPIO_IsInputPinSet(KEY1_GPIO_Port, KEY1_Pin)==0)
   {
       delay_ms(5);
       if(LL_GPIO_IsInputPinSet(KEY1_GPIO_Port, KEY1_Pin)==0)
       {
            while(LL_GPIO_IsInputPinSet(KEY1_GPIO_Port, KEY1_Pin)==0);
            keynum= Single_Key1;   
       }
   }
  else  if(LL_GPIO_IsInputPinSet(KEY2_GPIO_Port, KEY2_Pin)==0)
   {
       delay_ms(5);
        if(LL_GPIO_IsInputPinSet(KEY2_GPIO_Port, KEY2_Pin)==0)
        {
            while(LL_GPIO_IsInputPinSet(KEY2_GPIO_Port, KEY2_Pin)==0);
            keynum=  Single_Key2;   
        }
   }
   else if(LL_GPIO_IsInputPinSet(KEY3_GPIO_Port, KEY3_Pin)==0)
   {
       delay_ms(5);
        if(LL_GPIO_IsInputPinSet(KEY3_GPIO_Port, KEY3_Pin)==0)
        {
            while(LL_GPIO_IsInputPinSet(KEY3_GPIO_Port, KEY3_Pin)==0);
            keynum=  Single_Key3;   
        }
   }
   else if(LL_GPIO_IsInputPinSet(KEY4_GPIO_Port, KEY4_Pin)==0)
   {
       delay_ms(5);
        if(LL_GPIO_IsInputPinSet(KEY4_GPIO_Port, KEY4_Pin)==0)
        {
            while(LL_GPIO_IsInputPinSet(KEY4_GPIO_Port, KEY4_Pin)==0);
            keynum=  Single_Key4;   
        }
   }
   else if(LL_GPIO_IsInputPinSet(KEY5_GPIO_Port, KEY5_Pin)==0)
   {
       delay_ms(5);
        if(LL_GPIO_IsInputPinSet(KEY5_GPIO_Port, KEY5_Pin)==0)
        {
            while(LL_GPIO_IsInputPinSet(KEY5_GPIO_Port, KEY5_Pin)==0);
            keynum=  Single_Key5;   
        }
   }
   else if(LL_GPIO_IsInputPinSet(KEY6_GPIO_Port, KEY6_Pin)==0)
   {
       delay_ms(5);
        if(LL_GPIO_IsInputPinSet(KEY6_GPIO_Port, KEY6_Pin)==0)
        {
            while(LL_GPIO_IsInputPinSet(KEY6_GPIO_Port, KEY6_Pin)==0);
            keynum=  Single_Key6; 
        }            
   }
   else
   {
       keynum=0;
   }
    return keynum;;     
}
unsigned char Get_Keyvalue()
{
    if((keyvalue[first_keynum]==keyvalue[second_keynum])&&(keyvalue[first_keynum]!=0))
    {
        if(keyvalue[first_keynum]==Single_Key1)
        {
            return Long_Key1;
        }
        if(keyvalue[first_keynum]==Single_Key2)
        {
            return Long_Key2;
        }
        if(keyvalue[first_keynum]==Single_Key3)
        {
            return Long_Key3;
        }
        if(keyvalue[first_keynum]==Single_Key4)
        {
            return Long_Key4;
        }
        if(keyvalue[first_keynum]==Single_Key5)
        {
            return Long_Key5;
        }
        if(keyvalue[first_keynum]==Single_Key6)
        {
            return Long_Key6;
        }
    }
    else
    {
        return keyvalue[first_keynum];
    }
    return 0;
}
