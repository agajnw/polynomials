#include "term.h"

Term Term::derivativeGet()
{

	return Term(coeff*power, power-1);
}

double Term::getCoeff() const
{
	return coeff;
}

int Term::getPower() const
{
	return power;
}

Term::Term(double vCoeff, int vPower)
{
	coeff = vCoeff;
	power = vPower;
}
