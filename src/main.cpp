#include <iostream>
#include <unistd.h>
#include "fileManager.h"
#include "polynomial.h"
#include "root.h"
#include "tests.h"

using namespace std;

int main(int argc, char** argv) {
	FileManager fManager;
	char c;
	bool read = false, save = false;
	string fileToRead, fileToSave;
	double startPoint = 1.0;
	Polynomial *poly;

	//parse program's arguments
	while((c = getopt(argc, argv, "r:s:p:t")) != -1) {
		switch(c) {
		case 'r':
			//read polynomial from specified file
			read = true;
			fileToRead = optarg;
			break;
		case 's':
			//save polynomial to specified file
			save = true;
			fileToSave = optarg;
			break;
		case 'p':
			//define starting point for Newton's method
			startPoint = atof(optarg);
			break;
		case 't':
			//run tests
			testsRun();
			return 0;
		}
	}

	if(read) {
		//read specified file to load polynomial
		poly = fManager.readPoly(fileToRead);
		if(!poly)
		{
			cout << "Error while loading polynomial\n";
			return 0;
		}
		cout << *poly << endl;
	}
	else {
		//get polynomial string from standard input
		string polyString;
		getline(cin, polyString);
		//parse polynomial string
		poly = fManager.polyGetFromString(polyString);
		if(!poly)
		{
			cout << "Error while creating polynomial\n";
			return 0;
		}
	}

	//calculate root of polynomial using Newton's method
	Root result = poly->calculateRoot(startPoint);
	cout << "result: " << result.getX() << ", " << result.getY() << endl;

	if(save) {
		//save polynomial to specified file
		if(!fManager.savePoly(poly, fileToSave))
			{
				cout << "Failed to save polynomial\n";
			}
	}
}
