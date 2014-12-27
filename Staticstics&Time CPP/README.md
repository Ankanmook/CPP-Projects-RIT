Assignment

This is a simple software program that takes race times as inputs and outputs key statics about those times.
These include the minimum (winning) time, the maximum time, the mean, median and modes of the times.
I have written a templatized 'Statistics' class with the following public functions, where T is the template type:

•	T mean()

•	T median()

•	set<T> mode()

•	T min()

•	T max()

•	void push( T t )

•	clear()

I have implemented Time.cpp and Time.h with the operators to making my Statistics implementation work.

Input Format

Times will be entered on standard in (stdin) in the format HH:MM:SS, where HH is hours, MM is minutes and SS is seconds. The user does not need to enter all the fields. For instance, if "1:20" was specified, this would represent 1 hour and 20 minutes. 

Return Values, Errors and Error Handling

My program checks for invalid time format, where an invalid time is any number less than zero or an MM or SS field greater than 60. If it encounters an error, it throws a runtime_error exception with the description "Invalid time entry".
If the statistics functions does not have enough data to do their calculations, they should throw underflow_error exceptions with the description "Not enough data". If all values in the input are unique, mode() returns an empty set. Input is terminated with a CTRL-D

Example

Given the following input:

   3:15:52
   
   2:6:47
   
   5:50:33
   
   2:49:19
   
   1:44:43
   
   3:50:30
   
   2:31:55
   
   1:6:14
   
   4:37:23
   
   1:59:55
   

my program prints out the following output:
   
   min: 1:06:14
   
   max: 5:50:33
   
   mean: 2:59:19
   
   median: 2:40:37
   
   

