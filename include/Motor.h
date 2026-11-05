#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
    public:
        //---------- CONSTRUCTOR ----------//
        Motor(uint8_t rpwm, uint8_t lpwm, bool inverted = false);

        //---------- METHODS ----------//
        void begin();
        void forward(int pwm);
        void backward(int pwm);
        void brake();
    
    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _rpwm;
        uint8_t _lpwm;
        bool _inverted;
};

#endif