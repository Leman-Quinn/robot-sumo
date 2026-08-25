#ifndef ROBOT_H
#define ROBOT_H

#include "UltrasonicSensor.h"
#include "Driver.h"

class Robot {
    public:
        //---------- CONSTRUCTOR ----------//
        Robot(
            uint8_t leftTrigger, uint8_t leftEcho,
            uint8_t frontLeftTrigger, uint8_t frontLeftEcho,
            uint8_t frontRightTrigger, uint8_t frontRightEcho,
            uint8_t rightTrigger, uint8_t rightEcho,
            uint8_t pol1, uint8_t pol2,
            uint8_t pol3, uint8_t pol4
        );
        //---------------------------------//
        
        //---------- INTERFACES ----------//
        enum class UltrasonicPosition {LEFT, FRONT_LEFT, FRONT_RIGHT, RIGHT, COUNT};
        float getUltrasonicDistance(UltrasonicPosition position);
        
        enum class EnemyPosition{NONE, LEFT, FRONT_LEFT, FRONT, FRONT_RIGHT, RIGHT, COUNT};
        EnemyPosition getEnemyPosition();
        void setEnemyPosition(EnemyPosition enemyPosition);
        
        enum class State{SEARCH, ALIGN, ATTACK, EVADE_ENEMY, EVADE_LINE, COUNT};
        State getState();
        void setState(State state);

        enum class Action{FORWARD, BACKWARD, BRAKE, ROTATE_LEFT, ROTATE_RIGHT};
        Action getAction();
        void setAction(Action action);
        //-------------------------------//

        //---------- METHODS ----------//
        void begin();
        void sense();
        void think();
        void act();
        //-----------------------------//
    private:
        //---------- INTERNAL PROPERTIES ----------//
        float _ultrasonicDistances[static_cast<int>(UltrasonicPosition::COUNT)];
        EnemyPosition _enemyPosition = EnemyPosition::NONE;
        State _state = State::SEARCH;
        Action _action = Action::BRAKE;
        UltrasonicSensor _leftUltrasonic;
        UltrasonicSensor _frontLeftUltrasonic;
        UltrasonicSensor _frontRightUltrasonic;
        UltrasonicSensor _rightUltrasonic;
        Driver _driver;
        //-----------------------------------------//
        
        //---------- (SENSE) INTERNAL HELPERS ----------//
        void updateUltrasonicSensors();
        //----------------------------------------------//

        //---------- (THINK) INTERNAL HELPERS ----------//
        
        //----------------------------------------------//

        //---------- (ACT) INTERNAL HELPERS ----------//
        void forward();
        void backward();
        void rotateRight();
        void rotateLeft();
        void brake();
        //--------------------------------------------//
};

#endif