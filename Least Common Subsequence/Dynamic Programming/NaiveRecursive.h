#include<iostream>
#include<string>
#include<time.h>
#include<ctime>
#include<array>


/**
 class Subsequence is the recursive program
 that will implement the algorithm
 FIELD  int call    Number of recursive calls made
 */
class NaiveRecursive
{

public :
	int call ;

	int lcs(std::string& x, std::string& y, std::string& result);

	void testLCS(std::string x, std::string y);

};
