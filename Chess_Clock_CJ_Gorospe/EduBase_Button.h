#include "TM4C123GH6PM.h"
#include <stdint.h>

/**
 * @brief Initializes the EduBase Board buttons (SW2 - SW5).
 *
 * This function enables the digital functionality and configures PD0–PD3
 * as input pins with internal pull-up resistors enabled.
 * These buttons are active-low.
 *
 * Pins:
 *  - SW2 : PD3
 *  - SW3 : PD2
 *  - SW4 : PD1
 *  - SW5 : PD0
 *
 * @param None
 * @return None
 */
void EduBase_Button_Init(void);

/**
 * @brief Reads the current status of the EduBase Board buttons (SW2 - SW5).
 *
 * This function reads PD0–PD3 and returns their active-low state.
 * If a button is pressed, its corresponding bit will be 0.
 *
 * Bit Mapping:
 *  - Bit 3: SW2
 *  - Bit 2: SW3
 *  - Bit 1: SW4
 *  - Bit 0: SW5
 *
 * @param None
 * @return uint8_t Bitmask of pressed buttons (active-low)
 */
uint8_t Get_EduBase_Button_Status(void);

