#include "tm4c123gh6pm_registers.h"

#define PF1_PF2_PF3  (*((volatile unsigned long *)(0x40025000+0x38)))

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 364

void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
}

/* Enable PF1, PF2 and PF3 (RED, Blue and Green LEDs) */
void Leds_Init(void)
{
    GPIO_PORTF_AMSEL_REG &= 0xF1;         /* Disable Analog on PF1, PF2 and PF3 */
    GPIO_PORTF_PCTL_REG  &= 0xFFFF000F;   /* Clear PMCx bits for PF1, PF2 and PF3 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= 0x0E;         /* Configure PF1, PF2 and PF3 as output pin */
    GPIO_PORTF_AFSEL_REG &= 0xF1;         /* Disable alternative function on PF1, PF2 and PF3 */
    GPIO_PORTF_DEN_REG   |= 0x0E;         /* Enable Digital I/O on PF1, PF2 and PF3 */
    GPIO_PORTF_DATA_REG  &= 0xF1;         /* Clear bit 0, 1 and 2 in Data registers to turn off the leds */
}

int main(void)
{
    /* Enable clock for PORTF and wait for clock to start */  
    SYSCTL_RCGCGPIO_REG |= 0x20;
    while(!(SYSCTL_PRGPIO_REG & 0x20));
    
    /* Initialize the LEDs as GPIO Pins */
    Leds_Init();
    
    while(1)
    {
        /* Access each pin individually using the Bit Band feature */
        /* Turn on the Red LED */
        /* Turn off the Blue LED */
        /* Turn off the Green LED */
        PF1_PF2_PF3 = 0x02;
        Delay_MS(1000);
        
        /* Access each pin individually using the Bit Band feature */
        /* Turn off the Red LED */
        /* Turn on the Blue LED */
        /* Turn off the Green LED */
        PF1_PF2_PF3 = 0x04;
        Delay_MS(1000);
        
        /* Access each pin individually using the Bit Band feature */
        /* Turn off the Red LED */
        /* Turn off the Blue LED */
        /* Turn on the Green LED */
        PF1_PF2_PF3 = 0x08;
        Delay_MS(1000); 
    }
}
