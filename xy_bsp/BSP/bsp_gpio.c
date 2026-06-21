#include "bsp_gpio.h"

void BSP_GPIO_Set(BSP_GPIO_t *gpio)
{
    HAL_GPIO_WritePin(
        gpio->Port,
        gpio->Pin,
        GPIO_PIN_SET
    );
}

void BSP_GPIO_Reset(BSP_GPIO_t *gpio)
{
    HAL_GPIO_WritePin(
        gpio->Port,
        gpio->Pin,
        GPIO_PIN_RESET
    );
}

void BSP_GPIO_Toggle(BSP_GPIO_t *gpio)
{
    HAL_GPIO_TogglePin(
        gpio->Port,
        gpio->Pin
    );
}

GPIO_PinState BSP_GPIO_Read(BSP_GPIO_t *gpio)
{
    return HAL_GPIO_ReadPin(
        gpio->Port,
        gpio->Pin
    );
}

