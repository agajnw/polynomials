#ifndef TERMS_H_
#define TERMS_H_


class Term {
	public:
		/**
		 * @brief get derivative of term
		 * @return new Term object that is a derivative of current term
		 */
		Term derivativeGet();

		/**
		 * @brief get coefficient of term
		 * @return coefficient of term
		 */
		double getCoeff() const;

		/**
		 * @brief get power of variable in term
		 * @return power of variable in term
		 */
		int getPower() const;

		/**
		 * @brief constructor
		 * @param vCoeff coefficient of term
		 * @param vPower power of variable in term
		 */
		Term(double vCoeff, int vPower);
	private:
		double coeff;
		int power;
};


#endif /* TERMS_H_ */
