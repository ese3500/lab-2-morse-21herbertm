#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL

void Initialize()
{
    cli();
    //************ PIN ALLOCATION ***************
    //TOGGLES AN LED CODE
    DDRB |= (1<<DDB5); //SET PB5 TO BE OUTPUT PIN
    //PB5 IS THE  SAME
    // HIGH, LED ON
    //LOW, LED OFF
    DDRD &= ~(1<<DDB7); //SET PB7 TO BE INPUT PIN
    //INSTEAD OF PD5 WE USE PB7
    //NEEDS TO BE PULLED HIGH
    //WHEN SWITCH IS PRESSED, VOLTAGE AT PD5 WILL BE 0V
    PORTD |= (1<<PORTD5); // ENABLE PULL UP RESISTOR ON PD5
    //PD5 IS THE SAME
    //********** PIN CHANGE INTERRUPT SETUP *************
    PCICR |= (1<<PCIE2); // ENABLE PCINT21 PIN CHANGE INTERRUPT
    PCMSK2 |= (1<<PCINT21); //ENABLE TRIGGER FOR PCINT21
    sei();
} //INITIALIZE
ISR(PCINT2_vect)
    {
    PORTB ^=(1<<PORTB5); // TOGGLE PB5
    } //ISR
int main(void)
{
    Initialize();
    while(1);
} // MAIN