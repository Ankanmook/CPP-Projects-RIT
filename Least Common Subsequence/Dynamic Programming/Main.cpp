#include<iostream>
#include<string>
# include "DynamicProgramming.h"
# include "LinearSpaceQuadTime.h"
# include "Memoization.h"
# include "NaiveRecursive.h"

using namespace std;

int main(int argc, char * const argv[])
{
DynamicProgramming d;
LinearSpaceQuadTime l;
Memoization m;
NaiveRecursive n;

d.testLCS("ABCD","BCDA");
l.testLCS("ABCD","BCDA");
m.testLCS("ABCD","BCDA");
n.testLCS("ABCD","BCDA");

}

