/****************************************************************\
 | Program: number_guess.cpp											
 | Problem: Create a guessing game, of numbers from 1 - 99
 | Method : A random number between 1 and 99 is generated then user games.
 |			then the roles are switched 
 | Author : Naimah Mumin
 | Date : 4/18/13
 \****************************************************************/
#include <math.h>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

double urn(void) {return double(rand())/double(RAND_MAX);}

double	f(double x) {
	return exp(x);
}

double montecarlo(int n, int N)
{
	int i;	
	double x, y, integral;
	for(i =0; i < n; i++)
	{
		x = urn(); y=urn();
		if(y <= f(x)) N++;
	}
	
	integral = double(N)/double(n);
	
	return integral;
}

double trapezoid(double x0, double xn, int n)
{
	double x, h, A;	//h is height, A is area
	int i;		
	
	h= (xn - x0)/n;			//n is number of intervals
	
	A = (f(x0) + f(xn))/2.;
	for(i = 1; i < n; i++)
	{
		x = x0 + i*h;
		A += f(x);
	}
	
	A*=h;
	
	return A;
}


int main()
{
	double x0 = 0., xn = 1., montIntegral, trapIntegral, error, e;
	int n=10000000, N=0;	// n is number of randomly generated points, N is points under f(x)
	
	
	srand(time(NULL));
	
	trapIntegral = trapezoid(x0, xn, n);
	montIntegral = montecarlo(n, N);
	
	error = (montIntegral - trapIntegral)/trapIntegral;
	
	cout << "\nIntegral of e^x inside [0.,1.]\n\n"
	<< "Trapezoid result    = " << trapIntegral
	<< "\nMonte Carlo result = " << montIntegral
	<< "\nRelative error [%] = " << error
	<< "\n\nERROR ANALYSIS\n\n"
	<< setw(10) << "N" << setw(11) << "Integral"
	<< setw(12) << "Error [%]" 
	<< "\n----------------------------------\n";
	
	for(n=100; n<100000000; n*=100)
	{
		N=0; srand(time(NULL));
		montIntegral = montecarlo(n, N);
		trapIntegral = trapezoid(x0, xn, n);
		error = 100.*(montIntegral - trapIntegral)/trapIntegral;
		cout << setw(10) << n << setw(11) << montIntegral << setw(12) << error << "\n";
	}
	
	e = montIntegral + 1;	
	cout << "\ne computed from Monte Carlo: " << e;

	e = trapIntegral + 1;	
	cout << "\ne computed from Trapezoid: " << e;
	
	return 0;	
}