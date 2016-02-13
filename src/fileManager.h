#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include "polynomial.h"

class FileManager
{
public:
    /**
     * @brief load polynomial from specified file
     * @param fileName name of the file where polynomial is stored
     * @return pointer to newly loaded Polynomial
     */
    Polynomial* readPoly(std::string fileName);

    /**
     * @brief save polynomial to specified file
     * @param polynomial pointer of Polynomial to save
     * @param fileName name of file where Polynomial will be saved
     * @return true on success, false otherwise
     */
    bool savePoly(Polynomial *polynomial, std::string fileName);

    /**
     * @brief parse given string to create Polynomial object
     * @param string representation of polynomial
     * @return pointer to newly created Polynomial
     */
    Polynomial* polyGetFromString(std::string polyString);
};

#endif /* FILE_MANAGER_H_ */
