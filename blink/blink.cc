#include <stdint.h>
#include <util/delay.h>

namespace {

    class PORT {
        public:
        PORT() = delete;
        PORT( PORT && ) = delete;
        PORT( PORT const & ) = delete;
        ~PORT() = delete;
        auto operator=( PORT && ) = delete;
        auto operator=( PORT const & ) = delete;

       uint8_t volatile pin;
       uint8_t volatile ddr;
       uint8_t volatile port;

    };
    auto & portb() noexcept
    {
      return *reinterpret_cast<PORT *>( 0x23 );
    }

}

int main()
{
    constexpr auto mask = uint8_t{ 1 << 5};
    auto & port = portb();

    port.ddr = mask;

    for(;;)
    {
        port.pin = mask;
        _delay_ms(100);
    }
}
