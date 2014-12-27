/* Author : Ankan Mookherjee
 * Id : axm3244
 * Assginment : 3 Poker Program
 */


#include "card.h"
#include <sstream>

using namespace std;

Card::Card()
{
}

Card::Card( Card::SUITS _suit, Card::COUNT _val): suit(_suit),value(_val)
{

}

std::string Card::str()
{
   ostringstream os;
   os << valToStr() << suitToStr();
   return os.str();
}

/* Your code here */


Card::SUITS Card::getSuit()
{
   return suit;
}


Card::COUNT Card::getValue	()
{
   return value;
}

std::string Card::valToStr()
{
   Card::COUNT count = getValue();

   if(count == TWO ) return " 2";
   if(count == THREE ) return " 3";
   if(count == FOUR ) return " 4";
   if(count == FIVE ) return " 5";
   if(count == SIX ) return " 6";
   if(count == SEVEN ) return " 7";
   if(count == EIGHT ) return " 8";
   if(count == NINE ) return " 9";
   if(count == TEN ) return "10";
   if(count == JACK ) return " J";
   if(count == QUEEN ) return " Q";
   if(count == KING ) return " K";
   if(count == ACE ) return " A";

   return "DEFAULT";
}

std::string Card::suitToStr()
{
   Card::SUITS suit = getSuit();

   if (suit == CLUBS ) return "C";
   if (suit == DIAMONDS ) return "D";
   if (suit == HEARTS ) return "H";
   if (suit == SPADES ) return "S";
   
   return "DEFAULT";
}

