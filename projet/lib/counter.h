/**
 * Definition of the CounterInterrupt class and the associated enums
 * 
 * \file counter.h
 * \author Faneva Rakotoarivony
 * \date March 13 2022
 *
 */
#pragma once
#include <avr/interrupt.h>

/* Set counter on Timer 1 */
enum class CompareMode {
    Toggle,
    SetToLow,
    SetToHigh,
    Off
};

enum class GenerationMode {
    Normal,
    ClearTimerCompare
};

class CounterInterrupt {
   public:
    CounterInterrupt();
    ~CounterInterrupt() = default;

    void setDuration(uint16_t duration);
    void setCompareMode(CompareMode compareMode);
    void setGenerationMode(GenerationMode generationMode);


    const uint16_t ONE_SECOND_PRESCALER_VALUE = 7812.5;

};
