#include "DistanceSensor.h"

#include <math.h>


can DistanceSensor::can_;

void DistanceSensor::initialization() {
    DDRA &= ~(1 << PIN_);
    calibrate();
}

uint8_t DistanceSensor::getDistanceCm() {
    uint8_t analogReading = getAnalogReading();
    // Equation obtained by performing a power regression
    return static_cast<uint8_t>(pow(M_E, INTERCEPT - A_COEFFICENT * log(analogReading)));
}

void DistanceSensor::calibrate() {
}

uint8_t DistanceSensor::getAnalogReading() {
    return can_.lecture8Bits(PIN_);
}
