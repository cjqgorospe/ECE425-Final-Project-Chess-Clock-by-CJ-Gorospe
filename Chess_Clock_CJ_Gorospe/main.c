#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "EduBase_LCD.h"
#include "SysTick_Delay.h"

#define START_TIME 60

int main(void)
{
		// Initializations
    SysTick_Delay_Init();
	
    RGB_LED_Init();
    
		EduBase_LCD_Init();
    
		EduBase_Button_Init();
		
		// Declare game state variables
    int player1_time = START_TIME;
    
		int player2_time = START_TIME;
	
		// 0 = stopped, 1 = active
    uint8_t timerRunning = 0; 
		
		//0 = running, 1 = paused
    uint8_t timerPaused = 0;
		
		// 1 = Player 1, 2 = Player 2
    uint8_t playerTurn = 1;  

    // Initial LCD setup
    EduBase_LCD_Clear_Display();
    
		EduBase_LCD_Set_Cursor(0, 0);
    
		EduBase_LCD_Display_String("P1: 60  P2: 60");
		
		EduBase_LCD_Set_Cursor(0,1);
		
		EduBase_LCD_Display_String("SW4 To Start");

    while (1)
    {
        uint8_t status = Get_EduBase_Button_Status();

        if (status != 0)
        {
            // SW4: Start game with Player 1
            if (status & 0x02)
            {
                player1_time = START_TIME;
                
								player2_time = START_TIME;
                
								playerTurn = 1;
                
								timerRunning = 1;
                
								timerPaused = 0;
            }

            // SW3: Toggle turn (P1 <-> P2)
            else if (status & 0x04)
            {
                if (timerRunning && !timerPaused)
                {
                    if (playerTurn == 1)
										{
											playerTurn = 2;
										}
										else 
										{
											playerTurn = 1;
										}
                }
            }

            // SW5: Reset and stop game
            else if (status & 0x01)
            {
                player1_time = START_TIME;
                
								player2_time = START_TIME;
                
								timerRunning = 0;
                
								timerPaused = 0;

                EduBase_LCD_Set_Cursor(0, 1);
                
								EduBase_LCD_Display_String("Game Reset       ");
            }

            // SW2: Pause/Resume toggle
            else if (status & 0x08)
            {
                if (timerRunning)
                {
                    timerPaused = !timerPaused;
                    
										EduBase_LCD_Set_Cursor(0, 1);
                    
										if (timerPaused)
										{
                        EduBase_LCD_Display_String("Game Paused      ");
                    }
										else
										{  
												EduBase_LCD_Display_String("Game Resumed     ");
										}
								}
            }
            SysTick_Delay1ms(200); // Debounce
        }

        // Countdown logic
        if (timerRunning && !timerPaused)
        {
						if(playerTurn == 1)
						{
							RGB_LED_Output(RGB_LED_BLUE);
						}
						else 
						{
							RGB_LED_Output(RGB_LED_GREEN);
						}
						
						// Sync the flashing LEDs on LaunchPad with Clock Timer
						SysTick_Delay1ms(1000);
						
						RGB_LED_Output(RGB_LED_OFF);
						
						SysTick_Delay1ms(1000);
						
            if (playerTurn == 1 && player1_time > 0)
						{
                player1_time--;
            }
						else if (playerTurn == 2 && player2_time > 0)
						{  
							player2_time--;
						}
						
            // Display both timers
            char display[20];
            
						// I did some research on what i could use to display the timers because the EduBase_LCD was not updating the timer properly
						// https://www.tutorialspoint.com/c_standard_library/c_function_sprintf.htm#:~:text=C%20Library%20%2D%20sprintf()...
						//%20function&text=The%20C%20Library%20sprintf()%20function%20allows%20you,formats%2C%20similar%20to%20printf()%2C%20but%20instead%20of
						// ^reference
						sprintf(display, "P1: %02d  P2: %02d", player1_time, player2_time);
            
						EduBase_LCD_Set_Cursor(0, 0);
            
						EduBase_LCD_Display_String(display);

            // Check for timeout
            if (player1_time == 0 || player2_time == 0)
            {
                timerRunning = 0;
								
								timerPaused = 0;
							
								RGB_LED_Output(RGB_LED_RED);
							
                EduBase_LCD_Set_Cursor(0, 1);
                if (player1_time == 0)
								{
                    EduBase_LCD_Display_String("Player 1 Lost    ");
                }
								else
								{   
										EduBase_LCD_Display_String("Player 2 Lost    ");
								}
            }
            else
            {
                // Show current player’s turn
                EduBase_LCD_Set_Cursor(0, 1);
                if (playerTurn == 1)
								{
										EduBase_LCD_Display_String("P1 Turn           ");
								}
								else
								{
										EduBase_LCD_Display_String("P2 Turn           ");
								}
            }

            SysTick_Delay1ms(50);
        }

        SysTick_Delay1ms(50);
    }
}