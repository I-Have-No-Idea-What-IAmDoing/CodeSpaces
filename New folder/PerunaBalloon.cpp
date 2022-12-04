//
// Created by Erik Gabrielsen on 11/18/22.
//

#include "PerunaBalloon.h"

PerunaBalloon::PerunaBalloon() {
    balloonAmount = 10;
    popped = false;
}

int PerunaBalloon::pop() {
    popped = true;
    return balloonAmount;
}
