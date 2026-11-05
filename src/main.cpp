#include "config.h"
#include "Robot.h"

Robot robot(
    TRI_L, ECHO_L,
    TRI_FL, ECHO_FL,
    TRI_FR, ECHO_FR,
    TRI_R, ECHO_R,
    RPWM_A, LPWM_A,
    RPWM_B, LPWM_B
);

void setup() { 
    //---------- SERIAL (DEBUG) ----------//
    Serial.begin(115200);
    robot.begin();
}

void loop() { 
    //robot.sense();
    //robot.think();
    //robot.act();

    //------- DEBUGGING -------//
    // STRAIGHT LINE AT MAX SPEED (100% PWM)
    robot.testForward(255);
}