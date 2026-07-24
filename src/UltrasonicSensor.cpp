#include "UltrasonicSensor.h"

#include <Arduino.h>

//---------- CONSTRUCTOR ----------//
UltrasonicSensor::UltrasonicSensor(uint8_t trigger_pin, uint8_t echo_pin){
    this->_triggerPin = trigger_pin;
    this->_echoPin = echo_pin;    
}

//---------- PIN SETUP ----------//
void UltrasonicSensor::init(){
    pinMode(_triggerPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

//---------- GENERAL METHODS ----------//
float UltrasonicSensor::readDistance(){
    float duration;
    float distance;

    // set trigger to low to avoid dangling
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(5);

    // send wave for 10 microseconds burst
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    // receive wave
    duration = pulseIn(_echoPin, HIGH, 30000);
  
    // convert to cm 
    distance = (duration*0.0343)/2;
  
    return distance; 
}