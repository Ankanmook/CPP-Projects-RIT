/* 
 * Program to check whether values of elements 
 * in one list are subset of values in second list
 * main.cpp
 * Version : 1.0
 * Author : Ankan mookherjee
*/

// Referencing library and header files for pre-processing

#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>


using namespace std;

/*
 * Main Function
 * Program execution begins here
 * @param args[] takes command line arguments
 * @return returns int
 */

int main(){

//Declaring Variables
string input = "";
int num;
int size1, size2;
vector<int> Intdata;
vector<int> Intdata2;
bool result = true;

std::cout<<"List 1 size :";
std::getline(cin,input);


std::istringstream sizeofdata1(input);
while(sizeofdata1>>size1){
}


std::cout<<"List 1 data :";
std::getline(cin,input);

std::istringstream sourceofdata1(input);
while(sourceofdata1>>num){
	Intdata.push_back(num);
}


std::cout<<"List 2 size :";
std::getline(cin,input);


std::istringstream sizeofdata2(input);
while(sizeofdata2>>size2){
}


std::cout<<"List 2 data :";
std::getline(cin,input);

std::istringstream sourceofdata2(input);
while(sourceofdata2>>num){
	Intdata2.push_back(num);
}

//Sorting the Intdata in the order of the elements from min to max
sort(Intdata.begin(),Intdata.end()); 
//Removing the dupilcate elements in Intdata
Intdata.erase(unique(Intdata.begin(),Intdata.end()),Intdata.end());

//Sorting the Intdata2 in the order of the elements from min to max
sort(Intdata2.begin(),Intdata2.end());

vector<int>::iterator it;
vector<int> v(Intdata.size());

//Doing set intersection of Intdata and Intdata2
it = set_intersection(Intdata.begin(),Intdata.end(),Intdata2.begin(),Intdata2.end(),v.begin());

//checking whether the intersected set is equilvalent to Intdata
if(Intdata == v)
	cout<<"TRUE"<<endl;

else
	cout<<"FALSE"<<endl;


return 0;
}
