#ifndef _APP_H
#define _APP_H

#include "bsp_time.h"
#include "bsp_uart.h"

#include "dev_led.h"

#include "app_status.h"
#include "app_test.h"


void scheduler_init(void);
void scheduler_run(void);

void system_user_init(void);

#endif
