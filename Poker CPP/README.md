Assignment
I have developed a new system in C++ that takes a single deck of cards and deals to a specified number of players. The player will have no opportunity to exchange cards, and his hand will immediately validated by the software. Winning hands will be limited to the following combinations (list in order of precedence):
•	Four of a kind
•	Flush (all cards of the same suit)
•	Three of a kind
•	Two pair
•	One pair
Players can play themselves or against other players. The program should prompt the operator on startup for the number of players that are participating in a particular game. In order to evaluate the performance of this new software, the casino has requested that they be able to provide the random seed for deck shuffling as an input. The following .h and .cpp files are provided in the code:
•	card.h
•	card.cpp
•	deck.h
•	deck.cpp
•	hand.h
•	hand.cpp
•	main.cpp
The Deck class represents a deck of cards. The initialization for this function causes a uniform initialization. Have a look at the constructor and Shuffle() functions.
The Card class represents an individual playing card. 
The Hand class represents an individual player's current hand. This is composed of 5 playing cards. 
The main.cpp file will do the actual dealing of the cards. The dealing algorithm deals cards from the deck and do a round robin distribution to the players. Thus, if you had 5 players, and they each needed 5 cards you would pull 5 cards off the deck and assign the first card to player one, the second to player 2, etc. Then you would deal 5 more and repeat the process until 25 cards are dealt.
Example
Enter seed: 10
Enter number of players: 4
Player 1 hand:   JS 10D  3H  7C 10S   One Pair
Player 2 hand:   4C  6C  6S  5C  8C   One Pair
Player 3 hand:   6H  KD  QC  9C 10H
Player 4 hand:   9D  JC  4H  5D  QD

