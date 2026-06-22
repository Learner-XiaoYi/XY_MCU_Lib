#include "bsp_gpio.h"



void BSP_GPIO_Write(BSP_GPIO_t *gpio, GPIO_Level_t level)
{
    HAL_GPIO_WritePin(gpio->Port,gpio->Pin,level ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void BSP_GPIO_Toggle(BSP_GPIO_t *gpio)
{
    HAL_GPIO_TogglePin(gpio->Port,gpio->Pin);
}



GPIO_Level_t BSP_GPIO_Read(BSP_GPIO_t *gpio)
{
    if (HAL_GPIO_ReadPin(gpio->Port, gpio->Pin) == GPIO_PIN_SET)
    {
        return GPIO_HIGH;
    }
    else
    {
        return GPIO_LOW;
    }
}

