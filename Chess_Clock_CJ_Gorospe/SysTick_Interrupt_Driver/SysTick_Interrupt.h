/**
 * @file SysTick_Interrupt.h
 *
 * @brief Header file for the SysTick_Interrupt driver.
 *
 *
 *
 * @author CJ Gorospe
 */

#include "TM4C123GH6PM.h"

/**
 * @brief The SysTick_Interrupt_Init functin initializes the SysTick timer with interrupts enabled.
 *
 * This function configures the SysTick timer and its interrupt with a specified reload value to 
 * generate interrupts every 1 ms. It uses PIOSC as the clock source. The PIOSC provides 16 MHz which is
 * then divided by 4. The timer is used to generate periodic interrupts every millisecond. 
 * @param led_value
 *
 * @return None
 *
 */
void SysTick_Interrupt_Init(void);