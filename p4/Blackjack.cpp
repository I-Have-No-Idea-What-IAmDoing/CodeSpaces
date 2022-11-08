//
// Created by Erik Gabrielsen on 10/23/22.
//

#include <fstream>
#include "Blackjack.h"
#include "iostream"

using namespace std;

int balance = -1;

// Loads the balance file
Blackjack::Blackjack() {
    cout << "Loading bank balance... \n" << endl;

    ifstream balanceFile;
    balanceFile.open("balance.txt");
    if (balanceFile.good()) {
        balanceFile >> balance;
    }

    balanceFile.close();
}

void Blackjack::play() {
    std::cout << "Welcome to Blackjack! Let's Play!\n" << std::endl;

    int roundNumber = 1;
    while (true)
    {
        cout << "---- Hand " << roundNumber << " ----" << endl;
        cout << "Your balance is $" << balance << endl;
        cout << "Place your bet: $";

        int bet = -1;

        while (bet <= 0 or bet > balance) cin >> bet;
        cout << " | Your bet is $" << bet << endl << endl;

        dealCards();

        revealDealerCard();
        cout << endl;
        printPlayerHand();
        cout << endl;

        int winValue = presentChoice();

        switch (winValue){
            case 0:
                balance -= bet;
                cout << " | You lose $" << bet << "." << endl;
                break;
            case 1:
                balance += bet;
                cout << " | You win $" << bet << "." << endl;
                break;
            case 2:
            default:
                cout << " | Your bet of $" << bet << " has been returned." << endl;
                break;
        }

        char choice = 0;
        cout << "Enter 'c` to continue or `q` to quit: ";
        while (choice != 'c' and choice != 'q') cin >> choice;
        cout << endl;

        switch(choice){
            case 'c':
                // Reset everything for the next round
                deck.regenerate();
                player.clearHand();
                dealer.clearHand();
                break;
            case 'q':
                goto quit;
            default:
                // Shouldn't be possible but good to have some kind of case I guess...
                cout << "Spacetime has collapsed... or something has gone wrong in the major way...";
                throw;
        }

        roundNumber++;
    }

    quit:
        ofstream balanceFile;
        balanceFile.open("balance.txt");
        if (balanceFile.good()) {
            balanceFile << balance;
        }

        balanceFile.close();
        cout << "Thanks for playing :)" << endl;
}

void Blackjack::printPlayerHand()
{
    cout << "Players Hand:" << endl;
    player.Print();
    cout << " | Your Hand Value: " << player.getScore() << endl;
}

void Blackjack::revealDealerCard()
{
    cout << "Dealer Hand:" << endl;
    dealer.GetCard(0).Print();
    cout << " | Card Value: " << dealer.GetCard(0).getScore() << endl;
}

void Blackjack::printDealerHand()
{
    cout << "Dealer Hand:" << endl;
    dealer.Print();
    cout << " | Dealer Hand Value: " << dealer.getScore() << endl;
}

// Deal all cards at the start of the round
void Blackjack::dealCards()
{
    cout << "Dealing cards..." << endl << endl;
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());

    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
}

void Blackjack::dealTheDealer()
{
    cout << "Dealer Draws A Card:" << endl;
    Card newCard = deck.dealCard();
    dealer.addCard(newCard);
    newCard.Print();
    cout << " | Dealer Hand Value: " << dealer.getScore() << endl;
}

void Blackjack::dealThePlayer()
{
    cout << "You Draws A Card:" << endl;
    Card newCard = deck.dealCard();
    player.addCard(newCard);
    newCard.Print();
    cout << " | Your Hand Value: " << player.getScore() << endl;
}

// Check the score and then assigns a winner
// 2 is tied
// 0 is lost
// 1 is win
int Blackjack::checkScore()
{
    auto playerScore = player.getScore();
    auto dealerScore = dealer.getScore();

    if(playerScore > 21){
        cout << "You Busted!" << endl;
        return 0;
    }
    else if (playerScore == 21)
    {
        cout << "You Win!" << endl;
        return 1;
    }

    if(dealerScore > 21){
        cout << "Dealer Busted!" << endl;
        return 1;
    }
    else if (dealerScore == 21)
    {
        cout << "Dealer Win!" << endl;
        return 0;
    }

    if (dealerScore == playerScore)
    {
        cout << "Tie! Nobody Wins!" << endl;
        return 2;
    }
    else if (dealerScore <= playerScore)
    {
        cout << "You Win!" << endl;
        return 1;
    }else if (dealerScore > playerScore) {
        cout << "Dealer Win!" << endl;
        return 0;
    }

    return -1;
}

// Use recursion for choice because I can
int Blackjack::presentChoice()
{
    char choice = 0;
    cout << "Enter 's' to stay or 'h' to hit: ";
    while (choice != 's' and choice != 'h') cin >> choice;
    cout << endl;
    int winValue;
    switch (choice) {
        case 's':
            printDealerHand();
            while (dealer.getScore() < 17)
            {
                cout << endl;
                dealTheDealer();
            }

            cout << endl;
            winValue = checkScore();
            break;
        case 'h':
            dealThePlayer();
            cout << endl;
            if (player.getScore() > 21) {
                winValue = checkScore();
            }
            else {
                return presentChoice();
            }
            break;
        default:
            cout << "how is this real??? something majorly went wrong :O !!!";
            throw;
    }

    return winValue;
}