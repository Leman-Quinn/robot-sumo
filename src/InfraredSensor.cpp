#include "InfraredSensor.h"

//---------- CONSTRUCTOR ----------//
InfraredSensor::InfraredSensor(uint8_t out):
    _out(out){

    }

//---------- METHODS ----------//
void InfraredSensor::begin(){
    pinMode(_out, INPUT);
}

bool InfraredSensor::readSurface(){
    return digitalRead(_out);
}
