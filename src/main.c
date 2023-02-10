#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL


//QUESTION 3 OF PART A
void Initialize()
{
    cli();
    //************ PIN ALLOCATION ***************
    /*DDRB |= (1<<DDB4);
    DDRB |= (1<<DDB3);
    DDRB |= (1<<DDB2);
    DDRB |= (1<<DDB1);
     */

    DDRD &= ~(1<<DDD7);
    PORTD |= (1<<PORTD7);

    DDRB = 0x1E;
    PORTB = 0x2;

} //INITIALIZE

int main(void)
{
    Initialize();
    while(1){
        if(!(PIND & (1<<PIND7))){
            PORTB*=2;
            if(PORTB>0x20) PORTB = 0x2;
        }
        _delay_ms(2000);
    }// WHILE
} // MAIN