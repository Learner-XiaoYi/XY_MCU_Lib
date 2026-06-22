#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "main.h"
#include "usart.h"

#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define UART_RX_SIZE 128

void BSP_UART_Init(void);
void BSP_UART_Send(uint8_t *data, uint16_t len);
void BSP_UART_Print(char *fmt, ...);

uint16_t BSP_UART_GetRxLen(void);
uint8_t* BSP_UART_GetRxBuf(void);
void BSP_UART_ClearRx(void);

void BSP_UART_DMA_Init(void);

void BSP_uart_text(void);

#endif
