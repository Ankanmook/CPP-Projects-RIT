Assignment

My program will perform simple arithmetic (addition and subtraction) on user entered time values. The program should be able to take arbitrarily long input strings and support daisy chained expressions. Expressions should always be evaluated from left-to-right, and you do not need to support parenthesis. Input will be in the format hh:mm, where hh represents hours, and mm represent minutes. Several templates are provided to you:
•	Time.h

•	Time.cpp

•	main.cpp

I have implemented a function in Time.cpp called setTime. This function will take a string in the format hh:mm and convert it to seconds. Thus, if 1:25 was passed in, seconds would be set to 5100 (1*3600+25*60). I have also handled negative time, and it does not crash my program. In main.cpp, I have implement the code to loop through the input string, look for +, - and time. This was a good place to use a switch/case statement and for loops. I have employed the use of functions in your main.cpp to make the code easier to read.
The program should continue prompting the user for input until an end-of-file is read (CTRL-D). The code to handle reading input is there in main.cpp.

Example
1:00 + 0:30 + 0:45 - 0:15 - 0:45 + 0:10

1:25

:30 + :15

0:45

