
#include "tm4c123gh6pm_registers.h"

/* Enable PF0 (SW2) */
void SW2_Init(void)
{
    GPIO_PORTF_LOCK_REG   = 0x4C4F434B;   /* Unlock the GPIO_PORTF_CR_REG */
    GPIO_PORTF_CR_REG    |= (1<<0);       /* Enable changes on PF0 */
    GPIO_PORTF_AMSEL_REG &= ~(1<<0);      /* Disable Analog on PF0 */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;   /* Clear PMCx bits for PF0 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   &= ~(1<<0);      /* Configure PF0 as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<0);      /* Disable alternative function on PF0 */
    GPIO_PORTF_PUR_REG   |= (1<<0);       /* Enable pull-up on PF0 */
    GPIO_PORTF_DEN_REG   |= (1<<0);       /* Enable Digital I/O on PF0 */
}

/* Enable PF1 (RED LED) */
void Led_Red_Init(void)
{
    GPIO_PORTF_AMSEL_REG &= ~(1<<1);      /* Disable Analog on PF1 */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFF0F;   /* Clear PMCx bits for PF1 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<1);       /* Configure PF1 as output pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<1);      /* Disable alternative function on PF1 */
    GPIO_PORTF_DEN_REG   |= (1<<1);       /* Enable Digital I/O on PF1 */
    GPIO_PORTF_DATA_REG  &= ~(1<<1);      /* Clear bit 1 in Data register to turn off the led */
}

int main(void)
{
    /* Enable clock for PORTF and wait for clock to start */
    SYSCTL_RCGCGPIO_REG |= 0x20;
    while(!(SYSCTL_PRGPIO_REG & 0x20));

    /* Initialize the SW2 and Red LED as GPIO Pins */
    SW2_Init();
    Led_Red_Init();

    while(1)
    {
        /* Check the switch state */
        if(!(GPIO_PORTF_DATA_REG & (1<<0)))
        {
            GPIO_PORTF_DATA_REG |= (1<<1);  /* LED ON */
        }
        else
        {
            GPIO_PORTF_DATA_REG &= ~(1<<1); /* LED OFF */
        }
    }
}
