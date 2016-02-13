#include <assert.h>
#include <iostream>
#include <float.h>
#include <cmath>
#include "fileManager.h"
#include "polynomial.h"
#include "root.h"

void testFileManager()
{
    FileManager fManager;

    //1
    assert(fManager.readPoly("tests/1.txt") == NULL);

    //2
    assert(fManager.readPoly("tests/2.txt") == NULL);

    //3
    Polynomial *poly3 = fManager.readPoly("tests/3.txt");
    assert(fManager.savePoly(poly3, "tests/3.txt") == true);
    Polynomial *poly3copy = fManager.readPoly("tests/3.txt");
    assert(poly3->getPolyString() == poly3copy->getPolyString());

    //4
    Polynomial *poly4 = fManager.readPoly("tests/4.txt");
    assert(poly4->getPolyString() == "5");
    assert(fManager.savePoly(poly4, "tests/4_copy.txt") == true);
    Polynomial *poly4copy = fManager.readPoly("tests/4_copy.txt");
    assert(poly4->getPolyString() == poly4copy->getPolyString());

    //5
    Polynomial *poly5 = fManager.readPoly("tests/5.txt");
    assert(poly5->getPolyString() == "25x-100");
    assert(fManager.savePoly(poly5, "tests/5_copy.txt") == true);
    Polynomial *poly5copy = fManager.readPoly("tests/5_copy.txt");
    assert(poly5->getPolyString() == poly5copy->getPolyString());

    //6
    Polynomial *poly6 = fManager.readPoly("tests/6.txt");
    assert(poly6->getPolyString() == "2x^2+2x-4");
    assert(fManager.savePoly(poly6, "tests/6_copy.txt") == true);
    Polynomial *poly6copy = fManager.readPoly("tests/6_copy.txt");
    assert(poly6->getPolyString() == poly6copy->getPolyString());

    //7
    Polynomial *poly7 = fManager.readPoly("tests/7.txt");
    assert(poly7->getPolyString() == "6x^3+4x^2+0x+3");
    assert(fManager.savePoly(poly7, "tests/7_copy.txt") == true);
    Polynomial *poly7copy = fManager.readPoly("tests/7_copy.txt");
    assert(poly7->getPolyString() == poly7copy->getPolyString());

    //8
    Polynomial *poly8 = fManager.readPoly("tests/8.txt");
    assert(poly8->getPolyString() == "1x^10-5x^9+0x^8+0x^7+1x^6+2x^5-7x^4+0x^3+0x^2+0x-25");
    assert(fManager.savePoly(poly8, "tests/8_copy.txt") == true);
    Polynomial *poly8copy = fManager.readPoly("tests/8_copy.txt");
    assert(poly8->getPolyString() == poly8copy->getPolyString());

}

void testHelper()
{
    //1
    Term term(2.5, 3);
    assert(term.getCoeff() == 2.5);
    assert(term.getPower() == 3);

    //2
    Term term2(5, 1);
    Term term2der = term2.derivativeGet();
    assert(term2der.getCoeff() == term2.getCoeff()*term2.getPower());
    assert(term2der.getPower() == term2.getPower()-1);

    //3
    Term term3(-8.4, 10);
    Term term3der = term3.derivativeGet();
    assert(term3der.getCoeff() == term3.getCoeff()*term3.getPower());
    assert(term3der.getPower() == term3.getPower()-1);

    //4
    Root root(7.23, 2);
    assert(root.getX() == 7.23);
    assert(root.getY() == 2);
}

void testPolynomial()
{
    FileManager fManager;

    //1
    Polynomial *poly1 = fManager.readPoly("tests/3.txt");
    Root result1 = poly1->calculateRoot(1.0);
    assert((result1.getX() == -2) || (result1.getX() == 1));

    //2
    Polynomial *poly2 = fManager.readPoly("tests/5.txt");
    Root result2 = poly2->calculateRoot(1.0);
    assert(result2.getX() == 4);

    //3
    Polynomial *poly3 = fManager.readPoly("tests/6.txt");
    Root result3 = poly3->calculateRoot(1.0);
    assert((result3.getX() == -2) || (result3.getX() == 1));

    //4
    Polynomial *poly4 = fManager.readPoly("tests/7.txt");
    Root result4 = poly4->calculateRoot(1.0);
    assert(abs(result4.getX()+1.0886) < DBL_EPSILON);

    //5
    Polynomial *poly5 = fManager.readPoly("tests/8.txt");
    Root result5 = poly5->calculateRoot(1.0);
    assert((abs(result5.getX()+1.24201) < DBL_EPSILON) || (abs(result5.getX()-4.99101) < DBL_EPSILON));
}

void testsRun()
{
    testFileManager();
    std::cout << "Passed file manager tests" << std::endl;
    testHelper();
    std::cout << "Passed helper tests" << std::endl;
    testPolynomial();
    std::cout << "Passed polynomial tests" << std::endl;
    std::cout << "All tests passed" << std::endl;
}
