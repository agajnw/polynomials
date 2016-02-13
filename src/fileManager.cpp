#include <fstream>
#include "fileManager.h"

using namespace std;

Polynomial* FileManager::readPoly(string fileName)
{
    fstream file;
    Polynomial *poly = NULL;
    string firstLine;

    //open file with specified name
    file.open(fileName.c_str(), ios::in);
    if(file.good())
    {
        //if file has been opened, get first line with should contain polynomial
        getline(file, firstLine);

        //parse line to get pointer Polynomial object
        poly = polyGetFromString(firstLine);

        //close file when it is no longer needed
        file.close();
    }
    else
        cout << "Error while opening file: " << fileName << endl;

    return poly;
}

bool FileManager::savePoly(Polynomial *polynomial, string fileName)
{
    //get polynomial string representation
    string polyString = polynomial->getPolyString();
    fstream outputFile;

    //open file in which polynomial will be saved
    outputFile.open(fileName.c_str(), ios::out);
    if(outputFile.good())
    {
        //if file has been opened successfully, write polynomial string to it
        outputFile << polyString;

        //close file after it is no longer needed
        outputFile.close();

        return true;
    }

    return false;
}

Polynomial* FileManager::polyGetFromString(string polyString)
{
    vector<char*> polyTermsStrings;
    list<Term> polyTerms;
    int power;

    //char chains used in string parsing
    char *polynom = new char[polyString.length()+1];
    char *copy = new char[polyString.length()+1];
    //copy given string to helper char chains
    strcpy(polynom, polyString.c_str());
    strcpy(copy, polyString.c_str());

    //split string into tokens separated by +/i
    char *token = strtok(polynom, "-+");

    while(token)
    {
        //if first token is not at index 0 of string
        //and previous sign is '-'
        if(token-polynom-1>0 && copy[token-polynom-1] == '-')
        {
            //create signed token - add '-' at the beginning
            char *signedToken = new char[sizeof(token)+1];
            snprintf(signedToken, sizeof(token)+1, "-%s", token);
            //push to term strings list
            polyTermsStrings.push_back(signedToken);
        }
        else
            //push to term strings list
            polyTermsStrings.push_back(token);

        //get next token
        token = strtok(NULL, "-+");
    }

    //max power of polynomial is equal to number of terms - 1
    power = polyTermsStrings.size()-1;
    for(unsigned int i=0; i<polyTermsStrings.size(); i++)
    {
        //split each term into tokens separated by 'x'
        char *coeff = strtok(polyTermsStrings[i], "x");
        float coeffVal = atof(coeff);
        polyTerms.push_back(Term(coeffVal, power--));

    }

    delete [] polynom;

    if(polyTerms.empty())
        return NULL;

    return new Polynomial(polyTerms);
}
