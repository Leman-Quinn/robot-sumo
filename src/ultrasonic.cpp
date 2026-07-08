#include "config.h"
#include "ultrasonic.h"

// ---------- PIN SETUP ----------
void UltrasonicInit(){
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

// ---------- IMPLEMENTATIONS ----------
// HELPER FUNCTION
static float ReadDistance(uint8_t trigger_pin, uint8_t echo_pin){
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

// MAIN FUNCTIONS
float ReadFrontLeftDistance(){
    return ReadDistance(TRI_FL, ECHO_FL);
}

float ReadFrontRightDistance(){
    return ReadDistance(TRI_FR, ECHO_FR);
}

float ReadLeftDistance(){
    return ReadDistance(TRI_L, ECHO_L);
}

float ReadRightDistance(){
    return ReadDistance(TRI_R, ECHO_R);
}