#ifndef ROBOT_H
#define ROBOT_H

#include "UltrasonicSensor.h"
#include "Motor.h"

class Robot {
private:
    Motors motors;
    Ultrasonic ultrasonic;
    // Infrared infrared;

public:
    // CONSTRUCTOR
    Robot();
}

#endif