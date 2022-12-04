//
// Created by Erik Gabrielsen on 11/18/22.
//

#ifndef STACK_PERUNABALLOON_H
#define STACK_PERUNABALLOON_H


#include "Balloon.h"

class PerunaBalloon : public Balloon{
public:
    PerunaBalloon();

    int pop() override;
};


#endif //STACK_PERUNABALLOON_H
