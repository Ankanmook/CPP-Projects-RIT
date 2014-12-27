/**
* Homework 5
* Word Frequency with file streams
*
*
* main.cpp
*
* Program will read in a text file and
* output the frequency of each work in the file
*
* ! . , ? ; : - | ' 
* 
* Errors will be reported to STDERR
*
* Author: Ankan Mookherjee(axm3244)
* Date : 16th Feb 2013
*	
*/

#include<iostream>
#include<fstream>
#include<algorithm>
#include<stdio.h>
#include<cstdlib>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<string.h>
#include <libgen.h>

using namespace std;


/**
 * Count the Word Function
 *
 * Checks if the map already contains the inputted key value.
 * If key is already present, value in map is incremented by
 * one. Finally prints the output.
 *
 *
 * @param key - Set of unique words and vector of all the words
 *
 * @return void
 *
 */
void countingWord(set<string> uniqueWords,vector<string> completestring){

	int wordcount  = 0;
	set<string> :: iterator setIter;
	map<string, int> wordFrequencyMap;
	map<string,int> :: iterator mapIter;
	
	//Counting Frequency of words
	for(setIter= uniqueWords.begin(); setIter != uniqueWords.end(); ++setIter){
		wordcount = count(completestring.begin(),completestring.end(), *setIter);
		wordFrequencyMap[*setIter] = wordcount;
	}

	// output key-value pairs from Frequency of Word map
	for (mapIter = wordFrequencyMap.begin(); mapIter!= wordFrequencyMap.end(); ++mapIter){
		std::cout  << mapIter->first << ": " << mapIter->second <<std::endl;
	}

}


/**
 * Read Function 
 *
 * Removes the punctuations from given string to pass
 * string value, after removing punctuations to 
 * coutingWord function 
 *
 * @param Filename to extract punctuations from
 *
 * @return void
 */

void read(char* filename){
	
	ifstream input;
	std::set<string> uniqueWords;
	std::vector<string> completestring;
	
	//delimiter puctuations
	char* deletedPunctuation = "!.,?;:-|'";
	
	// open stream using command line argument
	input.open(filename);

	//Reading from input
	while(input){
		string word;
		input >> word;

		//Eliminating Punctuations
		for(int i =0; i<strlen(deletedPunctuation); ++i){
			word.erase( remove(word.begin(), word.end(), deletedPunctuation[i]),word.end());
		}

		completestring.push_back(word);
		uniqueWords.insert(word);
	}

	//Erasing empty characters
	uniqueWords.erase("");

	countingWord(uniqueWords,completestring);

	input.close();

}

/**
 * Main function
 *
 * Calls methods for getting 
 * frequency of words from file
 *
 * @param Command Line Arguments
 *
 * @return Type Void
 */

int main(int argc, char* argv[])
{
	ifstream input;

	// confirm that file was specified correctly
	if ( (argc==1) || (argc>2) ) {
		std::cerr << "Usage:" << endl << endl << "  "<<basename(argv[0]) << " "
			   << "filename" << endl << endl;
		exit(-1);
	}


	// open stream using command line argument
	input.open(argv[1]);

	// if file not found then print error and quit
	if(input.fail()){
		std::cerr << basename(argv[0]) 
			   << ": nofile: No such file"<< endl;
		exit(-1);
	}

	input.close();

	// Read from input
	read(argv[1]);

	return 0;
}