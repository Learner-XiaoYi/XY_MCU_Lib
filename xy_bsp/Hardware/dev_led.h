#ifndef _DEV_LED_H
#define _DEV_LED_H

#include "bsp_gpio.h"

typedef struct
{
    BSP_GPIO_t R;
    BSP_GPIO_t G;
    BSP_GPIO_t B;
} RGB_LED_t;


extern RGB_LED_t LED1;

void LED_Set(RGB_LED_t *led, uint8_t r, uint8_t g, uint8_t b);
void LED_OFF(void);

/*===========»¨Ê½µãµÆ=============*/
//ÉÁË¸ 50ms
void LED_Blink_Task(void);
//ºìÂÌ½»ÌæµÆ200ms
void LED_RedGreen_Task(void);
//RGBÅÜÂíµÆ£¨100ms£© 
void LED_Rainbow_Task(void);
//ºôÎüµÆ 10ms
void LED_Breath_Task(void);
//ĞÄÌøµÆ 100ms
void LED_Heartbeat_Task(void);
//±¨¾¯µÆ 10ms
void LED_Alarm_Task(void);
//ºôÎü + ÑÕÉ«½¥±ä 10ms
void LED_Fade_Task(void);
//ÂÌµÆ ¡ú »ÆµÆ ¡ú ºìµÆÑ­»· 100ms
void LED_TrafficLight_Task(void);
#endif
