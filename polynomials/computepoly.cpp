#include <iostream>
#include <fstream>
#include <sstream>  
#include <string>
#include "PolytermsP.h"

using namespace std;

void main(int argc, char *argv[]) {
	coefType coef;
	exponentType exponent;

	if (argc != 3) {
		cout << "usage: " << argv[0] << " <input filename> <output filename>" << endl;
		return;
	}
	ifstream input(argv[1]);
	ofstream output(argv[2]);

	if (!input.is_open()) {
		cout << "Couldn't open file" << endl;
		return;
	}
	
	char x;
	while (input.get(x)) {
		cout << x;
	}

	try {
		while (input >> coef >> exponent) {
			// Check for negative exponent or zero coefficient   
			if (exponent < 0) throw(1);
			if (coef == 0) throw(2);
		}
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