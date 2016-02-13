#include "polynomial.h"

using namespace std;

Root Polynomial::calculateRoot(double startPoint)
{
	double prevX, x = startPoint;
	double prevY, y;

	//get first derivative of polynomial
	Polynomial derPoly(getDerivative());

	for(int i=0;i<128;i++)
	{
		//function's value at previous root approximation
		prevY = calcPolyY(x);
		//derivative's value at previous root approximation
		y = derPoly.calcPolyY(x);

		//if previously defined function value is equal to 0 - solution has been found
		//(approximately - less than DBL_EPSILON of difference)
		if(abs(y) < DBL_EPSILON)
		{
			cout << "Wrong starting point" << endl;
			break;
		}

		//define previous point as current one
		prevX = x;
		//define new current point as defined in Newton's method
		x = x - prevY/y;

		//if difference between points is negligible - solution has been found
		if(abs(x-prevX) < DBL_EPSILON)
			break;
	}

	return Root(x,calcPolyY(x));
}

Polynomial Polynomial::getDerivative()
{
	list<Term> derTerms;

	for(list<Term>::iterator it=terms.begin();it != terms.end();it++)
	{
		//no need to get derivative of term with power=0 - it will be equal to 0
		if(it->getPower()!=0)
			derTerms.push_back(it->derivativeGet());
	}

	return Polynomial(derTerms);
}

double Polynomial::calcPolyY(double x)
{
	double y = 0;

	for(list<Term>::iterator it=terms.begin();it != terms.end();it++)
	{
		y += it->getCoeff()*pow(x, it->getPower());
	}

	return y;
}

list<Term> Polynomial::getTerms() const
{
	return terms;
}

Polynomial::Polynomial(list<Term> polyTerms)
{
	terms = polyTerms;
}

ostream & operator <<(ostream &ss, const Polynomial &poly)
{
	ss << poly.getPolyString();

	return ss;
}

string Polynomial::getPolyString() const
{
	string polyString;

	for(list<Term>::const_iterator it=terms.begin();it != terms.end();it++)
	{
		char signedCoeff[6];
		char coeff[12];

		/* 3 possibilities of sign (+/-):
		* - coeff is negative - don't add sign (it is included in coeff value)
		* - given term is the first term - don't add sign
		* - other terms - add + sign
		*/
		if(it==terms.begin() || it->getCoeff()<0)
			snprintf(signedCoeff, 6, "%g", it->getCoeff());
		else
			snprintf(signedCoeff, 6, "+%g", it->getCoeff());

		/* 3 possibilities of writing variable's power
		 * - power = 0 - don't write variable x (ex. 4)
		 * - power = 1 - write only 'x' (ex. 3x)
		 * - power > 1 - write variable x with power value (ex. 3x^2)
		 */
		if(it->getPower()==0)
			snprintf(coeff, 12, "%s", signedCoeff);
		else if(it->getPower()==1)
			snprintf(coeff, 12, "%sx", signedCoeff);
		else
			snprintf(coeff, 12, "%sx^%d", signedCoeff, it->getPower());

		//append term string to polynomial string
		polyString.append(coeff);
	}


	return polyString;
}

