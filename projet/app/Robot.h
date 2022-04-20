#pragma once

#include <avr/io.h>
#include <led.h>
#include <debug.h>
#include <util/delay.h>

#include <MotorsController.h>
#include <DistanceSensor.h>
#include <WallFollower.h>
#include <LightController.h>
#include <ButtonPressDetector.h>
#include <RerunManager.h>
#include <SystemTimer.h>
#include <RerunManager.h>
#include <BuzzerController.h>
#include <ConcurrentMusicPlayer.h>

#include "State.h"

class Robot {
    public:
        static void init();

        static void run();

    private:
        static State currentState_;
        static led led_;

        static constexpr uint8_t BLINKING_DELAY_FOR_FIVE_HERZTZ = 100;
        static constexpr uint8_t NB_ITER_FOR_THREE_SECONDS_AT_FIVE_HZ = 15;
        static constexpr uint8_t LOW_WALL_DETECTION_LIMIT = 15;
        static constexpr uint8_t HIGH_WALL_DETECTION_LIMIT = 30;
        static constexpr uint16_t ONE_SECOND_DELAY = 1000;

        static constexpr uint8_t UTURN_LEFT_SPEED = 80;
        static constexpr uint16_t FORWARD_DELAY_UTURN = 400;
        static constexpr uint8_t UTURN_RIGHT_SPEED = 55;
        static constexpr uint16_t UTURN_TURNING_DELAY = 3000;

        static void manageStateMachine();
        static void manageStateInit();
        static void manageStateStartRerun();
        static void manageStateRerun();
        static void manageStateEndRerun();
        static void manageStateStartAutonomous();
        static void manageStateStartMemorizing();
        static void manageStateFollowWall();
        static void manageStateFollowLight();
        static void manageStateStopMemorizing();
        static void manageStateStartUTurn();
        static void manageStateUTurn();
        static void manageStateEndAutonomous();
};
