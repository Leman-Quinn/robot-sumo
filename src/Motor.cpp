#include "config.h"
#include "Motor.h"

//---------- CONSTRUCTOR ----------//
Motor::Motor(uint8_t pol1, uint8_t pol2){
    this->_pol1 = pol1;
    this->_pol2 = pol2;
};

// ---------- PIN SETUP ----------
void Motor::init(){
    pinMode(_pol1, OUTPUT);
    pinMode(_pol2, OUTPUT);

    // AVOIDS MOVEMENT ON INIT
    Stop();

    delay(5000);
}

//---------- GENERAL METHODS ----------//
void Motor::Forward(){
    digitalWrite(_pol1, HIGH);
    digitalWrite(_pol2, LOW);
}

void Motor::Backward(){
    digitalWrite(_pol1, LOW);
    digitalWrite(_pol2, HIGH);
}

void Motor::Stop(){
    digitalWrite(_pol1, LOW);
    digitalWrite(_pol2, LOW);
}