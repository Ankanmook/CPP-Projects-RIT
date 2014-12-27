Problem
This program takes an arbitrary string of up to 255 characters input on STDIN (cin). There is no user prompt.
The program does an in-place reversal of the words in the string. That is, if "Hello, World!" was input, the 
output would be "World! Hello," This program does NOT use any C++ string manipulators nor makes a copy of the string. 
I allocate a buffer to store the string (size 255 bytes), and pointers and exactly one character on the stack to implement
a swap function. 

Example
Input: Hello, World!
Output: World! Hello,
