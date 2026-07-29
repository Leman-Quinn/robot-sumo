#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor{
    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _trigger;
        uint8_t _echo;

    public:
        //---------- CONSTRUCTOR ----------//
        UltrasonicSensor(uint8_t trigger, uint8_t echo);
        
        //---------- GENERAL METHODS ----------//
        // initializes pin modes
        void begin();
        // values returned in cm
        float readDistance();
};

#endif