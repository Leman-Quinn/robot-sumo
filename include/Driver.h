#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class Driver {
    private:
        //---------- ATTRIBUTES ----------//
        Motor _leftMotor;
        Motor _rightMotor;

    public:
        //---------- CONSTRUCTOR ----------//
        Driver(uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4);

        //---------- GENERAL METHODS ----------//
        void Forward();
        void Backward();
        void TurnRight();
        void TurnLeft();
        void Brake();
};

#endif