# include <iostream>
# include<ostream>
# include<istream>
# include<string>
# include <iomanip>
# include<sstream>
# include<stdexcept>


class Time
{
public :

 /**
   *
   * Default Constructor
   */
   Time();

 /**
   *
   * Custom Constructor that takes string input
   */
   Time(std::string &time);


 /**
   *
   * Custom Constructor that takes int input
   */
   Time(int sec);


  /**
    * Overload << operator for time object 
    *
    * @return The object itself (*this).
    */
   friend std::ostream &operator<<(std::ostream &stream, const Time time);

  /**
    * Overload >> operator for time object 
    *
    * @return The object itself (*this).
    */
   friend std::istream &operator>>(std::istream &stream, Time& time);


   
   /**
    * Mutator for second of Time object 
    *
    * @return void
    */  
   void setSeconds(int& sec);   

   
   /**
    * Mutator for seconds of time object
    * accepts string time to pass it on to 
    * update time
    *
    * @return void 
    */
   void setSeconds(std::string& time);
   
   /**
    * Mutator for updating time object
    * takes hours, minutes, seconds in string 
    *
    * @return void
    */
   void updateTime(std::string hour,std::string minute, std::string sec);


   /**
    * Short Hand += overload takes const Time& input
    *
    * @return Time object
    */
    Time operator+=(const Time &time);
	
    
   /**
    * Accessor for accessing seconds of time object
    *
    * @return seconds for time object
    */
    int getSeconds() const;


private :

   int second;

};


/* Relational operators */

/**
 * Overload < operator for a Time object
 *
 * @return true, if time1 < time2
 */
bool operator<(const Time& time1, const Time& time2);

/**
 * Overload > operator for a Time object
 *
 * @return true, if time1 > time2
 */
bool operator>(const Time& time1, const Time& time2) ;

/**
 * Overload != operator for a Time object
 *
 * @return true, if time1 != time2
 */
bool operator!=(const Time& time1, const Time& time2);

/**
 * Overload < operator for a Time object
 *
 * @return true, if time1 == time2
 */
bool operator==(const Time& time1, const Time& time2);



/* Arithmetic operators */

/**
 * Calculate the sum of the two Time objects
 *
 * @return new Time object which is the sum
 * of time1 and time2
 */
Time operator+(const Time &time1, const Time& time2);

/**
 * Calculate the difference of the two Time objects
 *
 * @return new Time object which is the difference of 
 * time1 and time2
 */
Time operator-(const Time &time1, const Time& time2);

/**
 * Calculate the division of the given Time object by given int value
 *
 * @return new Time object which is the division of time
 * by given int value 
 */
Time operator/(const Time &time, const int& denom);

/**
 * Calculate the multiplication of the given Time 
 * object by given int value
 *
 * @return new Time object which is the multiplication of
 * time by given int value 
 */
Time operator*(const Time &time, const int &num);

