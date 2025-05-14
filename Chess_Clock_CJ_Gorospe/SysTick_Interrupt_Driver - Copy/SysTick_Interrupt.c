/**
 * @file SysTick_Interrupt.c
 *
 * @brief SOurce code for the SysTick_Interrupt driver.
 *
 * @author
 */
 
 #include "SysTick_Interrupt.h"
 
 /*
  * @brief The SysTick_Interrupt_Init function initializes the SysTick timer with interrupts enabled.
	*
	* This function configures the SysTick timer and its interrupt with a specified reload value to
	* generate interrupts every 1ms. It uses the Peripheral Internal Oscillator (PIOSC) as the clock source.
	* The PIOSC provides 16 MHz which then divided by 4. The timer is used to generate periodic interrupts
	* every 1 millisecond. 
	*
	* @param None
	*
	* @return None
 */
 void SysTick_Interrupt_Init(void)
 {
	// Assign reload value of 3999 to STRELOAD register.
	 SysTick -> LOAD = (4000 - 1);
	 
	// Clear the current value of the SysTick timer by writing
	// any value to STCURRENT (VAL) register, zero can be used.
	 SysTick -> VAL = 0;
	 
	// Clear bit 2 (CLK_SRC) of STCTRL (CTRL) register to select PIOSC
	// as the clock source (clock frequency is 4 MHz)
	 SysTick -> CTRL &= ~0x2;
	 
	// Set the bit 0 (enable) and bit 1 (INTEN) of the STCTRL register
	 SysTick -> CTRL |= 0x03;
	 
	 
	 
	 
	 
 }