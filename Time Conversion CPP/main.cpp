/*
 * main.cpp
 * For use with 4003-703-01,
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Ankan Mookherjee
 */
#include "Time.h"
#include <iostream>

using namespace std;


/* Calculate Time Function
 *
 * Calculates time by using line input from the user
 *
 * Argument: None
 * Returns: Void
 */
void caculateTime(){

   //Declaring variables
   string str;
   string prefix;
   string suffix;

   //Signifying symbol before the time expression to be evaluated
   string prevSymbol;
   //Signifying symbol after the time expression to be evaluated
   string afterSymbol;

   size_t plus = 0;
   size_t minus = 0;

   //Setting the time Equal to Zero
   Time time("0:0:0");
   //Getting input from user in line
   getline( cin, str );

   //Finding occurence of + and minus sign
   plus = str.find("+");
   minus = str.find("-");

   //Setting values of previous and after symbols
   prevSymbol =" ";
   afterSymbol ="+";


   //To check whether the addition or multiplication have not finished
   while( (plus !=-1) || (minus !=-1)){

	//Only Plus
	if((plus !=-1)&(minus ==-1)){
		 prefix = str.substr(0,plus);
		 suffix = str.substr(plus+1);
		 afterSymbol ="+";
	}

	//Only Minus
	else if((minus != -1)&(plus ==-1)){
		 prefix = str.substr(0,minus);
		 suffix = str.substr(minus+1);
		 afterSymbol ="-";
	}

	//Plus Before Minus
	else if((plus < minus) &&(minus != -1)){
		 prefix = str.substr(0,plus);
		 suffix = str.substr(plus+1);
		 afterSymbol ="+";
	}

	//Minus Before Plus
	else if((minus <plus)&&(plus != -1)){
		 prefix = str.substr(0,minus);
		 suffix = str.substr(minus+1);
		 afterSymbol ="-";
	}

	//Setting rest of the part of the code to suffix
	str = suffix;

	//If there is no previous symbol
	//This means it is the starting of the line
	if(prevSymbol ==" "){
		//Adding time to zero
		Time newtime(prefix);
		time.add(newtime);
	}

	//Next symbol is +
	else if(prevSymbol == "+"){
		Time newtime(prefix);
		time.add(newtime);
	}

	//Next Symbol is -
	else if(prevSymbol == "-"){
		Time newtime(prefix);
		time.subtract(newtime);
	}

	//Next Symbol is empty
	else if(afterSymbol ==" "){
		break;

	}

	else{
		std::cout<<" "<<endl;
	}

	//Setting previous symbol equal to after symbol for the next
	//expression to be evaluated and after symbol to empty
	prevSymbol = afterSymbol;
	afterSymbol = " ";


	//Finding next position of plus and minus
	plus = str.find("+");
	minus = str.find("-");

   }

  //Adding the suffix part to the whole exression
   if(prevSymbol =="+"){
	 Time newtime(prefix);
	 time.add(str);
   }

   else if(prevSymbol =="-"){
	  Time newtime(prefix);
	  time.subtract(str);
   }

    std::cout<<time.str()<<endl;

}


int main()
{

  do
   {
	 caculateTime();
   } while ( !cin.eof() );

}
