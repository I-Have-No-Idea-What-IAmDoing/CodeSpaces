//
// Created by Erik Gabrielsen on 10/23/22.
//

#include "Deck.h"

Deck::Deck() {
    regenerate();
}

// Basically creates a new deck
void Deck::regenerate(){
    cards.clear();
    for (int suitIndex = 0; suitIndex < 4; ++suitIndex) {
        for (int rankIndex = 0; rankIndex < 13; ++rankIndex) {
            addCard(Card(suitIndex, rankIndex));
        }
    }

    shuffle();
}

// Shuffle the card by going through each card and switching 2 of them by random
void Deck::shuffle() {
    for (int currentCardIndex = 0; currentCardIndex < cards.size() - 2; ++currentCardIndex) {
        int cardIndexRange = (cards.size() - currentCardIndex + 1);
        int shuffleNum = (rand() % cardIndexRange) + (currentCardIndex - 1);
        Card tempCard = cards.at(shuffleNum);
        cards.at(shuffleNum) = cards.at(currentCardIndex);
        cards.at(currentCardIndex) = tempCard;
    }
}

// pop the top card and 'deal' it out...
Card Deck::dealCard() {
    Card topCard = cards.back();
    cards.pop_back();
    return topCard;
}

void Deck::addCard(Card newCard) {
    cards.push_back(newCard);
}