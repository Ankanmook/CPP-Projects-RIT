/* Author : Ankan Mookherjee
 * Id : axm3244
 * Assginment : 3 Poker Program
 */


#include "hand.h"
#include <iostream>

using namespace std;

/* Your code here */
void Hand::add(Card card )
{
   cards.push_back(card);
}


void Hand::showHand()
{
   std::vector<Card>::iterator p;
   for(p = cards.begin(); p != cards.end(); p++)
       {
           std::cout<<(*p).str()<< "  "; 
       }
}



void Hand::check()
{

     bool fourofakind=false;
     bool flush=false;
     bool threeofakind=false;
     bool twopair=false;
     bool onepair=false;

     /* Vector of card suit with 13 values and each having 
        0 value initialize in it  */
     std::vector<int> CardValue(13,0);

     /* Vector of card with 4 suit allowed and 0 initialized */
     std::vector<int> CardSuit(4,0);
     int suit;
     int value;

    std::vector<Card>::iterator p;

    for(p = cards.begin(); p != cards.end(); p++)
       {
           /*Suit Value could vary from 0 to 3 */
           suit  = (*p).getSuit() - 1;

           /*Value of card could vary from 0 to 12 */ 
           value = (*p).getValue() - 2;
           
           /* Incrementing CardValue  by one to count 
		number of cards with similar value in one hand */
           CardValue[value] = CardValue[value]+1;
           
           /* Incrementing CardSuit  by one to count
		number of cards with similar suit in one hand */ 
           CardSuit[suit] = CardSuit[suit]+1;
       }

    std::vector<int>::iterator iter; 

    /* Counting type of card by checking CardValue Vector */
    for(iter = CardValue.begin(); iter != CardValue.end(); iter++)
       {
         if(( *iter == 4) ||(*iter ==5))
            {
               fourofakind = true;
               break;
            }  
         
         if(( *iter == 3) && ( (*iter !=5)||(*iter !=4) ))
            {
               threeofakind= true;
               break;
            }

         if(( *iter == 2) && (onepair ==false ))
            {
               onepair= true;
               /* Setting it to 0 to check for two pair*/
	         *iter = 0;
		  continue;
            }

         if(( *iter == 2) && (onepair== true) )
            {
               twopair= true;
               break;
            }

       }

    /* Checking for Flush */
    for(iter = CardSuit.begin(); iter != CardSuit.end(); iter++)
       {
         if( *iter == 4) 
            {
               flush= true;
            }  

       }

    /* Dumping out current users hand with result */
    if(fourofakind == true)
       {
          std::cout<<"Four of a kind ";
       }

    if((flush== true)&& (fourofakind == false))
       {
          std::cout<<"Flush ";
       }

    if((threeofakind== true)&&(fourofakind == false)&&(flush == false))
       {
          std::cout<<"Three of a kind ";
       }

    if((twopair== true)&&(fourofakind == false)&&
      (flush == false)&&(threeofakind == false))
       {
          std::cout<<"Two pair ";
       }

    if((onepair== true)&&(fourofakind == false)&&(flush == false)&&
      (threeofakind == false)&&(twopair ==false))
       {
          std::cout<<"One pair ";
       }

}