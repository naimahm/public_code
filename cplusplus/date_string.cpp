/***********************************************************************\
|    Program: DATE_STRING.CPP													|
|    Problem: Write a program that reads a date as a string in the form	|
|    10/19/72 and displays the same date in the form October 19, 1972.	|
|    Make two versions of this program: one that uses C-strings (arrays	|
|    of characters terminated by \0), and one that uses the string 		|
|    class.																|
|    Purpose: String processing											|
|    Author: Naimah Mumin												|
|    Date: Mar 18 2012													|
\***********************************************************************/

#include <iostream>	// cin, cout
#include <string>
using namespace std;



int main()
{
	string s;
	cout << "\nEnter a date in the format mm/dd/yy: ";
	cin >> s;
	
	//get month
	string mon = s.substr(0,2);
	
	//convert string to int for switch statement
	int month_int;
	if(mon[0] != '0') month_int = mon[1] -'0' + 10;
	else month_int = mon[1] -'0';

	switch(month_int)
	{
		case 1:
			mon = "January";
			break;
	
		case 2:
			mon = "February";
			break;
		
		case 3:
			mon = "March";
			break;
		
		case 4:
			mon = "April";
			break;
		
		case 5:
			mon = "May";
			break;
		
		case 6:
			mon = "June";
			break;
		
		case 7:
			mon = "July";
			break;
		
		case 8:
			mon = "August";
			break;
		
		case 9:
			mon = "September";
			break;
		
		case 10:
			mon = "October";
			break;
		
		case 11:
			mon =  "November";
			break;
		
		default:
			mon = "December";
	}


	//get day
	string day = s.substr(3,2);
	
	//get year
	string year = s.substr(6,2);
	
	
	if((year[0] == '1' && year[1] < '3') || (year[0] == '0')) 
	{
		year = "20" + year;
	}
	else
	{
		year = "19" + year;
	}
	
	
	cout << mon << ' ' << day << ", " << year << "\n";
	
	return 0;
}