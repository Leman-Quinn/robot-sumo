#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class Driver {
    public:
        //---------- CONSTRUCTOR ----------//
        Driver(uint8_t pol1, uint8_t pol2, uint8_t pwma,
               uint8_t pol3, uint8_t pol4, uint8_t pwmb);

        //---------- METHODS ----------//
        void begin();
        void forward();
        void forward(int pwm_perc);
        //void forwardRight(int pwm_perc);
        //void forwardLeft(int pwm_perc);
        void backward();
        void backward(int pwm_perc);
        void rotateRight();
        void rotateLeft();
        void brake();

    private:
        //---------- ATTRIBUTES ----------//
        Motor _leftMotor;
        uint8_t _pwma;
        Motor _rightMotor;
        uint8_t _pwmb;
};

#endif