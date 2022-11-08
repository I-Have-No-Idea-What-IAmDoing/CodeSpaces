# Program 4 - Blackjack
Information regarding Program 4 is located [here](https://github.com/CS1342-F22/lecture-materials/blob/main/misc/program04/program4.md)


---

# Program 4 - Blackjack
In this program, you will be creating a program using Object Oriented Programming techniques for the game of Blackjack! Your program is due **November 7th @ 6:00 am** submitted to GitHub

## Blackjack
The objective of Blackjack is to get as close to 21 without going over. The player and the dealer are each dealt two cards. The playerʼs cards are dealt face up, and only one of the dealerʼs cards are shown.

Before any cards are dealt, the player makes a wager from their available bank balance.

On the deal, if the player has 21 showing, then the player scores a “Blackjack” and wins. In this game of Blackjack, numbered cards are the value on the card, “face” cards are worth 10, and Aces are worth 11.

If the player does not have 21 on the deal, then the player must “hit” (take an extra card) or “stay” (waits for the dealer to complete their hand). If the player goes over 21, then they lose and the dealer wins. If the player chooses to stay, then they must wait for the dealer to close out their hand (a dealer will automatically “hit” on a card if the dealerʼs hand is less than 17 (and they will keep hitting provided their hand remains less than 17); if the dealerʼs hand is 17 or greater, then they will stay). If the dealer ends up with more than 21, then the dealer busts and the player wins. If the player and dealer end up tying (including 21), then nobody wins and no money changes hands.

If a player wins, then their overall balance increases by the bet they placed. If a player loses, they lose the amount bet from their balance. Make sure that each time a player places a bet, they have sufficient funds to do so.

## Implementation Details
You are to implement the game of blackjack using OOP.
1. Your program will begin by reading in the current balance from the **balance.txt** file. When your program ends, you should update the file with the new bank balance of the player.
2. Your deck of cards must have 52 cards in it and be represented as a vector of Card objects
3. At the beginning of each round, re-create the deck of cards.
4. After creating the cards, shuffle them! You are to implement your own `shuffle()` method for your Deck class. Note you may NOT use a method from the STL to do the shuffle for you. Hint: Think about using random _swaps_
5. All data members of classes must be declared `private`. Use getters / setters where appropriate

The interface files for this project have been provided for you with some functions / data to get you started. Make sure to implement all functions (even through you may not necessarily use them) and feel free to add any others
that you see fit (i.e. maybe some `print()` functions for each class would be useful). The `Card` class has been provided for you to use!

## Grading Rubric
- Blackjack implementation correct **(50 pts)**
- Correct OOP practices **(40 pts)**
    - You may NOT edit `main.cpp`
    - Implemented all functions
    - Used getters and setters appropriately
    - Define and Implement a Default Constructor and Overloaded Constructor
    - Proper initialization of data members
    - Properly define member functions of class (using .h and .cpp files)
- Code adheres to proper spacing and formatting **(10 pts)**

## Program Submission
You are to upload your finished program to GitHub by the assignment due date.

## Sample Output
A sample output file is provided below. Try to format your output as closely as possible to this:

```
Welcome to Blackjack! Let's Play!

Loading bank balance...

---- Hand 1 ----
Your balance is $100
Place your bet: $10

Dealing cards...

Dealers Hand:
King of Clubs

Players Hand:
Three of Diamonds
Queen of Spades
Hand Value: 13

Enter 's' to stay or 'h' to hit: h
New Card:
Nine of Clubs
Your Hand Value: 22

You busted!
You lost $10

Enter 'c` to continue or `q` to quit: c

---- Hand 2 ----
Your balance is $90
Place your bet: $15

Dealing cards...

Dealers Hand:
Jack of Spades

Players Hand:
Seven of Clubs
Three of Hearts
Hand Value: 10

Enter 's' to stay or 'h' to hit: h
New Card:
Seven of Hearts
Your Hand Value: 17

Enter 's' to stay or 'h' to hit: s

Dealer's Hand:
Jack of Spades
Two of Hearts
Hand Value: 12

Dealer Hits...
New Card: Jack of Clubs
Dealer's Hand Value: 22
Dealer Busted!
You won $15

Enter 'c` to continue or `q` to quit: c

---- Hand 3 ----
Your balance is $105
Place your bet: $40

Dealing cards...

Dealers Hand:
Queen of Hearts

Players Hand:
Three of Diamonds
Six of Clubs
Hand Value: 9

Enter 's' to stay or 'h' to hit: h
New Card:
Ace of Spades
Your Hand Value: 20

Enter 's' to stay or 'h' to hit: s

Dealer's Hand:
Queen of Hearts
Six of Diamonds
Hand Value: 16

Dealer Hits...
New Card: Queen of Clubs
Dealer's Hand Value: 26
Dealer Busted!
You won $40

Enter 'c` to continue or `q` to quit: c

---- Hand 4 ----
Your balance is $145
Place your bet: $40

Dealing cards...

Dealers Hand:
Eight of Diamonds

Players Hand:
Queen of Clubs
Nine of Clubs
Hand Value: 19

Enter 's' to stay or 'h' to hit: s

Dealer's Hand:
Eight of Diamonds
Five of Clubs
Hand Value: 13

Dealer Hits...
New Card: Two of Spades
Dealer's Hand Value: 15
Dealer Hits...
New Card: Eight of Hearts
Dealer's Hand Value: 23
Dealer Busted!
You won $40

Enter 'c` to continue or `q` to quit: q

Process finished with exit code 0