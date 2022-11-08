//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Hand.h"

Hand::Hand() = default;

// Sum up all the card scores
int Hand::getScore() {
    int totalScore = 0;
    for (Card currentCard : cards)
    {
        totalScore += currentCard.getScore();
    }

    return totalScore;
}

void Hand::clearHand() {
    cards.clear();
}

void Hand::addCard(Card c) {
    cards.push_back(c);
}

Card Hand::GetCard(int cardIndex) {
    return cards.at(cardIndex);
}

// Loop through each card and print
void Hand::Print() {
    for (auto & card : cards) {
        card.Print();
    }
}
