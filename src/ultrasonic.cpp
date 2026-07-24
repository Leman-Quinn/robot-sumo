#include "config.h"
#include "Ultrasonic.h"

//---------- CONSTRUCTOR ----------//
Ultrasonic::Ultrasonic(){
    
};

//---------- PIN SETUP ----------//
void Ultrasonic::ultrasonicInit(){
    // FRONTAL LEFT SENSOR
    pinMode(TRI_FL, OUTPUT);
    pinMode(ECHO_FL, INPUT);
    
    // FRONTAL RIGHT SENSOR
    pinMode(TRI_FR, OUTPUT);
    pinMode(ECHO_FR, INPUT);

    // LEFT SENSOR
    pinMode(TRI_L, OUTPUT);
    pinMode(ECHO_L, INPUT);

    // RIGHT SENSOR
    pinMode(TRI_R, OUTPUT);
    pinMode(ECHO_R, INPUT);
}
//---------- HELPER ----------//
float Ultrasonic::readDistance(uint8_t trigger_pin, uint8_t echo_pin){
    float duration;
    float distance;

    // set trigger to low to avoid dangling
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(5);

    // send wave for 10 microseconds burst
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);

    // receive wave
    duration = pulseIn(echo_pin, HIGH, 30000);
  
    // convert to cm 
    distance = (duration*0.0343)/2;
  
    return distance; 
}

//---------- GENERAL METHODS ----------//
float Ultrasonic::readFrontLeftDistance(){
    return readDistance(TRI_FL, ECHO_FL);
}

float Ultrasonic::readFrontRightDistance(){
    return readDistance(TRI_FR, ECHO_FR);
}

float Ultrasonic::readLeftDistance(){
    return readDistance(TRI_L, ECHO_L);
}

float Ultrasonic::readRightDistance(){
    return readDistance(TRI_R, ECHO_R);
}