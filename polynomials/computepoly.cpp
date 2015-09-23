#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include "PolytermsP.h"

using namespace std;

int main(int argc, char *argv[]) {
	coefType coef;
	exponentType exponent;

	if (argc != 3) {
		cout << "usage: " << argv[0] << " <input filename> <output filename>" << endl;
		return 0;
	}

	cout << argv[1] << "and " << argv[2] << endl;
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	string curr_line;
	int polycount = 0;

	if (!input.is_open()) {
		cout << "Couldn't open file" << endl;
		return 0;
	}

	Poly outputClass;
	try {
		while (std::getline(input, curr_line)) {
			cout << "----" << curr_line << "and compare output is " << curr_line.compare("XXX") << endl;
			if (curr_line.compare("XXX") == 0) {
				//display current polynomial
				output << outputClass.getString(++polycount) << endl;

				//delete and create new class
				outputClass.~Poly();
				//Poly outputClass;
				continue;
			}
			stringstream(curr_line) >>  coef >> exponent;
			//cout << "exponenet read is "<<exponent<<"  coef read is "<< coef << endl;
			outputClass.newTerm(exponent, coef);
			// Check for negative exponent or zero coefficient   
			//if (exponent < 0) throw(1);
			//if (coef == 0) throw(2);
		}
		output << outputClass.getString(++polycount);
	}
	catch (int error)
	{
		if (error == 1)
		{
			cout << "ERROR: Input exponent is negative!" << endl;
		}
		if (error == 2)
		{
			cout << "ERROR: Input coefficient is zero!" << endl;
		}
	}
	system("pause");
}