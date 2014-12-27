#include <iostream>
#include <string.h>

using namespace std;

void swap( char *s, char *e )
{
   char temp;

   temp = *s;
   *s = *e;
   *e = temp;
}

void reverse( char *s, char *e )
{
   char *a = s;
   char *b = e;

   for ( ; a<b; a++, b--)
   {
      swap( a, b );
   }
}

char *lookForSpace( char *s, char *e )
{
   char *rval = s;
   while ( rval <= e )
   {
      if (*rval == ' ')
         break;
      rval++;
   }

   return rval;
}

int main()
{
   char str[256];
   char *start, *end, *startOfWord, *endOfWord;

   cin.getline( str, 256 );

   // Set our start and end pointers
   start = str;
   end = str + (strlen(str)-1);

   // First, reverse the entire string
   reverse( start, end );


   // Now, iterate through the list again and reverse the contents of the
   // words.  Send two new pointers: start of word and end of word; we will
   // use these to reverse individual words
   startOfWord = start;
   endOfWord = lookForSpace( start, end ) - 1;

   for ( ; startOfWord < end; 
         startOfWord = endOfWord + 2, 
         endOfWord = lookForSpace( startOfWord, end )-1)
   {
      reverse( startOfWord, endOfWord );
   }

   cout << str << endl;
   
   
}
