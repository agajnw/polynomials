A simple cpp program that parses a polynomial and calculates its root using Newton's method. (April 2015)

How to run the program:

arguments:
-r fileName - name of the file from which to get the polynomial
-s fileName - name of the file to which the polynomial should be saved
-p startPoint - start point of Newton's method
-t - launch tests

If read file name is not specified, the program will read the polynomial from standard input.
The program accepts polynomials of the following format:
a1x^n+a2x^n-1+....+bx+c
Terms' coefficients need to be defined even if equal to 0; they can be negative.


Tests have been divided into 3 groups:
1)testFileManager: reading/writing polynomial to file
 * 1. wrong file name (file doesn't exist)
 * 2. read empty file
 * 3. write to existing file
 * 4. read polynomial of power=0, check value and write it to different file
 * 5. read polynomial of power=1, check value and write it to different file
 * 6. read polynomial of power=2, check value and write it to different file
 * 7. read polynomial of power=3, check value and write it to different file
 * 8. read polynomial of power=10, check value and write it to different file


2) testHelper: test Term and Root classes
 * 1. create Term obj and check values returned by class's getters
 * 2. create Term of power=1 and check derivative;
 * 3. create Term of power=10 and check derivative;
 * 4. create Root obj and check values returned by class's getters


3) testPolynomial: test Polynomial class: proper execution of Newton's method
 * and quality of results
 * 1. test polynomial with negative values
 * 2. test polynomial of power=1
 * 3. test polynomial of power=2
 * 4. test polynomial of power=3
 * 5. test polynomial of power=10
