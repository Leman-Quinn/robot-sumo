#include "config.h"
#include "Motor.h"

//---------- CONSTRUCTOR ----------//
Motor::Motor(){

};

// ---------- PIN SETUP ----------
void Motor::MotorInit(){
    // MOTOR 1
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    // MOTOR 2
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // AVOIDS UNWANTED MOVEMENT ON STARTUP
    Brake();

    delay(5000);
}

// ---------- IMPLEMENTATIONS ----------
// HELPER FUNCTION
static void SetPolarities(bool pol1, bool pol2, bool pol3, bool pol4){
    digitalWrite(IN1, pol1);
    digitalWrite(IN2, pol2);
    digitalWrite(IN3, pol3);
    digitalWrite(IN4, pol4);
}

// MAIN FUNCTIONS
void MoveForward(){
    return SetPolarities(LOW, HIGH, LOW, HIGH);
}

void MoveBackward(){
    return SetPolarities(HIGH, LOW, HIGH, LOW);
}

void RotateLeft(){
    return SetPolarities(HIGH, LOW, LOW, HIGH);
}

void RotateRight(){
    return SetPolarities(LOW, HIGH, HIGH, LOW);
}

void Brake(){
    return SetPolarities(LOW, LOW, LOW, LOW);
}