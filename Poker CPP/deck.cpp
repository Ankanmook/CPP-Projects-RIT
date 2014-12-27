/* Author : Ankan Mookherjee
 * Id : axm3244
 * Assginment : 3 Poker Program
 */


#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

Deck::Deck()
{
   Shuffle();
}

void Deck::Shuffle()
{
   cards.erase(cards.begin(), cards.end());
   for ( int i = Card::CLUBS; i <= Card::SPADES; i++ )
   {
      for ( int j = Card::TWO; j <= Card::ACE; j++ )
      {
         cards.push_back( Card(Card::SUITS(i),Card::COUNT(j)));
      }
   }
   random_shuffle ( cards.begin(), cards.end() );
}


/* Your code here */

std::vector<Card> Deck::Deal(int count)
{
   std::vector<Card> dealingCards ;
   for(int i=0;i<count;i++)
      {  
         /* Taking out element from front and adding to
            the back of the dealingCard vector */
         Card c = cards.front();
         dealingCards.push_back(c);
         /* Removing the card from the deck */
         cards.erase(cards.begin());
      }
   return dealingCards ;
}


void Deck::ShowDeck()
{
   std::vector<Card>::iterator p;
   for (p = cards.begin(); p != cards.end(); p++)
       {
           std::cout<< p->str() << "  " ;
       }
   std::cout<<endl;
}
