#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor{
    public:
        //---------- CONSTRUCTOR ----------//
        UltrasonicSensor(uint8_t trigger, uint8_t echo);
        
        //---------- METHODS ----------//
        void begin();

        // values returned in cm
        float readDistance();

    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _trigger;
        uint8_t _echo;
};

#endif