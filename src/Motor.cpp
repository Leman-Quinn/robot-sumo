#include "Motor.h"

//---------- CONSTRUCTOR ----------//
Motor::Motor(uint8_t pol1, uint8_t pol2){
    this->_pol1 = pol1;
    this->_pol2 = pol2;
};

//---------- METHODS ----------//
void Motor::begin(){
    pinMode(_pol1, OUTPUT);
    pinMode(_pol2, OUTPUT);

    // avoids movement on init
    stop();

    delay(5000);
}

void Motor::forward(){
    digitalWrite(_pol1, HIGH);
    digitalWrite(_pol2, LOW);
}

void Motor::backward(){
    digitalWrite(_pol1, LOW);
    digitalWrite(_pol2, HIGH);
}

void Motor::stop(){
    digitalWrite(_pol1, LOW);
    digitalWrite(_pol2, LOW);
}