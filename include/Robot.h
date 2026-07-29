#ifndef ROBOT_H
#define ROBOT_H

#include "config.h"
#include "UltrasonicSensor.h"
#include "Driver.h"
#include "Motor.h"

class Robot {
    private:
        UltrasonicSensor _leftUltrasonic;
        UltrasonicSensor _frontLeftUltrasonic;
        UltrasonicSensor _frontRightUltrasonic;
        UltrasonicSensor _rightUltrasonic;
        Driver _driver;

    public:
        //---------- CONSTRUCTOR ----------//
        Robot(uint8_t leftTrigger, uint8_t leftEcho,
            uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
            uint8_t frontRightTrigger, uint8_t frontRightEcho,
            uint8_t rightTrigger, uint8_t rightEcho,
            uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4), ;

        //---------- METHODS ----------//
        void begin();
        void updateUltrasonic();
        //void updateInfrared();
};

#endif