#ifndef ROBOT_H
#define ROBOT_H

#include <array>
#include "Arduino.h"
#include "config.h"
#include "UltrasonicSensor.h"
#include "Driver.h"

class Robot {
    private:
        UltrasonicSensor _leftUltrasonic;
        UltrasonicSensor _frontLeftUltrasonic;
        UltrasonicSensor _frontRightUltrasonic;
        UltrasonicSensor _rightUltrasonic;
        
        enum UltrasonicPositions {
            LEFT,
            FRONT_LEFT,
            FRONT_RIGHT,
            RIGHT,
            COUNT
        };
        std::array<float, COUNT> _ultrasonicDistances;
        
        Driver _driver;

    public:
        //---------- CONSTRUCTOR ----------//
        Robot(uint8_t leftTrigger, uint8_t leftEcho,
            uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
            uint8_t frontRightTrigger, uint8_t frontRightEcho,
            uint8_t rightTrigger, uint8_t rightEcho,
            uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4);

        //---------- METHODS ----------//
        void begin();
        void updateUltrasonicSensors();
        float getUltrasonic(UltrasonicPositions position);
        //void readInfrared();
};

#endif