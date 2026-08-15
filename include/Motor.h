#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
    public:
        //---------- CONSTRUCTOR ----------//
        Motor(uint8_t pol1, uint8_t pol2);

        //---------- METHODS ----------//
        // initializes pin modes
        void begin();
        void forward();
        void backward();
        void brake();
    
    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _pol1;
        uint8_t _pol2;
};

#endif