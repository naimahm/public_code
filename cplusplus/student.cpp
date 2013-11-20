/****************************************************************\
| Program: student.cpp											
| Problem: Create the class student that includes the following 
| information about student: name,age and gpa.
| Purpose: HW #6
| Method : 
|			
| Author : Naimah Mumin
| Date : 4/24/13
\****************************************************************/

#include <iostream>	// cin, cout
#include <fstream>	// ofstream, ifstream
#include <iomanip>

using namespace std;

#define W setw

class student
{
	private:
		char first[20], mi[20], last[20];
		int age;
		double gpa;
	public:
		student();					// Constructor
		int read();
		void show();				// show student data
		void writefile(ofstream &);			// write student to file
		double getgpa();			// get student gpa
		int readfile(ifstream &);	// read student from file
};

student::student()
{	
	age = 0;
	gpa = 0.;
}


int student::read()	
{
	cout << "Please enter first, middle, and last name, age and GPA separated by spaces "
	<< ",press CTRL-D to terminate\n";
	while(!cin.eof())
		cin >> first >> mi >> last >> age >> gpa;
	
	return 0;
}
void student::show()
{
	cout << W(10) << first << W(4) << mi << W(15) << last
		 << W(3) << age	<< W(6) << gpa 
		 << endl;
}
void student::writefile(ofstream & OS)
{
	OS << first << " " << mi << " " << last << "\t " << age << "\t" << gpa;
}
double student::getgpa()
{
	return gpa;
}
int student::readfile(ifstream & IS)	//return 1/0
{	
	IS >> first >> mi >> last >> age >> gpa;
	return !IS.eof();
}
int main() {
	char filename[] = "student.dat";
	ifstream IS(filename,ios::in);
	ofstream OS(filename,ios::out);
	student a;
	
	a.read();
	a.show();
	
	a.writefile(OS);	
	OS.close();
	
	a.getgpa();
	
	a.readfile(IS);
	IS.close();
	
		
	return 0;
}
