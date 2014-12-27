/* Author : Ankan Mookherjee
 * Id : axm3244
 * Assginment : 3 Poker Program
 */

#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main()
{
   vector< Hand > hands;
   Deck deck;
   int players; 
   int seed;
   int sizeOfHand = 5;

   std::cout << "Enter seed: ";
   std::cin >> seed;
   srand(unsigned(seed));

   std::cout << "Enter number of players: ";
   std::cin >> players; 

   deck.Shuffle();

   /* Your code here */
   /* Deal cards from the deck and do a round robin distribution to the
    * players.  Thus, if you had 5 players, and they each needed 5 cards you
    * would pull 5 cards off the deck and assign the first card to player one,
    * the second to player 2, etc.. Then you would deal 5 more and repeat the
    * process until 25 cards are dealt 
    */

   /* Allocating space to vector equal to the number of players */
   for(int i=0; i<players ; i++)
     {
	Hand h;
	hands.push_back(h);
     }

    /* Dealing the cards to the players */
    for(int i=0; i<sizeOfHand; i++)
      {
         vector<Card> dealtcard = deck.Deal(players); 
         for(int i= 0; i< players; i++)
            { 
              /* Extracting hands configuration from first position*/  
		Hand h = hands[0];
		/* Adding Card to the hand configuration*/
		h.add(dealtcard[i]);
		/* Erasing this position and adding hand configuration to the end */
		hands.erase(hands.begin());
		hands.push_back(h);
             }
      }


    /* Displaying result */
    for(int i=0; i<players; i++)
       {
         std::cout<<"Player " << i+1 << " hand:" ;
         (hands[i]).showHand();
         (hands[i]).check();
	   std::cout<<endl;
       }


    return 0;
}
