#ifndef STRATEGIES_H
#define STRATEGIES_H

class Robot; // forward declaration. (It is not necessary to declare #include "Robot.h" here in Strategies.h, but in Strategies.cpp)

class Strategy{
    public:
        // CONSTRUCTOR
        Strategy(Robot& robot);

        // METHODS
        void searchAndAttack();
        /* Future strategies:
        void flankLeft(); --> attempts to approach and flank the enemy from its left side before attacking.
        void flankRight(); --> attempts to approach and flank the enemy from its right side before attacking.
        */
    private:
        Robot& _robot;
};

#endif