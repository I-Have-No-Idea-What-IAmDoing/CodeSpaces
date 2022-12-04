//
// Created by Erik Gabrielsen on 11/18/22.
//

#ifndef STACK_PERUNAPOP_H
#define STACK_PERUNAPOP_H
#include "Balloon.h"
#include <vector>
class PerunaPop {
public:
    explicit PerunaPop();

    virtual ~PerunaPop();

    void Print();

    void play();
private:
    int winnings;
    std::vector<Balloon*> balloons;
};


#endif //STACK_PERUNAPOP_H
