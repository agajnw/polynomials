#ifndef POLY_MANAGER_H_
#define POLY_MANAGER_H_

#include <iostream>
#include <list>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <float.h>
#include <cstring>
#include "term.h"
#include "root.h"

class Polynomial {
	public:
		/**
		 * @brief calculate root of the polynomial
		 * @param startPoint point where function will begin looking for root
		 * @return Root object containing calculation results
		 */
		Root calculateRoot(double startPoint);

		/**
		 * @brief calculate value of polynomial at x
		 * @param x variable for polynomial calculation
		 * @return value of polynomial at x
		 */
		double calcPolyY(double x);

		/**
		 * @brief get derivative of polynomial
		 * @return new Polynomial that is a derivative of the current one
		 */
		Polynomial getDerivative();

		/**
		 * @brief get terms of polynomial
		 * @return vector of terms
		 */
		std::list<Term> getTerms() const;

		/**
		 * @brief Polynomial constructor
		 * @param terms terms of polynomial
		 */
		Polynomial(std::list<Term> terms);

		/**
		 * @brief get string representation of polynomial
		 */
		std::string getPolyString() const;
	private:
		std::list<Term> terms;
};

std::ostream & operator <<(std::ostream &ss, const Polynomial &poly);

#endif /* POLY_MANAGER_H_ */
