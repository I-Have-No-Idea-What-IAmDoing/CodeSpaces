#ifndef PROGRAM4_BLACKJACK_H
#define PROGRAM4_BLACKJACK_H

#include <iostream>
#include "Deck.h"
#include "Hand.h"

class Blackjack {
public:
    Blackjack();

    void play();
    void printPlayerHand();
    void printDealerHand();
    void revealDealerCard();
    void dealTheDealer();
    void dealCards();
    void dealThePlayer();
private:
    Deck deck;
    Hand dealer;
    Hand player;

    // these are private since they are really only internal stuff
    int presentChoice();
    int checkScore();
};


#endif