#pragma once
#include <iostream>  
#include <iomanip>  
#include <stdlib.h>  

using namespace std;

// Here the user can specify a different type;  
// Your implementation should work for double, float, and int  
typedef int coefType;
typedef int exponentType;

struct polyTerm;

class Poly {
public:

	// Constructor: create an empty polynomial linked list.  
	Poly();

	// Copy constructor: create a deep copy  
	Poly(const Poly& original);

	// Destructor: deallocate memory that was allocated dynamically  
	~Poly();

	// Get corresponding coefficient for an exponent      
	coefType getCoef(exponentType exponent);
	// Set the coefficient for an exponent  
	void setCoef(exponentType exponent, coefType coef);


	// Insert a new term. This is placed directly after the current // item.         
	void newTerm(exponentType exponent, coefType coef);

	// Find the highest exponent in the polynomial  
	exponentType findDegree();

	string getString(int number);


private:

	// List node, called polyTerm for Polynomial Term      
	struct polyTerm
	{
		coefType coef;
		exponentType exponent;
		polyTerm *next;
	};


	// Points to the first term      
	polyTerm *head;

	// Points to the current term – the tail end term of the linked list   
	polyTerm *current;

	// Find the term for an exponent, returns a pointer to the term.  
	// If there is no term with that exponent, make a new term and set 
	// the coefficient to zero.
	struct polyTerm* findTerm(exponentType exponent)
	{
		struct polyTerm * pos = head;
		while (pos != NULL) {
			if (pos->exponent == exponent)
				return pos;
			pos = pos->next;
		}

		//add new term when unable to find
		newTerm(exponent, (coefType)0);
		return current;
	}

};
