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
            uint8_t rpwm_a, uint8_t lpwm_a,
            uint8_t rpwm_b, uint8_t lpwm_b
        );
        //---------------------------------//
        
        //---------- INTERFACES ----------//
        enum class UltrasonicPosition {LEFT, FRONT_LEFT, FRONT_RIGHT, RIGHT, COUNT};
        float getUltrasonicDistance(UltrasonicPosition position);

        enum class EnemyPosition{NONE, LEFT, FRONT_LEFT, FRONT, FRONT_RIGHT, RIGHT, COUNT};
        EnemyPosition getEnemyPosition();
        void setEnemyPosition(EnemyPosition enemyPosition);
        
        enum class State{SEARCH, SEARCH_R, SEARCH_L, ALIGN, ATTACK, EVADE_ENEMY, EVADE_LINE, COUNT};
        State getState();
        void setState(State state);

        enum class Action{FORWARD, FORWARD_LEFT, FORWARD_RIGHT, BACKWARD, BACKWARD_LEFT, BACKWARD_RIGHT, BRAKE, ROTATE_LEFT, ROTATE_RIGHT, PATROL, COUNT};
        Action getAction();
        void setAction(Action action);

        enum class StrategyStep{FORWARD, ROTATE_RIGHT};
        //-------------------------------//

        //---------- METHODS ----------//
        void begin();
        void sense();
        void think();
        void act();
        //-----------------------------//

        //------- DEBUGGING -------//
        void testForward(int pwm);
        void testBackward(int pwm);
        void testMixedMovements(int pwm);
        //-------------------------------//

        //--------------- STRATEGY -----------------//
        void simple_patrol();
        //------------------------------------------//
    private:
        //---------- PROPERTIES ----------//
        float _ultrasonicDistances[static_cast<int>(UltrasonicPosition::COUNT)];
        EnemyPosition _enemyPosition = EnemyPosition::NONE;
        State _state = State::SEARCH;
        Action _action = Action::BRAKE;
        
        UltrasonicSensor _leftUltrasonic;
        UltrasonicSensor _frontLeftUltrasonic;
        UltrasonicSensor _frontRightUltrasonic;
        UltrasonicSensor _rightUltrasonic;
        Driver _driver;

        StrategyStep _stratStep = StrategyStep::FORWARD;
        unsigned long _stratClock = 0;
        //-----------------------------------------//
        
        //---------- SENSE HELPERS ----------//
        void updateUltrasonicSensors();
        //----------------------------------------------//

        //---------- THINK HELPERS ----------//
        void updateEnemyPosition();
        void updateState();
        void updateAction();
        //----------------------------------------------//

        //---------- ACT HELPERS ----------//
        void forward(int pwm);
        void forwardRight(int pwm);
        void forwardLeft(int pwm);
        void backward(int pwm);
        void backwardRight(int pwm);
        void backwardLeft(int pwm);
        void rotateRight(int pwm);
        void rotateLeft(int pwm);
        void brake();
        //--------------------------------------------//
};

#endif