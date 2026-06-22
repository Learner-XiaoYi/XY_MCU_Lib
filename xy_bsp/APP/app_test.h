#ifndef _APP_TEST_H
#define _APP_TEST_H

#include "dev_led.h"
#include "dev_key.h"

typedef enum
{
    APP_STATE_NORMAL,
    APP_STATE_SETTING,
    APP_STATE_ALARM
} app_state_t;

void app_key(void);
void app_status(void);

#endif
