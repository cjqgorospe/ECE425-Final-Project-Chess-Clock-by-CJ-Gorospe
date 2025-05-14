#include "GPIO.h"

// Constant definitions for the user LED (RGB) colors
const uint8_t RGB_LED_OFF   = 0x00;
const uint8_t RGB_LED_RED   = 0x02;
const uint8_t RGB_LED_BLUE  = 0x04;
const uint8_t RGB_LED_GREEN = 0x08;

// Constant definitions for the EduBase board LEDs
const uint8_t EDUBASE_LED_ALL_OFF = 0x00;
const uint8_t EDUBASE_LED_ALL_ON  = 0x0F;

void RGB_LED_Init(void)
{
    // Enable the clock to Port F
    SYSCTL->RCGCGPIO |= 0x20;

    // Set PF1, PF2, and PF3 as output GPIO pins
    GPIOF->DIR |= 0x0E;

    // Configure PF1, PF2, and PF3 to function as GPIO pins
    GPIOF->AFSEL &= ~0x0E;

    // Enable digital functionality for PF1, PF2, and PF3
    GPIOF->DEN |= 0x0E;

    // Initialize the output of the RGB LED to zero
    GPIOF->DATA &= ~0x0E;
}

void RGB_LED_Output(uint8_t led_value)
{
    // Set the output of the RGB LED
    GPIOF->DATA = (GPIOF->DATA & 0xF1) | led_value;
}

uint8_t RGB_LED_Status(void)
{
    return GPIOF->DATA & 0x0E;
}

void EduBase_Button_Init(void)
{
    // Enable the clock to Port D
    SYSCTL->RCGCGPIO |= 0x08;

    // Set PD0–PD3 as input
    GPIOD->DIR &= ~0x0F;

    // Disable alternate functions (ensure GPIO)
    GPIOD->AFSEL &= ~0x0F;

    // Enable digital functionality
    GPIOD->DEN |= 0x0F;
}

uint8_t Get_EduBase_Button_Status(void)
{
    // Return current status of SW2–SW5 (PD0–PD3)
    return GPIOD->DATA & 0x0F;
}


