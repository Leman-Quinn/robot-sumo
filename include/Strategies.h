#ifndef STRATEGIES_H
#define STRATEGIES_H

class Robot; // forward declaration. (It is not necessary to declare #include "Robot.h" here in Strategies.h, but in Strategies.cpp)

namespace Strategies {
    void basic(Robot& robot);
}

#endif