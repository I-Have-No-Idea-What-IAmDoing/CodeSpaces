//
// Created by Erik Gabrielsen on 11/18/22.
//

#ifndef STACK_HORNEDFROGBALLOON_H
#define STACK_HORNEDFROGBALLOON_H


#include "Balloon.h"

class HornedFrogBalloon : public Balloon{
public:
    HornedFrogBalloon();

    int pop() override;
};


#endif //STACK_HORNEDFROGBALLOON_H
