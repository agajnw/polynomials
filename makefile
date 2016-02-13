all: src/*.cpp 
	g++ src/main.cpp src/fileManager.cpp src/polynomial.cpp src/root.cpp src/term.cpp src/tests.cpp -o polynomial
clean: polynomial
	rm polynomial
