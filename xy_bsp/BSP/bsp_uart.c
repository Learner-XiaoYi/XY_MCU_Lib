#include "bsp_uart.h"

extern UART_HandleTypeDef huart1;

static uint8_t uart_rx_buf[UART_RX_SIZE];
static volatile uint16_t rx_len = 0;

void BSP_UART_Init(void)
{
	
}

void BSP_UART_Send(uint8_t *data, uint16_t len)
{
    HAL_UART_Transmit(&huart1, data, len, 1000);
}

void BSP_UART_Print(char *fmt, ...)
{
    char buf[128];

    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);

    HAL_UART_Transmit(&huart1, (uint8_t *)buf, strlen(buf), 1000);
}

void BSP_UART_DMA_Init(void)
{
    HAL_UART_Receive_DMA(&huart1, uart_rx_buf, UART_RX_SIZE);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        rx_len = UART_RX_SIZE;

        HAL_UART_Receive_DMA(&huart1, uart_rx_buf, UART_RX_SIZE);
    }
}




void BSP_uart_text(void)
{
  BSP_UART_Send((uint8_t*)"send\r\n", 6);
	BSP_UART_Print("hello\r\n");
	BSP_UART_Print("ÄãºÃ\r\n");
}

