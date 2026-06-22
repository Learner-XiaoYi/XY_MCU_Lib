#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "main.h"

typedef struct
{
    GPIO_TypeDef *Port;
    uint16_t Pin;
} BSP_GPIO_t;

typedef enum
{
    GPIO_LOW,
    GPIO_HIGH
} GPIO_Level_t;

void BSP_GPIO_Write(BSP_GPIO_t *gpio, GPIO_Level_t level);
void BSP_GPIO_Toggle(BSP_GPIO_t *gpio);
GPIO_Level_t BSP_GPIO_Read(BSP_GPIO_t *gpio);

#endif

