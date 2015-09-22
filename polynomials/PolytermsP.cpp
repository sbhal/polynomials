#include "PolytermsP.h"
#include <math.h>

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
	if(pos != NULL) {
		if (pos->exponent == exponent)
			pos->coef = coef;
	}
}

void Poly::newTerm(exponentType exponent, coefType coef)
{
	struct polyTerm * newNode = new struct polyTerm;
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
