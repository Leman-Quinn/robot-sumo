#ifndef INFRAREDSENSOR_H
#define INFRAREDSENSOR_H

#include <Arduino.h>

class InfraredSensor {
    public:
        //---------- CONSTRUCTOR ----------//
        InfraredSensor(uint8_t out);

        //---------- METHODS ----------//
        void begin();
        bool readSurface();
    
    private:
        //---------- ATTRIBUTES ----------//
        uint8_t _out;
};

#endif