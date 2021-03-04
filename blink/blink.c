#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB  =  1 << PB5; 
    for(;;)
    {
        PINB = 1 << PB5;
        _delay_ms(100);
    }
    return 0;
}
