#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
//#include <cstddef>

namespace {

    class USART {
         public:
         USART() = delete;
         USART( USART && ) = delete;
         USART( USART const & ) = delete;
        ~USART() = delete;
         auto operator=( USART && ) = delete;
         auto operator=( USART const & ) = delete;
          
        // ATmega48A datasheet pg185 ex:Ccode, pg621 register location
        uint8_t volatile ucsrA;
        uint8_t volatile ucsrB;
        uint8_t volatile ucsrC;       
//        std::string message = "Hello World";

        void USART_Init(void){
        //Bit rate, refer to datasheet page 199
        UBRR0 = 8;
        // Set frame 1 stop bit, 8 bit
        ucsrC = (0<<USBS0)|(3<<UCSZ00);
        //Enable Transmit
        ucsrB = (1<<TXEN0);
        }

        bool USART_Transmit_buffer_empty(){    
            return (~(UCSR0A) & (1<<UDRE0));  
        }
        
        void USART_Transmit(uint8_t data){
        while (USART_Transmit_buffer_empty() == true){
         }
         UDR0 = data;
        }
    };
    
    auto & portUSART() noexcept {
        
        return *reinterpret_cast <USART*>( 0xC0 );
    }
    

}


int main(void){
    
    auto & USART = portUSART();
    char c;
    char const * message = "Hello, World";
//    size_t message_size = strlen(message);
    
    USART.USART_Init();
   
/*    do { 
        ((c=*message++));
        USART.USART_Transmit(c);
      } while(message_size != 0);
*/
    while (( c = *message++)){
        USART.USART_Transmit(c);
    }


}


