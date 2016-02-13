#ifndef ROOT_H_
#define ROOT_H_

class Root
{
public:
    /**
     * @brief constructor
     * @param x root of function
     * @param y value of function at root
     */
    Root(double x, double y);

    /**
     * @brief get root of function
     * @return root of function
     */
    double getX();

    /**
     * @brief get value of function at root
     * @return value of function at root
     */
    double getY();
private:
    double x;
    double y;
};



#endif /* ROOT_H_ */
