#include "config.h"
#include "Robot.h"

Robot robot(
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    AIN1, AIN2, PWMA, 
    BIN1, BIN2, PWMB
);

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    Serial.begin(115200);
    robot.begin();
}

void loop() { 
    robot.sense();
    robot.think();
    robot.act();
}