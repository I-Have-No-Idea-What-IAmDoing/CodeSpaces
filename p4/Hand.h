#ifndef PROGRAM4_HAND_H
#define PROGRAM4_HAND_H

#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();

    int getScore();
    void addCard(Card c);
    Card GetCard(int);
    void Print();
    void clearHand();
private:
    std::vector<Card> cards;
};


#endif //PROGRAM4_HAND_H
