/***********************************************************************\
|    Program: KEYCOUNT.CPP												|
|    Problem: Write a program that reads from the keyboard a line of 	|
|    text and then computes and displays the number of upper case 		|
|    letters, lower case letters and digits in the line					|
|    Purpose: Count keyboard entry										|
|    Author: Naimah Mumin												|
|    Date: Mar 18 2012													|
\***********************************************************************/

#include <iostream>	// cin, cout
#include <string>
using namespace std;


int main()
{
	string s;
	cout << "\nEnter a line of text(digits and characters " 
	     << "to find sum of upper case, lower case and digits: ";
	     
	getline(cin, s);
	
	int i;
	int upsum = 0;
	int lowsum = 0;
	int digitsum = 0;
	
	//find the sum of digits
	for(i = 0; s[i]; i++)	//s[i] != '\0'
		if('0' <= s[i] && s[i]<='9') digitsum++;
	
	for(i = 0; s[i]; i++)
		if('A'<=s[i] && s[i]<='Z') upsum++;
		
	for(i=0; s[i]; i++) 
		if('a'<=s[i] && s[i]<='z') lowsum++;
	
	cout << "\nNumber of digits = " << digitsum << endl;
	cout << "Number of upper case = " << upsum << endl;
	cout << "Number of lower case = " << lowsum << endl;
	
	return 0;
}