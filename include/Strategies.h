#ifndef STRATEGIES_H
#define STRATEGIES_H

class Robot; // forward declaration. (It is not necessary to declare #include "Robot.h" here in Strategies.h, but in Strategies.cpp)

namespace Strategies {
    void searchAndAttack(Robot& robot);

    /* Future strategies:
    void flankLeft(Robot& robot); --> attempts to approach and flank the enemy from its left side before attacking.
    void flankRight(Robot& robot); --> attempts to approach and flank the enemy from its right side before attacking.
    */
}

#endif