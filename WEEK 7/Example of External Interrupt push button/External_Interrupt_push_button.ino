#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define ONE 1

int flag_SW2 = 0;   // Flag is switch from normal state to blinking state
int flag_SW3 = 0;
int flag_SW4 = 0;   
unsigned int count = 0;

void timer_zero_enable();
void Intr_Enable();
void run();

int main (void)
{
   DDRB |=  (ONE << PB1);     // Output
   DDRD &= ~(ONE << PD2);    // Input
   DDRD &= ~(ONE << PD3);    // Input
   DDRD &= ~(ONE << PD4);    // Input

  
   // sei();  // global interrupt state
   SREG |= (ONE << 7);
  
   Intr_Enable();
   timer_zero_enable();
    
   PORTB |= ~(ONE << PB1);    // Initial value of port
   PORTD &= ~(ONE << PD2);    // Initial value of port
   PORTD &= ~(ONE << PD3);    // Initial value of port
   PORTD &= ~(ONE << PD4);    // Initial value of port

  
  
  while(1)
  {
    if(flag_SW2)
    {
        if(count>=15)            // certain delay completed
        {
           PORTB^=(ONE << PB1);   // Toggle led
           count = 0;            // reset counter
        }
    }
    else if (flag_SW3)
    {
         if(count>=45)            // certain delay completed
         {
           PORTB^=(ONE << PB1);   // Toggle led
           count = 0;            // reset counter
         }
    }  
    else if (flag_SW4)
    {
          run();    // Make High
    }  
     
    else    // default state, led is ON
    {
          PORTB |= ~(1 << PB1);   // Make LOW
    }
  }
  return 0;
}


void setClkSource()
{  
   TCCR0B |=  (ONE << CS00);
   TCCR0B |=  (ONE << CS02);
   TCCR0B &= ~(ONE << CS01);
}

void timer_zero_enable()
{
   TCNT0 = 0;
   TIMSK0 |= (1 << TOIE0); // to enable timer 0 
  
   TCCR0A &= ~(ONE << WGM00);
   TCCR0A &= ~(ONE << WGM01);
   TCCR0B &= ~(ONE << WGM02);
}


void Intr_Enable()
{
  EICRA |= (ONE << ISC00);
  EIMSK |= (ONE << INT0);
  
  EICRA |= (ONE << ISC10);
  EIMSK |= (ONE << INT1);
  
   PCICR |= (ONE << PCIE2);
  PCMSK2 |= (ONE << PCINT20);
}


ISR(INT0_vect)  // Interrupt comes automatically, name the interrupt . INT0_vect = vector name 
{
    flag_SW2 = !flag_SW2;
    setClkSource();  
}

ISR(INT1_vect)  // Interrupt comes automatically, name the interrupt . INT0_vect = vector name 
{
    flag_SW3 = !flag_SW3;
    setClkSource();  
}

ISR(PCINT2_vect)  // Interrupt comes automatically, name the interrupt . PCINT2_vect = vector name 
{
    flag_SW4 = !flag_SW4;
}

ISR(TIMER0_OVF_vect)  // Interrupt comes automatically, name the interrupt . PCINT2_vect = vector name 
{
    count++;
}

void run()
{
    PORTB ^= (1 << PB1);    // Make High
}

  
  
  
  