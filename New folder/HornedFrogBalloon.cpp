//
// Created by Erik Gabrielsen on 11/18/22.
//

#include "HornedFrogBalloon.h"

HornedFrogBalloon::HornedFrogBalloon() {
    balloonAmount = 20;
    popped = false;
}

int HornedFrogBalloon::pop() {
    popped = true;
    return -balloonAmount;
}
