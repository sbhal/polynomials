#include "PolytermsP.h"
#include <math.h>
#include <sstream>


Poly::Poly()
{
	head = current = NULL;
}

Poly::Poly(const Poly & original)
{
	struct polyTerm * orig_pos = original.head;
	while (orig_pos != NULL) {
		newTerm(orig_pos->exponent, orig_pos->coef);
		orig_pos = orig_pos->next;
	}
}

Poly::~Poly()
{
	struct polyTerm * pos = head, *prev;
	while (pos != NULL) {
		prev = pos;
		pos = pos->next;
		free(prev);
	}
	head = current = NULL;
}

coefType Poly::getCoef(exponentType exponent)
{
	struct polyTerm * pos = findTerm(exponent);
	if (pos != NULL) {
		if (pos->exponent == exponent)
			return pos->coef;
	}
	return (coefType)0;
}

void Poly::setCoef(exponentType exponent, coefType coef)
{
	struct polyTerm * pos = findTerm(exponent);
	if (pos != NULL) {
		if (pos->exponent == exponent)
			pos->coef = coef;
	}
}

void Poly::newTerm(exponentType exponent, coefType coef)
{
	struct polyTerm * newNode = new struct polyTerm;
	newNode->exponent = exponent;
	newNode->coef = coef;
	newNode->next = NULL;
	if (head == NULL) {
		current = head = newNode;
		newNode->next = NULL;
	}
	else {
		//assuming current points to last node
		current->next = newNode;
		current = current->next;
		newNode->next = NULL;
	}
}

exponentType Poly::findDegree()
{
	struct polyTerm * pos = head;
	exponentType maxExp = 0;
	while (pos != NULL) {
		maxExp = (pos->exponent < maxExp) ? maxExp : pos->exponent;
		pos = pos->next;
	}
	return maxExp;
}

string Poly::getString(int number)
{
	struct polyTerm * pos = head;
	std::stringstream ss;

	ss << "poly(" << number << ") = ";
	while (pos != NULL) {
		ss << pos->coef;

		if (pos->exponent == 1)
			ss << "X";
		else if (pos->exponent == 0)
			ss << "";
		else {
			ss << "X^";
			ss << pos->exponent;
		}

		if (pos != current)
			ss << " + ";

		pos = pos->next;
	}

	return ss.str();

}
