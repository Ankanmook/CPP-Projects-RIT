#include "NaiveRecursive.h"

using namespace std;

/**
 Function Subsequence   recursive function to obtain LCS
 of two strings
 @param a       string& first input string
 @param b       string& second input string
 @param result  string& longest common subsequence
                        between a and b
 */
int NaiveRecursive::lcs(std::string& a, std::string& b, std::string& result)
{
	int retVal(0);
	call++;

	// this is the "heart" of the recursion where
    // the comparisons and outputs will take place
	if(a.size() > 1 && b.size() > 1)
	{
		// Base case when the two first elements
        // are equal
		if(a[0] == b[0])
		{
			std::string res;
			retVal = 1 + lcs(a.substr(1,a.size()-1),b.substr(1,b.size()-1),res);
			result += a[0] + res;
		}
		// other statements of the naïve algorithm
		else
		{
			// obtaining max value of the two strings
			std::string res1, res2;
			retVal = std::max(lcs(a.substr(1,a.size()-1),b,res1),lcs(a,b.substr(1,b.size()-1),res2));

			// concatenating the result
			if(res1.size() > res2.size()) 
				result +=res1;
			else 
				result +=res2;

		}
	}
	// This is the base case: both strings are of unit size and are equal
	else if ( a.size() && b.size() && a[0] == b[0])
	{
		result += a[0]; 
		retVal = 1;
	}

	return retVal;
}

/**
 Function Test LCS of two strings
 @param a       string& first input string
 @param b       string& second input string
 @param result  calling LCS function from Subsequence
 ckass and testing result over it
 */
void NaiveRecursive::testLCS(std::string x, std::string y)
{
std::string result;

call = 0;

time_t t1 = time(0); 

lcs(x,y,result);
std::cout<<"Native Recursive LCS of "<< x <<"  &  " << y <<" is: "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive calls :" <<call<<endl;
result.clear();

call = 0;

lcs(y,x,result);
std::cout<<"Native Recursive LCS of "<< y <<"  &  " << x <<" is: "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive calls :" <<call<<endl;


time_t t2 = time(0); 
std::cout <<"Total Time Taken :"<< t2 - t1 <<endl;
std::cout<<endl<<endl;
}
