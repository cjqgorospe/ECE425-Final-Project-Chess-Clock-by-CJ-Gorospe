#include "EduBase_Button.h"

void EduBase_Button_Init(void)
{
    // Enable the clock to Port D (PD0 - PD3 for SW2 - SW5)
    SYSCTL->RCGCGPIO |= 0x08;

    // Configure PD0 - PD3 as input
    GPIOD->DIR &= ~0x0F;

    // Disable alternate functions for PD0 - PD3
    GPIOD->AFSEL &= ~0x0F;

    // Enable digital functionality for PD0 - PD3
    GPIOD->DEN |= 0x0F;

    // Enable pull-up resistors for PD0 - PD3 (active-low buttons)
    GPIOD->PUR |= 0x0F;
}

uint8_t Get_EduBase_Button_Status(void)
{
    // Return only the lower 4 bits (PD0 - PD3) for SW2 - SW5
    return GPIOD->DATA & 0x0F;
}
