#include "dev_key.h"

KEY_t key1 = {{GPIOE, GPIO_PIN_0}, 1, 0, 0, 0};
KEY_t key2 = {{GPIOE, GPIO_PIN_1}, 1, 0, 0, 0};
KEY_t key3 = {{GPIOE, GPIO_PIN_2}, 1, 0, 0, 0};
KEY_t key4 = {{GPIOE, GPIO_PIN_3}, 1, 0, 0, 0};

//10ms
void key_show(KEY_t *k)
{
    uint8_t level = BSP_GPIO_Read(&k->gpio);
    k->last_level = level;

    // 按下计时
    if(level == GPIO_LOW)
    {
        if(k->cnt < 0xFFFF)
            k->cnt++;
    }
    else
    {
        // 松手判断
        if(k->cnt > KEY_FILTER_TIME && k->cnt < KEY_LONG_TIME)
        {
            k->short_flag = 1;
        }
        else if(k->cnt >= KEY_LONG_TIME)
        {
            k->long_flag = 1;
        }
        // 清计时
        k->cnt = 0;
    }
}

void key_10ms(void)
{
	key_show(&key1);
	key_show(&key2);
	key_show(&key3);
	key_show(&key4);
}



