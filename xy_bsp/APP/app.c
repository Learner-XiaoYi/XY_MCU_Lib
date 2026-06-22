#include "app.h"

uint32_t app_tick = 0;


typedef struct 
	{
		void (*task_func)(void);
		uint32_t rate_ms;
		uint32_t last_run;
  	}task_t;
	 
static task_t scheduler_task[] =
{
	{app_key,10,0},
	{app_status,200,0}
};


uint8_t task_num;
void scheduler_init(void)
{
	task_num = sizeof(scheduler_task) / sizeof(task_t);
}

void scheduler_run(void) 
	{
		for(uint8_t i = 0;i < task_num;i++)
		{
			uint32_t now_time = BSP_GetTick(); 
			if(now_time >= scheduler_task[i].rate_ms + scheduler_task[i].last_run)
			{
				scheduler_task[i].last_run = now_time;
				scheduler_task[i].task_func();
			}
		}
  }

void system_user_init(void)	
{
	scheduler_init();
	BSP_UART_Init();
	LED_OFF();
	
	BSP_uart_text();
}	



