#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
    private:
        //---------- HELPER ----------//
        void SetPolarities(bool pol1, bool pol2, bool pol3, bool pol4);

    public:
        //---------- CONSTRUCTOR ----------//
        Motor();

        //---------- PIN SETUP ----------//
        // initializes pin modes
        void MotorInit();

        //---------- GENERAL METHODS ----------//
        void MoveForward();
        void MoveBackward();
        void RotateLeft();
        void RotateRight();
        void Brake();

};

#endif