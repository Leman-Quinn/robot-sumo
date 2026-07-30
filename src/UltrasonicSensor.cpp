#include "UltrasonicSensor.h"

//---------- CONSTRUCTOR ----------//
UltrasonicSensor::UltrasonicSensor(uint8_t trigger, uint8_t echo){
    this->_trigger = trigger;
    this->_echo = echo;    
}

//---------- METHODS ----------//
void UltrasonicSensor::begin(){
    pinMode(_trigger, OUTPUT);
    pinMode(_echo, INPUT);
}

float UltrasonicSensor::readDistance(){
    float duration;
    float distance;

    // set trigger to low to avoid dangling
    digitalWrite(_trigger, LOW);
    delayMicroseconds(5);

    // send wave for 10 microseconds burst
    digitalWrite(_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigger, LOW);

    // receive wave
    duration = pulseIn(_echo, HIGH, 30000);

    // convert to cm 
    distance = (duration*0.0343)/2;

    if (distance == 0)
    {
        return -1;
    }
  
    return distance; 
}