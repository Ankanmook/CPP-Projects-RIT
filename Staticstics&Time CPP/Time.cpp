#include "Time.h"

using namespace std;


Time::Time():second(0)
{

}


Time::Time(string &time):second(0)
{

}



Time::Time(int sec):second(sec)
{

}


std::ostream &operator<<(std::ostream &stream, const Time time)
{
	int hour,rest,minute,second;
	hour = time.getSeconds()/3600;
	
	rest = time.getSeconds()%3600;
	
	minute= rest/60;
	second = rest%60;

	/* Formatting output in hours:minutes:seconds*/
	stream << hour << ":" << setfill('0') << setw(2)<<
		minute <<":"<<setfill('0') << setw(2)<< second;

	return stream;
}






std::istream &operator>>(std::istream &stream, Time& time) 
{
	std::string strTime;
	char* hour;
	char* min;
	char* sec;
	
	/*Declaring Variables */
	int ihour = 0;
	int iminute = 0;
	int isecond = 0;

	/* Extracts the charatcters from stream 
		and puts them into strTime */
	std::getline(stream, strTime);

	if(stream.eof())
		return stream;

	time.setSeconds(strTime);

	return stream;
}


void Time::setSeconds(int& sec)
{
	this->second = sec;
}


void Time::setSeconds(std::string& strTime)
{
	try{

	/* Declaring Variables */
	string hour ;
	string minute;
	string sec;

	unsigned found1 = strTime.find_first_of(":");
	hour = strTime.substr(0,found1);

	/* Pruning hour */
	strTime = strTime.substr(found1+1);
	unsigned found2 = strTime.find_first_of(":");
	minute = strTime.substr(0,found2);

	/* Pruning minute */
	strTime = strTime.substr(found2+1);
	unsigned found3 = strTime.find_first_of(":");
	sec = strTime.substr(0,found3);

	if(found1 == std::string::npos || found2 == std::string::npos)
		throw std::runtime_error("Invalid time entry");

	updateTime(hour,minute,sec);
	}

	catch(exception e)
	{
		throw std::runtime_error("Invalid time entry");
	}
	

}


void Time::updateTime(std::string hour,std::string minute, std::string sec)
{
	/*Declaring Variables */
	int ihour = 0;
	int iminute = 0;
	int isecond = 0;

	/* Converting string hour into int */
	std::stringstream sh(hour);
	sh>>ihour;
	if(ihour<0)
		throw std::runtime_error("Invalid time entry");

	/* Converting string minute into int */
	std::stringstream sm(minute);
	sm>>iminute;
	if ((iminute>60)||(iminute<0))
		throw std::runtime_error("Invalid time entry");

	/* Converting string second into int */
	std::stringstream sc(sec);
	sc>>isecond;
	if((isecond>60)||(isecond<0))
		throw std::runtime_error("Invalid time entry");
	
	/* Finally setting second of this class */
	this->second = ihour*3600 + iminute*60 + isecond;

}


int Time::getSeconds() const
{
	return this->second;
}


// Shorthand Operator
Time Time::operator+=(const Time& time)
{
    this->second = this->second +time.second;
    return *this;
}


// Relational operators
bool operator<(const Time &time1, const Time &time2)
{
	return ( time1.getSeconds() < time2.getSeconds());
}

bool operator>(const Time &time1, const Time &time2)
{
	return (time1.getSeconds() > time2.getSeconds());
}

bool operator!=(const Time &time1, const Time &time2)
{
	return (time1.getSeconds() != time2.getSeconds());
}

bool operator==(const Time &time1, const Time &time2)
{
	return (time1.getSeconds() == time2.getSeconds());
}



// Arithmetic operators
Time operator+(const Time& time1, const Time &time2 )
{
	Time newT;
	int sec = time1.getSeconds() + time2.getSeconds();
	newT.setSeconds(sec); 
	
	return newT;
}

Time operator-(const Time &time1, const Time &time2)
{
	Time newT;
	int sec = time1.getSeconds() - time2.getSeconds();
	newT.setSeconds(sec); 
	return newT;
}

Time operator/(const Time &time, const int& denom)
{
	Time newT;
	int sec = time.getSeconds()/ denom;
	newT.setSeconds(sec); 
	return newT;
}

Time operator*(const Time &time, const int &num)
{
	Time newT;
	int sec = time.getSeconds() * num;
	newT.setSeconds(sec);
	return newT;
}

 