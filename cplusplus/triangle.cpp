/****************************************************************\
| Program: triangle.cpp											
| Problem: Create the class student that includes the following information about student: name,
age and gpa.
| Purpose: HW #6
| Method : 
|			
| Author : Naimah Mumin
| Date : 4/24/13
\****************************************************************/

#include <iostream>	// cin, cout
#include <fstream>	// ofstream, ifstream
#include <cstring>  

using namespace std;
class triangle{
	private:
		int A, B, C;
	public:
		triangle()
		{
			A=B=C=0;
		}
		void show()
		{
			cout << "Side A: " << A << ", Side B: " << B
				<< ", Side C: " << C << endl;
		}
		bool isequilateral(triangle tri)
		{
			if(((A+B)<C) || ((B+C) < A) || ((C+A) < B)) return false;
			if((A==B) || (B==C) || (C==A)) return true;
			return false;
		}
        int readfile(ifstream &);
};


int triangle::readfile(ifstream & IS)
{	
    
    IS >> A >> B >> C;
    return !IS.eof();			
}


int main() {
    ifstream IS("triangle.dat",ios::in);
    triangle tri;
    
    
	while(!IS.eof())
	{   
        tri.readfile(IS);
        if(tri.isequilateral(tri))
			tri.show(); 
    }
    
	return 0;
}