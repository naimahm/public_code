/***********************************************************************\
|    Program: DATE.CPP													|
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
#include <cstring>	// strcpy, strcat
using namespace std;



int main()
{
	char s[9];
	cout << "\nEnter a date in the format mm/dd/yy: ";
	cin.getline(s,9);
	
	//get month
	char mon[2];
	mon[0] = s[0];
	mon[1] = s[1];
	
	char month[12];
	//convert char month to int for switch statement
	int month_int;
	if(mon[0] != '0') month_int = mon[1] -'0' + 10;
	else month_int = mon[1] -'0';

	switch(month_int)
	{
		case 1:
			strcpy(month,"January");
			break;
	
		case 2:
			strcpy(month,"February");
			break;
		
		case 3:
			strcpy(month,"March");
			break;
		
		case 4:
			strcpy(month,"April");
			break;
		
		case 5:
			strcpy(month,"May");
			break;
		
		case 6:
			strcpy(month,"June");
			break;
		
		case 7:
			strcpy(month,"July");
			break;
		
		case 8:
			strcpy(month,"August");
			break;
		
		case 9:
			strcpy(month,"September");
			break;
		
		case 10:
			strcpy(month,"October");
			break;
		
		case 11:
			strcpy(month, "November");
			break;
		
		default:
			strcpy(month, "December");
	}


	//get day
	char day[2];
	day[0] = s[3];
	day[1] = s[4];
	
	//get year
	char year[2];
	year[0] = s[6];
	year[1] = s[7];
	
	
	if((year[0] == '1' && year[1] < '3') || (year[0] == '0')) 
	{
		char year_long[] = "20";
		strcat(year_long, year);
		strcpy(year, year_long);
	}
	else
	{
		char year_long[] = "19";
		strcat(year_long, year);
		strcpy(year, year_long);
	}
	
	
	cout << month << ' ' << day << ", " << year << "\n";
	
	return 0;
}