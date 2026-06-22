#ifndef _DEV_KEY_H
#define _DEV_KEY_H

#include "bsp_gpio.h"

#define KEY_FILTER_TIME     3      // 消抖滤波时间 30ms
#define KEY_LONG_TIME       100    // 长按判定阈值 1s
#define KEY_DOUBLE_TIME     30     // 双击间隔阈值 300ms
#define KEY_REPEAT_TIME     20     // 长按连发间隔 200ms

//结果
typedef enum
{
    KEY_EVENT_NONE,     //无

    KEY_EVENT_SHORT,    //短
    KEY_EVENT_LONG,     //长

} KEY_EVENT_t;

//按键对象
typedef struct
{
    BSP_GPIO_t gpio;

    uint8_t last_level;  //上一拍电平,边沿判断
    uint16_t cnt;        //按下持续时间计数器

    uint8_t short_flag;   // 短按标志
    uint8_t long_flag;    // 长按标志
} KEY_t;

extern KEY_t key1;
extern KEY_t key2;
extern KEY_t key3;
extern KEY_t key4;

void key_10ms(void);

#endif
