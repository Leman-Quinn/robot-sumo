#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class Driver {
    public:
        //---------- CONSTRUCTOR ----------//
        Driver(uint8_t rpwm_a, uint8_t lpwm_a,
               uint8_t rpwm_b, uint8_t lpwm_b);

        //---------- METHODS ----------//
        void begin();
        void forward(int pwm_perc);
        void forwardRight(int pwm_perc);
        void forwardLeft(int pwm_perc);
        void backward(int pwm_perc);
        void backwardRight(int pwm_perc);
        void backwardLeft(int pwm_perc);
        void rotateRight();
        void rotateLeft();
        void brake();

    private:
        //---------- ATTRIBUTES ----------//
        Motor _leftMotor;
        uint8_t _rpwm_a;
        uint8_t _lpwm_a;
        Motor _rightMotor;
        uint8_t _rpwm_b;
        uint8_t _lpwm_b;
};

#endif