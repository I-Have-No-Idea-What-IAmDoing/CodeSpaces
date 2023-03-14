//
// Created by Erik Gabrielsen on 11/18/22.
//

#include <iostream>
#include <vector>
#include "PerunaPop.h"
#include "PerunaBalloon.h"
#include "HornedFrogBalloon.h"


using namespace std;

void PerunaPop::play() {
    int throwsLeft = 5;
    while (throwsLeft > 0){
        Print();
        cout << "You have " << throwsLeft << " throws left" << endl;
        cout << "Pick balloon #:";

        int numBalloon = -1;
        // Loop to make sure it's a valid range
        while (numBalloon > 10 or numBalloon < 1) cin >> numBalloon;

        Balloon* selectedBalloon = balloons.at(numBalloon - 1);
        if (selectedBalloon->isPopped()){
            // Instead of making it an invalid case just put a message here
            // It easier this way...
            cout << "You threw at empty air... the balloon was already popped..." << endl;
        }else{
            int amount = selectedBalloon->pop();
            if (amount > 0) {
                cout << "Popped Peruna for $" << amount << endl;
            }else{
                cout << "Popped a Horned Frog - you lost $" << amount << endl;
            }

            winnings += amount;
        }

        cout << "You now have $" << winnings << endl;
        throwsLeft--;
        cout << endl;
    }

    cout << "Game over" << endl;
}

PerunaPop::PerunaPop(){
    winnings = 0;
    vector<int> randomNumbers;

    // Create 3 random numbers
    randomNumbers.push_back(rand() % 10);
    randomNumbers.push_back(rand() % 10);
    randomNumbers.push_back(rand() % 10);

    for (int i = 0; i < 10; ++i) {

        // Check if the current balloon should be a horned one.
        bool makeHorn = false;
        for (auto currentNumber : randomNumbers) {
            if (i == currentNumber) makeHorn = true;
        }

        if (makeHorn){
            balloons.push_back(new HornedFrogBalloon());
        } else{
            balloons.push_back(new PerunaBalloon());
        }
    }
}

// Probably not needed but hey it couldn't hurt
PerunaPop::~PerunaPop() {
    for (int i = 0; i < 10; ++i) {
        delete balloons.at(i);
    }
}

// Print all the balloons
void PerunaPop::Print(){
    int index = 0;
    for (auto curBalloon: balloons) {
        // * if it's popped
        // Put the shifted index if it's not
        if (curBalloon->isPopped()){
            cout << "[*] ";
        }else{
            cout << "["<< (index + 1) << "] ";
        }
        index++;
    }

    cout << endl;
}

