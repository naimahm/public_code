/***********************************************************************\
|    Program: INDEX.CPP													|
|    Problem: Write a program to copy a given text file into another 	|
|    text file in which the lines are numbered 1,2,3,...				|
|    with the line number at the beginning of each line.				|
|    Purpose: index lines in text file									|
|    Author: Naimah Mumin												|
|    Date: Mar 18 2012													|
\***********************************************************************/

#include <iostream>	// cin, cout
#include <iomanip>
#include <fstream>
using namespace std;


int main()
{
	
	char file[] = "text.txt";
	char fileout[] = "text2.txt";
	string s;
	int n;
	
	
	ifstream IS(file,ios::in);
	if(!IS.is_open()) cout << "can't open file" << endl;	
	ofstream OS(fileout,ios::out);
	n=0;
	while(IS >> s)
	{   
		n++;
		OS << n << ' ' << s << endl;	
	}
	IS.close();
	OS.close();
		
	return 0;
}