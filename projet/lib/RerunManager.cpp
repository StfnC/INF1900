#include "RerunManager.h"

uint16_t RerunManager::address_ = 0;
Memoire24CXXX RerunManager::memory_ = Memoire24CXXX();
RerunManagerState RerunManager::state_ = RerunManagerState::INERT;

void RerunManager::manageRerun() {
    switch (state_) {
        case RerunManagerState::INERT:
            break;
        case RerunManagerState::MEMORIZING:
            break;
        case RerunManagerState::RERUN:
            break;
    }
}

void RerunManager::setRerunManagerState(RerunManagerState state) {
    state_ = state;
}

void RerunManager::initializationRead() {
    RerunManager::initialization();
    address_ = 0;
}

void RerunManager::initialization() {
    cli();
    TCNT2 = 0;
    TCCR2A = _BV(COM2A1) | _BV(COM2A0);
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
    TIMSK2 |= (1 << OCIE2A);
    sei();
}

void RerunManager::setIntervalle(uint16_t duration) {
    OCR2A = duration;
}

void RerunManager::writeMemory() {
    uint8_t storingLeft = (MotorsController::getLeftDirection() << 7) | MotorsController::getLeftPercentage();
    memory_.ecriture(address_++, storingLeft);
    uint8_t storingRight = (MotorsController::getRightDirection() << 7) | MotorsController::getRightPercentage();
    memory_.ecriture(address_++, storingRight);
}

void RerunManager::readMemory() {
    uint8_t lecture;
    memory_.lecture(address_++, &lecture);
    MotorsController::changeLeftDirection(static_cast<Direction>(lecture >> 7));
    MotorsController::setLeftPercentage(lecture & 0x7F);

    memory_.lecture(address_++, &lecture);
    MotorsController::changeRightDirection(static_cast<Direction>(lecture >> 7));
    MotorsController::setRightPercentage(lecture & 0x7F);

}