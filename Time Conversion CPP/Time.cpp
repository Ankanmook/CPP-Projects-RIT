/**
 * Time.cpp
 * For use with 4003-703-01
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Ankan Mookherjee
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time( void )
{
   seconds = 0;
}

Time::Time( int _seconds )
{
   seconds = _seconds;
}

Time::Time( string t )
{
   setTime( t );
}

Time Time::add( Time t )
{
   return seconds += t.seconds;
}

Time Time::subtract( Time t )
{
   return seconds -= t.seconds;
}

std::string Time::str() const
{
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();

}

void Time::setTime( std::string t )
{

       //Declaring variables
	size_t separator = 0;
	string hour= "0";
	int sec;
	string minute;

	separator = t.find(":");
	hour = t.substr(0,separator);

	//If Expression is like :min
	if(separator == 0){
		hour ="0";
	}
	//If Expression is like min
	else if(separator == -1){
		hour ="0";
	}
	//If Expression is like ' :min'
	else if(t.at(separator-1) ==' '){
		hour ="0";
	}

	minute = t.substr(separator+1);

	std::stringstream sh(hour);
	int ihour;
	sh>>ihour;
	//Check for hour
	if(ihour>24)
		ihour = ihour -24;

	std::stringstream sm(minute);
	int iminute;
	sm>>iminute;
	//Check for minute
	if(iminute>60)
		iminute = iminute -60;

	sec = ihour*3600 + iminute*60 ;

	//If the total time duration is more than 24 hours
	if( sec > 86400 ){
		this->seconds = sec - 86400;
	}

	else {
		this->seconds = sec;
	}
}

