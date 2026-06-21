#include "dev_led.h"


RGB_LED_t LED1 =
{
    {GPIOE, GPIO_PIN_6},  // R
    {GPIOE, GPIO_PIN_5},  // G
    {GPIOE, GPIO_PIN_4}   // B
};

//BSP_GPIO_Set
//BSP_GPIO_Reset
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

//»¨Ê½µãµÆ
//ÉÁË¸ 50ms
void LED_Blink_Task(void)
{
    static uint8_t state = 0;

    state = !state;

    // ºìµÆÉÁË¸
    LED_Set(&LED1, state, 0, 0);
}

//ºìÂÌ½»ÌæµÆ200ms
void LED_RedGreen_Task(void)
{
    static uint8_t state = 0;

    state++;

    if(state % 2 == 0)
    {
        LED_Set(&LED1, 1, 0, 0); // ºì
    }
    else
    {
        LED_Set(&LED1, 0, 1, 0); // ÂÌ
    }
}

//RGBÅÜÂíµÆ£¨100ms£© 
void LED_Rainbow_Task(void)
{
    static uint8_t step = 0;

    step++;

    switch(step % 6)
    {
        case 0: LED_Set(&LED1, 1,0,0); break; // ºì
        case 1: LED_Set(&LED1, 1,1,0); break; // »Æ
        case 2: LED_Set(&LED1, 0,1,0); break; // ÂÌ
        case 3: LED_Set(&LED1, 0,1,1); break; // Çà
        case 4: LED_Set(&LED1, 0,0,1); break; // À¶
        case 5: LED_Set(&LED1, 1,0,1); break; // ×Ï
    }
}

//ºôÎüµÆ 10ms
void LED_Breath_Task(void)
{
    static uint8_t dir = 0;
    static uint8_t pwm = 0;

    if(dir == 0)
        pwm++;
    else
        pwm--;

    // ¼òµ¥ãÐÖµÄ£Äâ£¨ÎÞPWM°æ£©
    LED_Set(&LED1, pwm > 128 ? 1 : 0, 0, 0);

    if(pwm == 255)
        dir = 1;
    else if(pwm == 0)
        dir = 0;
}

//ÐÄÌøµÆ 100ms
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

//±¨¾¯µÆ 10ms
void LED_Alarm_Task(void)
{
    static uint8_t state = 0;

    state = !state;

    // ºìµÆ¿ìËÙÉÁË¸
    LED_Set(&LED1, state, 0, 0);
}

//ºôÎü + ÑÕÉ«½¥±ä 10ms
void LED_Fade_Task(void)
{
    static uint8_t pwm = 0;
    static uint8_t dir = 0;

    if(dir == 0)
        pwm++;
    else
        pwm--;

    // ¼òµ¥×´Ì¬ÇÐ»»
    LED_Set(&LED1,
             pwm < 128 ? 1 : 0,
             pwm >= 128 ? 1 : 0,
             0);

    if(pwm == 255)
        dir = 1;
    if(pwm == 0)
        dir = 0;
}

//ÂÌµÆ ¡ú »ÆµÆ ¡ú ºìµÆÑ­»· 100ms
void LED_TrafficLight_Task(void)
{
    static uint16_t cnt = 0;

    cnt++;

    // ===== ºìµÆ½×¶Î =====
    if(cnt < 30)   // 3Ãë£¨100ms * 30£©
    {
        LED_Set(&LED1, 1, 0, 0);   // ºìµÆÁÁ
    }
    // ===== ÂÌµÆ½×¶Î =====
    else if(cnt < 60) // 3Ãë
    {
        LED_Set(&LED1, 0, 1, 0);   // ÂÌµÆÁÁ
    }
    // ===== »ÆµÆ½×¶Î =====
    else if(cnt < 75) // 1.5Ãë
    {
        LED_Set(&LED1, 1, 1, 0);   // »ÆµÆ£¨ºì+ÂÌ£©
    }
    // ===== ÖØÐÂÑ­»· =====
    else
    {
        cnt = 0;
    }
}

