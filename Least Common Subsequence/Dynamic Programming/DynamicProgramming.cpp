# include "DynamicProgramming.h"

/**
 Function dynamicpLCS function to obtain LCS
 of two strings using Dynamic Programming
 @param a       char* first input string
 @param b       char* second input string
 @return string that is LCS of a, b
 */
std::string DynamicProgramming::lcs( char * a , char * b  )
{
	const int p = strlen(a) + 1;
	const int q = strlen(b) + 1;
	
	int *  p2 = (int*)std::calloc(p * q , sizeof(int)) ;
	int ** p1 = (int**)std::malloc(p * sizeof(int*)) ;

	int *  la	   = (int*) std::calloc(p * q,  sizeof(int));
	int ** lengths = (int**)std::malloc(p * sizeof(int*)) ;
	
	int i = p-1;
	int j = q-1;
	int m = MIN(p,q);
	char * endlcs = (char*)std::malloc(m * sizeof( char));
	std::string result = "";

	for (int i= 0; i < p ; i++)
	{
		p1[i] = p2 + i*q;
	}
	
	for (int i= 0; i < p ; i++)
	{
		lengths[i] = la + i*q;
	}


	for(int i=0; i < p; i++)
    {
        for(int j=0; j < q; j++)
        {
			call++;

			if(i==0 || j==0)
			{
				lengths[i][j] = 0;
			}
            else if(a[i-1]==b[j-1])
			{
				lengths[i][j] = lengths[i-1][j-1]+1;
			}
            else if (p1[i-1][j]>=p1[i][j-1])
			{
				lengths[i][j] = max(lengths[i-1][j],lengths[i][j-1]);
			}
			else
			{
				lengths[i][j] = max(lengths[i-1][j],lengths[i][j-1]);
            }                
        }
	}

	
	char * lcs = endlcs + m ;
	*lcs = NULL;

	for (int k = 0; k < m ; k++)
	{
		endlcs[k] = ' ';
	}

	lcs--;

	while ( (i>0) && (j>0) ) 
	{
		call++;
		if (lengths[i][j] == lengths[i-1][j])
			i--;
		else
			if (lengths[i][j] == lengths[i][j-1])
				j--;
		else 
		{
			*(lcs) = a[i-1];
			result = a[i-1] + result ;
			lcs--;
			i--;
			j--;
		}
	}
	return result;
}


/**
 Function Test LCS of two strings using Memoization
 @param x       string& first input string
 @param y       string& second input string
 @param result  calling LCS function from Subsequence
 ckass and testing result over it
 */
void DynamicProgramming::testLCS(char* x, char* y)
{

call = 0;
time_t t1 = time(0); 

std::cout<<"Dynamic Programming LCS of "<< x <<"  &  " << y <<" is: "<<endl;
std::cout <<lcs(x,y) << std::endl;
std::cout << "Number of Calls :" <<call<<endl;

call = 0;
std::cout<<"Dynamic Programming LCS of "<< y <<"  &  " << x <<" is: "<<endl;
std::cout << lcs(y,x) << std::endl;
std::cout << "Number of Calls :" <<call<<endl;

time_t t2 = time(0); 
std::cout << t2 - t1 <<endl;
std::cout<<endl<<endl;
}

