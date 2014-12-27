# include "Memoization.h"

using namespace std;


/**
 Function Lcs memoized function to obtain LCS
 of two strings
 @param a       string& first input string
 @param b       string& second input string
 @param result  string& longest common subsequence
                        between a and b
 @param table  table& map of string, string as key 
						and string as value
 */
int Memoization::lcs(std::string& a, std::string& b, std::string& result, std::map<std::pair<std::string,std::string>,std::string> &table )
{
	int retVal(0);
	call++;

	//making pair of both input LCS
	std::pair<std::string, std::string> p1(a,b);
	
	// this is the "heart" of the recursion where
	// the comparisons and outputs will take place
	if(a.size() > 1 && b.size() > 1)
	{
		// Base case when the two first elements
		// are equal
		if(a[0] == b[0])
		{
			std::string res;

			//If table has solution
			if(table.find(p1) == table.end())
			{	
				retVal = 1 + lcs(a.substr(1,a.size()-1),b.substr(1,b.size()-1),res,table);
				result += a[0] + res;
				table.insert(std::make_pair(p1,result));
			}

			else
			{
				result +=table[p1] + res;
			}
		}

		// other statements of the naïve algorithm
		else
		{
			//If the table does not have solution
			if(table.find(p1) == table.end())
			{
		
				// obtaining max value of the two strings
				std::string res1, res2;
				std::string suba = a.substr(1,a.size()-1);
				std::string subb = b.substr(1,a.size()-1);

				retVal = std::max(lcs(suba,b,res1,table),lcs(a,subb,res2,table));

				// concatenating the result
				if(res1.size() > res2.size()) 
					result +=res1;
				else 
					result +=res2;

				table.insert(std::make_pair(p1,result));
				
			}

			else
			{
				result += table[p1];
			}
		}
	}
	// This is the base case: both strings are of unit size and are equal
	else if ( a.size() && b.size() && a[0] == b[0])
	{
		//If table is does not have solution
		if(table.find(p1) == table.end())
		{
			table.insert(std::make_pair(p1,result));
			result += a[0]; 
		}

		else
		{
			result += table[p1];
		}

		retVal = 1;
	}
	return retVal;
}



/**
 Function Test LCS of two strings using Memoization
 @param x       string& first input string
 @param y       string& second input string
 @param result  calling LCS function from Subsequence
 ckass and testing result over it
 */
void Memoization::testLCS(std::string x, std::string y)
{


call = 0;
std::string result;
std::map<std::pair<std::string,std::string>,std::string> table1;
time_t t1 = time(0); 


lcs(x,y,result,table1) ;
std::cout<<"Memoization LCS of "<< x <<"  &  " << y <<" is: "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive Calls :" <<call<<endl;
result.clear();


call = 0;

std::map<std::pair<std::string,std::string>,std::string> table2;
lcs(y,x,result,table2);
std::cout<<"Memoization LCS of "<< y <<"  &  " << x <<" is: "<<endl;
std::cout << result << std::endl;
std::cout << "Recursive Calls :" <<call<<endl;

time_t t2 = time(0); 
std::cout << t2 - t1 <<endl;
std::cout<<endl<<endl;
}

