#include<iostream>
#include<string>
#include<time.h>
#include<ctime>

using namespace std;

/**
 class Subsequence is the recursive program
 that will implement the algorithm
 FIELD  int call    Number of recursive calls made
 
 */
class Subsequence
{

public :
	int call ;

	int lcs(std::string& x, std::string& y, std::string& result);

private :

};

/**
 Function Subsequence   recursive function to obtain LCS
 of two strings
 @param a       string& first input string
 @param b       string& second input string
 @param result  string& longest common subsequence
                        between a and b
 */
int Subsequence::lcs(std::string& a, std::string& b, std::string& result)
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
		       std::string a1 = a.substr(1, a.size()-1);
        		std::string b1 = b.substr(1, b.size()-1);

			retVal = 1 + lcs(a1,b1,res);
			result += a[0] + res;
		}
		// other statements of the naïve algorithm
		else
		{
			// obtaining max value of the two strings
			std::string res1, res2;
			std::string a2 = a.substr(1, a.size()-1);
        		std::string b2 = b.substr(1, b.size()-1);


			retVal = std::max(lcs(a2,b,res1),lcs(a,b2,res2));

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
void testLCS(std::string x, std::string y)
{
std::string result;

Subsequence s1;
s1.call = 0;

Subsequence s2;
s2.call = 0;

time_t t1 = time(0); 

s1.lcs(x,y,result);
std::cout<<"LCS of "<< x <<"  &  " << y <<" is : "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive calls :" <<s1.call<<endl;
result.clear();


s2.lcs(y,x,result);
std::cout<<"LCS of "<< y <<"  &  " << x <<" is : "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive calls :" <<s2.call<<endl;


time_t t2 = time(0); 
std::cout <<"Total Time Taken :"<< t2 - t1 <<endl;

std::cout<<endl<<endl;
}

/**
 Main Functiion
 @param a       length of command line argument
 @param b       command line argument
 @param result  Used to enter into the program
 */
int main(int argc, char * const argv[])
{
std::string x="ABCDBAGZCDCAMPSAOP";
std::string y="BCADCGZZCDCALMPSOP";
testLCS( x,  y);

x="ABCDBAGZCDCAMPC";
y="BCADCGZZCDCALMC";
testLCS( x,  y);


x="ABCDBAGZCDCAM";
y="BCADCGZZCDCAL";
testLCS( x,  y);


x="ABCDBAGZCDCA";
y="BCADCGZZCDCA";
testLCS( x,  y);

x="ABCDBAGZCDC";
y="BCADCGZZCDC";
testLCS( x,  y);

return 0;
}