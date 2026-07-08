#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

// ---------- PIN SETUP ----------
void UltrasonicInit();

// ---------- METHODS ----------
float ReadFrontLeftDistance();
float ReadFrontRightDistance();
float ReadLeftDistance();
float ReadRightDistance();

#endif