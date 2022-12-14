/**
 * Definition of the Interpreter class
 *
 * \file Interpreter.h
 * \author Stefan Cotargasanu Rakotoarivony Faneva Lina Belloui Justine Sauquet
 * \date March 22 2022
 */

#pragma once
#define F_CPU 8000000

#include <avr/io.h>
#include <counter.h>
#include <led.h>
#include <MotorsController.h>
#include <util/delay.h>
#include <usart.h>
#include <stdio.h>
#include <memoire_24.h>
#include <debug.h>
#include "operations.h"
#include <BuzzerController.h>

class Interpreter
{
public:
    Interpreter();
    void interpretCode();

private:
    uint8_t read8Bits();
    void readNumberInstructions();
    void interpretLine();
    void interpreter(uint8_t instruction, uint8_t operand);

    void dbt();
    void att(uint8_t operand);
    void dal(uint8_t operand);
    void det(uint8_t operand);
    void sgo(uint8_t operand);
    void sar();
    void mar();
    void mav(uint8_t operand);
    void mre(uint8_t operand);
    void trd();
    void trg();
    void dbc(uint8_t operand);
    void fbc();
    void fin();

    static const uint16_t ROTATION_TIME = 515;
    static const uint8_t BIT_SHIFT_FOR_UINT8_CONVERSION = 8;
    static const uint8_t N_BYTES_FOR_PROGRAM_SIZE = 2;
    static const uint8_t TWENTY_FIVE_SECOND_DELAY = 25;
    static const uint8_t TWENTY_SECOND_DELAY = 20;
    static const uint8_t HUNDRED_PERCENT = 100;

    bool execute_ = false;

    Memoire24CXXX memoire_;

    uint16_t loopInstructionNumber_ = 0;
    uint16_t numberInstructions_ = 0;
    uint16_t currentAdress_ = 0;
    uint16_t loopAddress_ = 0;
    uint8_t counter_ = 0;
};
