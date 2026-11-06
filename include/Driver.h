#ifndef DRIVER_H
#define DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class Driver {
    public:
        //---------- CONSTRUCTOR ----------//
        Driver(uint8_t rpwm_a, uint8_t lpwm_a,
               uint8_t rpwm_b, uint8_t lpwm_b,
               bool inverted_a = true, bool inverted_b = false);

        //---------- METHODS ----------//
        void begin();
        void forward(int pwm);
        void forwardRight(int pwm);
        void forwardLeft(int pwm);
        void backward(int pwm);
        void backwardRight(int pwm);
        void backwardLeft(int pwm);
        void rotateRight(int pwm);
        void rotateLeft(int pwm);
        void brake();

    private:
        //---------- ATTRIBUTES ----------//
        Motor _leftMotor;
        Motor _rightMotor;
};

#endif