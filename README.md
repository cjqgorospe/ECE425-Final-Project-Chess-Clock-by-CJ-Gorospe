# ECE425-Final-Project-Chess-Clock-by-CJ-Gorospe
# Introduction
This  project fulfills the final project requirement for the following class at California State University, Northridge (CSUN):
- ECE 425: Microprocessor Systems

Performed by:
- CJ Gorospe

Professor:
- Aaron Nanas

# Project Goals
- Develop a fully functioning chess clock using the following concepts from ECE 425 lecture
  -  General Purpose Input/Output
  -  Timers
  -  Liquid Crystal Display

 # Video Demonstration
Files exceed the size limit for GitHub upload. Please refer to the Chess Clock Video Output folder above.

# Directory Tree
- Chess_Clock_CJ_Gorospe: Contains complete C code for the chess clock implementation.
- Chess_Clock_Diagrams: Contains the initial and final block diagrams of the chess clock.
- Chess_Clock_Hardware: Contains an image of the hardware used to make the chess clock.
- Chess_Clock_Video_Output: Video outputs of button functions and the player's one and two losing.

# Hardware
Tiva EduBase Board and Launchpad

![Screenshot 2025-05-13 235116](https://github.com/user-attachments/assets/b00ce993-6783-43a8-8f4f-de81000f3405)

# Block Diagrams
Initial Chess Clock Block Diagram

![ECE425_Project_Proposal_Block_Diagram](https://github.com/user-attachments/assets/92c2029a-0408-4529-a9f8-703504d5b057)

Final Chess Clock Block Diagram


![Screenshot 2025-05-13 230458](https://github.com/user-attachments/assets/28b12cc0-c603-4970-b516-0d21bae478b0)

# Project Description
This project implements a two-player digital chess clock using the Tiva C Series TM4C123GH6PM microcontroller and the EduBase Board. The system simulates a standard chess clock that allows players to manage and alternate turn-based countdowns during a game. It uses onboard buttons, an LCD screen, RGB LEDs, and software-based timing through the SysTick timer.

Each player starts with a predefined time (e.g., 60 seconds). When one player completes their move, they press a button to end their turn, and the clock switches to the other player. The timer pauses, resumes, resets, and handles timeouts with clear feedback via the LCD and colored LED indicators.

# Methodology
The three main drivers that is required for the chess clock to be considered are the GPIO, System Tick Delay, and LCD drivers. In the condensed version of the chess clock implementation, the GPIO driver is used to implement the LEDs on the LaunchPad and to initialize the EduBase board buttons to work for specific functions, the System Tick Delay driver provides the timer for the LCD to decrement the player timer while remaining consistent with the LEDs as each player progress through the game, and the LCD acts as the main display for the entire clock. Without the rotary encoder, the default game speed was set to 60 seconds for proper output display on the LCD, and the LCD main display was the timers of players one and two on row one and different game messages, like “Press SW4 to Start”, “P1 Lost, or “P2 Lost”, on row two. The EduBase board buttons had unique functions of the chess clock: button one (SW2) was used to pause and resume the timer, button two (SW3) was used to toggle between the player’s turn, button three (SW4) was used to start the game, and button four (SW5) was used to restart the timer and game. 

# Components Used 
![Screenshot 2025-05-13 235929](https://github.com/user-attachments/assets/a61f1f8c-b380-443b-86b3-869dee518b7b)

# Pinouts Used
![Screenshot 2025-05-14 000416](https://github.com/user-attachments/assets/3bbe87a0-1391-49d0-b5c8-43b77fc90822)

# Development Tools
- Software: Keil
- Languages: C
- Development Board Used: TM4C123GH6PM, EduBase Board

