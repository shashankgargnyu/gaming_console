// INCLUDES
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include <stdio.h>
#include <math.h>
#include "accelerometers/accelerometers.h"
#include "RNG/random_number_generator.h"
#include "LCD/lcd.h"

// ***** Initializing global variables for gaming console
// Variables for Player 1
uint present_xpos=0;
uint present_ypos=40;
uint max_ypos=285;
uint min_ypos=5;
uint hit=0;
uint hit1=0;
uint missile_ypos=0;
uint missile_xpos=0;

// Variables for the opponent
uint present_xpos1=209;
uint present_ypos1=40;
uint max_ypos1=285;
uint min_ypos1=5;
uint missile_ypos1=0;
uint missile_xpos1=239;

// Variables for implementing Button debouncing
static int ButtenIsPressed;
static int ButtenIsReleased;
static int ButtenPressed=1;
static int ButtenReleased=1;
static uint32_t counter1;
static uint32_t counter2;
static uint32_t x;

uint32_t d=0;
uint32_t m=0;
  
static void init_systick();
void delay_ms(uint32_t n);
static volatile uint32_t msTicks; // counts 1 ms timeTicks

// Initialize PA0 as GPIO input for button
void init_button()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;  // enable clock to GPIOA
    
    GPIOA->MODER &= ~(0x3 << (2*0)); // clear the 2 bits corresponding to pin 0
    // if the 2 bits corresponding to pin 0 are 00, then it is in input mode
}

/* This function reads the Port A IDR register to determine if the button is pressed.
 Button on STM32Discovery is connected to pin PA0
 */
uint32_t read_button(void)
{
    uint32_t a= GPIOA->IDR;     // read the IDR register
    a &=(0x01);                 // Extract the first bit of IDR Register
    if (a==1)
        return 1;
    else
        return 0;
}

// SysTick Handler (Interrupt Service Routine for the System Tick interrupt)
void SysTick_Handler(void)
{
    // Implement button debouncing
    msTicks++;
    x=read_button(); // check if buttton is pressed
    if(x==1)
    {   counter1++;
        counter2=0;
    }
    if(x==0)
    {   counter2++;
        counter1=0;
    }
    if((x==1) && (counter1>=10) && (ButtenReleased==1))
    {
        ButtenIsPressed=1;
        ButtenReleased=0;
        counter1=0;
    }
    if((x==0) && (counter2>=10) && (ButtenPressed==1))
    {
        ButtenIsReleased=1;
        ButtenPressed=0;
        counter2=0;
    }
}

// initialize the system tick
void init_systick(void)
{
	SystemCoreClockUpdate();                      /* Get Core Clock Frequency   */
	if (SysTick_Config(SystemCoreClock / 10000)) 
	{ /* SysTick 1 msec interrupts  */
    while (1);                                  /* Capture error              */
	}
}

// pause for a specified number (n) of milliseconds
void delay_ms(uint32_t n)
{
  uint32_t msTicks2 = msTicks + n*10;
  while(msTicks < msTicks2) ;
}

// Initialize Port C for GPIO input from the second player
void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;    // Enable the clock
    for (int i=0; i<3; i++)                 // Pins PC0, PC1 and PC2
    {
        GPIOC->MODER &= ~(0x3 << (2*i)); // clear the 2 bits corresponding to pin i
        GPIOC->MODER |= (0 << (2*i)); // Reset the pins to enaable input mode
    }
}	
void Move_Missile(void)
{
	missile_ypos=present_ypos+8; // middle of the tank
	missile_xpos=present_xpos+32; // top of the tank
	
    // travel till the boundary of the LCD
	for (missile_xpos;missile_xpos<=226;missile_xpos++)
	{
		LCD_Fill(missile_xpos, missile_ypos, missile_xpos+8, missile_ypos+8, BLUE);
		delay_ms(2);
        // Simultaneously erase the missile from the previous position
		LCD_Fill(missile_xpos, missile_ypos, missile_xpos+8, missile_ypos+8, BLACK);
		delay_ms(2);
	}
	// increment the number of hits if opponent's missile hits the player
	if (missile_ypos-present_ypos1<30)
		hit++;
}

/* This function implements the motion of missile on the LCD screen for the opponent*/
void Move_Missile_1(void)
{
	missile_ypos1=present_ypos1+8;
	missile_xpos1=present_xpos1-32;
	
	for (missile_xpos1;missile_xpos1>=5;missile_xpos1--)
	{
		LCD_Fill(missile_xpos1, missile_ypos1, missile_xpos1+8, missile_ypos1+8, BLUE);
		delay_ms(2);
		LCD_Fill(missile_xpos1, missile_ypos1, missile_xpos1+8, missile_ypos1+8, BLACK);
		delay_ms(2);
	}
	if (missile_ypos1-present_ypos<30)
		hit1++;
}

/* This function implements the motion of player's tank on the the LCD based on input from the accelerometer
 */
void modify_lcd( float a[3])
{
	// move left
    if(a[1]<-0.2)
		{
            // check if the player has reached the boundary
			if(present_ypos<=min_ypos)
			{
				present_ypos=min_ypos;
				LCD_Rect(0, present_ypos, 30,present_ypos+30, RED);
			}
			else
			{
				LCD_Rect(0, present_ypos, 30, present_ypos+30, BLACK);
				present_ypos=present_ypos-5;
				LCD_Rect(0, present_ypos, 30, present_ypos+30, RED);
			}
		}
    
		// move right
		if(a[1]>0.2)
		{
			if (present_ypos>=max_ypos)
			{
				present_ypos=max_ypos;
				LCD_Rect(0, present_ypos, 30, present_ypos+30, RED);
			}
			else
			{
				LCD_Rect(0, present_ypos, 30, present_ypos+30, BLACK);
				present_ypos=present_ypos+5;
				LCD_Rect(0, present_ypos, 30, present_ypos+30, RED);
			}
		}
}

/* This function implements the motion of opponents's tank on the the LCD based on GPIO input from the opponent
 */
void modify_lcd_1(uint16_t d)
{
	uint left= d & (0x01);
	uint right=d & (0x02);

	if(right==0)
		{
			if(present_ypos1<=min_ypos1)
			{
				present_ypos1=min_ypos1;
				LCD_Rect(209, present_ypos1, 239,present_ypos1+30, BLUE);
	
			}
			else
			{
				LCD_Rect(209, present_ypos1, 239, present_ypos1+30, BLACK);
				present_ypos1=present_ypos1-5;
				LCD_Rect(209, present_ypos1, 239, present_ypos1+30, BLUE);
			}
		}
		
		if(right==2)
		{
			if (present_ypos1>=max_ypos1)
			{
				present_ypos1=max_ypos1;
				LCD_Rect(209, present_ypos1, 239, present_ypos1+30, BLUE);
			}
			else
			{
				LCD_Rect(209, present_ypos1, 239, present_ypos1+30, BLACK);
				present_ypos1=present_ypos1+5;
				LCD_Rect(209, present_ypos1, 239, present_ypos1+30, BLUE);
			}
		}
}


int main(void)
{
}
