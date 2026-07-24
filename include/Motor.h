#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
    private:
        uint8_t _pol1;
        uint8_t _pol2;

    public:
        //---------- CONSTRUCTOR ----------//
        Motor(uint8_t pol1, uint8_t pol2);

        //---------- PIN SETUP ----------//
        // initializes pin modes
        void init();

        //---------- GENERAL METHODS ----------//
        void Forward();
        void Backward();
        void Stop();
};

#endif