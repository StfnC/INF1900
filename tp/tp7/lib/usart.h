#include <avr/io.h>

class usart {
    public:
        static void transmit(uint8_t data);

        static uint8_t receive(void);

        static void transmitTextMessage(uint8_t message[], uint8_t messageLength);
        static void initialization(void);
};
