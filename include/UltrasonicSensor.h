#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor{
    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _triggerPin;
        uint8_t _echoPin;

    public:
        //---------- CONSTRUCTOR ----------//
        UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin);
        
        //---------- GENERAL METHODS ----------//
        // initializes pin modes
        void init();
        // values returned in cm
        float readDistance();
};

#endif