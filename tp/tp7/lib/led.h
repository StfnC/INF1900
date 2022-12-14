/**
 * Definition of the led class
 * 
 * \file led.h
 * \author Lina Belloui and Stefan Cotargasanu
 * \date March 13 2022
 *
 */

#include <avr/io.h>

class led {
	public:
    	led(volatile uint8_t* port, uint8_t pin1, uint8_t pin2);
    	~led() = default;

    	void setGreen();
    	void setRed();
    	void setOff();
    	void setAmber();

	private:
    	static const uint8_t GREEN_AMBER_DELAY = 8;
    	static const uint8_t RED_AMBER_DELAY = 5;
    	volatile uint8_t* port_;
    	uint8_t pin1_;
    	uint8_t pin2_;
};
