#ifndef ROBOT_H
#define ROBOT_H

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
        Robot();

        //---------- METHODS ----------//
        void begin();
        void updateUltrasonic();
        //void updateInfrared();
};

#endif