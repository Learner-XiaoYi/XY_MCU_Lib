#include "app_status.h"


static app_state_t state = APP_STATE_NORMAL;

void app_key(void)
{
    key_10ms();

    if(key1.short_flag)
    {
        key1.short_flag = 0;

        // ×´Ì¬ÇÐ»»
        if(state == APP_STATE_NORMAL)
            state = APP_STATE_SETTING;
        else if(state == APP_STATE_SETTING)
            state = APP_STATE_ALARM;
        else
            state = APP_STATE_NORMAL;
    }
}

void app_status(void)
{
    switch(state)
    {
        case APP_STATE_NORMAL:
            LED_RedGreen_Task();
            break;

        case APP_STATE_SETTING:
            LED_Rainbow_Task();
            break;

        case APP_STATE_ALARM:
            LED_Alarm_Task();
            break;
    }
}

