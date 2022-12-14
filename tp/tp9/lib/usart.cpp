/**
 * Implementation of the usart methods
 * 
 * \file usart.cpp
 * \author Stefan Cotargasanu
 * \date March 13 2022
 *
 * Pins:
 *  Input:
 *      -D0
 * 
 *  Output:
 *      -D1
 * 
 */

#include "usart.h"

#include <avr/io.h>

usart::usart() {
    usart::initialization();
}

void usart::initialization(void) {
    UBRR0H = 0;

    UBRR0L = 0xCF;

    // Allow reception and transmission through UART0
    UCSR0A |= (1 << RXC0) | (1 << TXC0);

    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // 8 data bits, 1 stop bit, no parity

    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
}

void usart::transmit(uint8_t data) {
    // Copy pasted from p.174 of the ATmega documentation

    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}

uint8_t usart::receive(void) {
    // Copy pasted from p.177 of the ATmega documentation

    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
        ;
    /* Get and return received data from buffer */
    return UDR0;
}

void usart::transmitTextMessage(uint8_t message[], uint8_t messageLength){
    for (uint8_t i = 0; i < messageLength - 1; i++) {
        usart::transmit(message[i]);
    }
}

void usart::transmitTextMessage(const char message[], uint8_t messageLength){
    for (uint8_t i = 0; i < messageLength - 1; i++) {
        usart::transmit(message[i]);
    }
}

void usart::transmitTextMessage(char* message, uint8_t messageLength){
    for (uint8_t i = 0; i < messageLength - 1; i++) {
        usart::transmit(message[i]);
    }
}
