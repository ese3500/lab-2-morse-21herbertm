#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL
void Initialize()
{
    DDRB |= (1<<DDB4);
    DDRB |= (1<<DDB3);
    DDRB |= (1<<DDB2);
    DDRB |= (1<<DDB1);
}
int main(void)
{
    Initialize();

    while(1)
    {
        PORTB |= (1<<PORTB4);
        PORTB |= (1<<PORTB3);
        PORTB |= (1<<PORTB2);
        PORTB |= (1<<PORTB1);
        _delay_ms(1000);
        PORTB &= ~(1<<PORTB4);
        PORTB &= ~(1<<PORTB3);
        PORTB &= ~(1<<PORTB2);
        PORTB &= ~(1<<PORTB1);
        _delay_ms(1000);
    }
}