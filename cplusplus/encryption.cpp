/****************************************************************\
| Program: encryption.cpp											
| Problem: Create a cryptography program
| Method : Get input and output file from user, then use key to 
|	generate seed
| Author : Naimah Mumin
| Date : 5/12/13
\****************************************************************/
#include <iostream>
#include <fstream>
using namespace std;


int filesize(char filename[])
{
	int size = 0;
	ifstream IS(filename, ios::in|ios::ate); // open file to read binary, starting at the end
	size = (int)IS.tellg();		// get the size of the file
	return size;
}

int main()
{	int i, j, size;
	char password[100], infile[40], outfile[40], y;
	unsigned int key;
	char * input, *output;
	
	cout << "\nEnter a key: ";
	cin >> password;
	
	key = 0;
	for(j=0; password[j]; j++)
		key = (key + 3) * password[j];
	cout << "Password: " << key << " (" << hex << key << ")";
	
	
	cout << "\nGive the name of the input file: ";
	cin >> infile;
	cout << "and the output file: ";
	cin >> outfile;
	
	srand(key);
	size = filesize(infile);
	cout << "File size: " << dec << size;	
	input = new char[size];
	output = new char[size];
	
	ifstream IS(infile, ios::in|ios::binary);
	while(!IS.eof())
		IS.read(input, size);
	
	IS.close();
	
	for(i=0; i<size; i++)
		output[i] = input[i];
	
	
	ofstream OS(outfile, ios::out | ios::binary);
	
	for(i = 0; i<size; i++)
		output[i] ^= (rand() >> 8);
	
	
	OS << output;		// Put encrypted version into output file
	
	OS.close();
	
	cout << "\nDo you want to see input and output files? (y/n)";
	cin >> y;
	
	if(y == 'y') 
		cout << "\nInput file:\n" << dec << input << "\noutput file:\n" << output;
		
	input = NULL;
	delete[] input;		//clear memory
	output = NULL;
	delete[] output;		//clear memory

	
	return 0;
}