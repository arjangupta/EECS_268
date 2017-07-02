SortingSuite: main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o
	g++ -g -std=c++11 main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o -o SortingSuite

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -c main.cpp

SortDriver.o: SortDriver.h SortDriver.cpp
	g++ -g -std=c++11 -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -g -std=c++11 -c NumberFileDriver.cpp

clean:
	rm *.o SortingSuite
	clean done