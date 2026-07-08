#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>

// ---------- PIN SETUP ----------
void MotorsInit();

// ---------- METHODS ----------
void MoveForward();
void MoveBackward();
void RotateLeft();
void RotateRight();
void Brake();

#endif