#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include <sys/types.h>
#include<time.h>
#include<ctime>
#include<map>
#include <sstream>


class Memoization
{

public :

	int call ;

	int lcs(std::string& x, std::string& y, std::string& result, std::map<std::pair<std::string,std::string>,std::string> & table );

	void testLCS(std::string x, std::string y);


};
