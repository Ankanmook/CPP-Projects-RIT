#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include <vector>
#include <set>
#include <algorithm>
#include <stdexcept>
#include <numeric>

template< class T >
class Statistics
{
public:

   /*add a 'value_type' typedef */
   typedef T value_type;
   
   /**
    * Calculate the mean (average) of the data entered.
    *
    * @return the mean of the data pushed into our data set
    */
   T mean()
   {
	if (elements.empty())
	{
            throw std::runtime_error("Empty data"); 
	}
	T mean(0) ;
	T cumulative = std::accumulate(elements.begin(),elements.end(), mean);
       
       mean = cumulative/elements.size(); 

       return mean;        
   }

   /**
    * Calculate the median (middle element when the data is sorted)
    *
    * @return the mode of the data pushed into our data set
    */
   T median()
   {
	   T median;
	   int size = elements.size();

	   if (elements.empty())
	   {
            throw std::runtime_error("Empty data"); 
	   }
	   
	   sort(elements.begin(), elements.end());

	   if( size % 2 == 1 )
		   return elements[size/2];
        else
		{
            return ( elements[size/2] + elements[(size/2)-1] ) / 2;
		}
   }

   /**
    * Calculate the mode (most common element). 
    *
    * @return a set of the most common elements.  This can be the empty set if
    * there is a uniform distribution
    */
   std::set<T> mode()
   {
	    if(elements.empty())
	   {
		   throw std::runtime_error("Empty data");
	   }
	   std::set<T> mode;
	   std::vector<int> counter;
	   int count = 0;
	   
	   /* Filling the elements of counter vector sequentially with occurence
	   of the exact same elements */
	   for(int i=0; i < elements.size(); i++)
	   {
		   count = std::count(elements.begin(),elements.end(),elements[i]);
		   counter.push_back(count);
	   }

	   /* Counting the maximumm element in vector of int */
	   int maxcount = *max_element(counter.begin(), counter.end());

	   /* In case of unform distribution */
	   if (maxcount ==1)
		   return mode;

	   /* Inserting the mode elements in the set */
	   for(int i=0; i<counter.size(); i++)
	   {
		   if(counter[i]== maxcount)
		   {
			   mode.insert(elements[i]);
		   }
	   }

	   return mode;

   }

   /**
    * Get the value of the smallest element
    *
    * @return the minimum value of the data pushed in 
    */
   T min()
   {
	   if (elements.empty()) {
            throw std::underflow_error("Empty data");
        }
        // get the minimum time in the container, uses operator<
        return *min_element( elements.begin(), elements.end());
        
   }

   /**
    * Get the value of the largest element
    *
    * @return the maximum value of the data pushed in 
    */
   T max()
   {
	   if (elements.empty()) {
            throw std::underflow_error("Empty data");
        }
        // get the minimum time in the container, uses operator<
        return *max_element( elements.begin(), elements.end());
        
   }

   /**
    * Add an element to our data set
    *
    * @param t Element to add to our data
    */
   void push( T t )
   {
	   elements.push_back(t);
   }

   /**
    * Removes all elements from the data
    */
   void clear()
   {
	   elements.clear();
   }

private:
	
    std::vector<T> elements;

};
#endif // _STATISTICS_H_
