#include "dev_led.h"


RGB_LED_t LED1 =
{
    {GPIOE, GPIO_PIN_6},  // R
    {GPIOE, GPIO_PIN_5},  // G
    {GPIOE, GPIO_PIN_4}   // B
};

//设置灯色
void LED_Set(RGB_LED_t *led, uint8_t r, uint8_t g, uint8_t b)
{
    if(r)
        BSP_GPIO_Reset(&led->R);
    else
        BSP_GPIO_Set(&led->R);

    if(g)
        BSP_GPIO_Reset(&led->G);
    else
        BSP_GPIO_Set(&led->G);

    if(b)
        BSP_GPIO_Reset(&led->B);
    else
        BSP_GPIO_Set(&led->B);
}

void LED_OFF(void)
{
	LED_Set(&LED1,0,0,0);
}

//花式点灯
//闪烁 50ms
void LED_Blink_Task(void)
{
    static uint8_t state = 0;

    state = !state;

    // 红灯闪烁
    LED_Set(&LED1, state, 0, 0);
}

//红绿交替灯200ms
void LED_RedGreen_Task(void)
{
    static uint8_t state = 0;

    state++;

    if(state % 2 == 0)
    {
        LED_Set(&LED1, 1, 0, 0); // 红
    }
    else
    {
        LED_Set(&LED1, 0, 1, 0); // 绿
    }
}

//RGB跑马灯（100ms） 
void LED_Rainbow_Task(void)
{
    static uint8_t step = 0;

    step++;

    switch(step % 6)
    {
        case 0: LED_Set(&LED1, 1,0,0); break; // 红
        case 1: LED_Set(&LED1, 1,1,0); break; // 黄
        case 2: LED_Set(&LED1, 0,1,0); break; // 绿
        case 3: LED_Set(&LED1, 0,1,1); break; // 青
        case 4: LED_Set(&LED1, 0,0,1); break; // 蓝
        case 5: LED_Set(&LED1, 1,0,1); break; // 紫
    }
}

//呼吸灯 10ms
void LED_Breath_Task(void)
{
    static uint8_t dir = 0;
    static uint8_t pwm = 0;

    if(dir == 0)
        pwm++;
    else
        pwm--;

    // 简单阈值模拟（无PWM版）
    LED_Set(&LED1, pwm > 128 ? 1 : 0, 0, 0);

    if(pwm == 255)
        dir = 1;
    else if(pwm == 0)
        dir = 0;
}

//心跳灯 100ms
void LED_Heartbeat_Task(void)
{
    static uint16_t cnt = 0;

    cnt++;

    if(cnt < 2)
        LED_Set(&LED1, 1, 0, 0);
    else if(cnt < 4)
        LED_Set(&LED1, 0, 0, 0);
    else if(cnt < 6)
        LED_Set(&LED1, 1, 0, 0);
    else
    {
        LED_Set(&LED1, 0, 0, 0);
        cnt = 0;
    }
}

//报警灯 10ms
void LED_Alarm_Task(void)
{
    static uint8_t state = 0;

    state = !state;

    // 红灯快速闪烁
    LED_Set(&LED1, state, 0, 0);
}

//呼吸 + 颜色渐变 10ms
void LED_Fade_Task(void)
{
    static uint8_t pwm = 0;
    static uint8_t dir = 0;

    if(dir == 0)
        pwm++;
    else
        pwm--;

    // 简单状态切换
    LED_Set(&LED1,
             pwm < 128 ? 1 : 0,
             pwm >= 128 ? 1 : 0,
             0);

    if(pwm == 255)
        dir = 1;
    if(pwm == 0)
        dir = 0;
}

//绿灯 → 黄灯 → 红灯循环 100ms
void LED_TrafficLight_Task(void)
{
    static uint16_t cnt = 0;

    cnt++;

    // ===== 红灯阶段 =====
    if(cnt < 30)   // 3秒（100ms * 30）
    {
        LED_Set(&LED1, 1, 0, 0);   // 红灯亮
    }
    // ===== 绿灯阶段 =====
    else if(cnt < 60) // 3秒
    {
        LED_Set(&LED1, 0, 1, 0);   // 绿灯亮
    }
    // ===== 黄灯阶段 =====
    else if(cnt < 75) // 1.5秒
    {
        LED_Set(&LED1, 1, 1, 0);   // 黄灯（红+绿）
    }
    // ===== 重新循环 =====
    else
    {
        cnt = 0;
    }
}

