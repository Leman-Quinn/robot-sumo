#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
private:
    //---------- HELPER ----------//
    // values returned in cm
    float readDistance(uint8_t trigger_pin, uint8_t echo_pin);

public:
    //---------- CONSTRUCTOR ----------//
    Ultrasonic();

    //---------- PIN SETUP ----------//
    // initializes pin modes
    void ultrasonicInit();

    //---------- GENERAL METHODS ----------//
    float readFrontLeftDistance();
    float readFrontRightDistance();
    float readLeftDistance();
    float readRightDistance();
};

#endif