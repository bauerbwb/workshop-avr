#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

void USART_Init(void);
void USART_Transmit(uint8_t);

int main(void){

    char c;
    USART_Init();
    
    char const * message = "Hello, World";

    while (( c = *message++)){
        USART_Transmit(c);
    }

    return 0;
}

void USART_Init(void){
    //Bit rate, refer to datasheet page 199
    UBRR0 = 8;
    // Set frame 1 stop bit, 8 bit
    UCSR0C = (0<<USBS0)|(3<<UCSZ00);
    //Enable Transmit
    UCSR0B = (1<<TXEN0);
}

void USART_Transmit(uint8_t data){
  
    while (!(UCSR0A & (1<< UDRE0))){
    }

    UDR0 = data;

}


