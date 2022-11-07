#include <iostream>
#include "Blackjack.h"
#include <ctime>

int main() {
    srand(time(nullptr)); // seeded for your shuffle

    Blackjack game;
    game.play();

    return 0;
}