#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include <sys/types.h>
#include<time.h>
#include<ctime>
#include<map>
#include<stdlib.h>
#include<cstdlib>
#include<string.h>

using namespace std;

#define MAX(A,B) (((A)>(B))? (A) : (B))
#define MIN(A,B) (((A)>(B))? (B) : (A))

class DynamicProgramming
{
public :

	int call;

	std::string lcs( char * a , char * b  );

	void testLCS(char* x, char* y);

};