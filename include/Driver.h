#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class Driver {
    public:
        //---------- CONSTRUCTOR ----------//
        Driver(uint8_t pol1, uint8_t pol2, uint8_t pol3, uint8_t pol4);

        //---------- METHODS ----------//
        void begin();
        void forward();
        void backward();
        void rotateRight();
        void rotateLeft();
        void brake();

    private:
        //---------- ATTRIBUTES ----------//
        Motor _leftMotor;
        Motor _rightMotor;
};

#endif