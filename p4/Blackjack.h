#ifndef PROGRAM4_BLACKJACK_H
#define PROGRAM4_BLACKJACK_H

#include <iostream>
#include "Deck.h"
#include "Hand.h"

class Blackjack {
public:
    Blackjack();

    void play();

private:
    Deck deck;
    Hand dealer;
    Hand player;
};


#endif