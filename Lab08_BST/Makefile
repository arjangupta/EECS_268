Lab08: main.o ValueNotFoundException.o
	g++ -g -std=c++11 main.o ValueNotFoundException.o -o Lab08

main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp Node.h Node.hpp BSTI.h
	g++ -g -std=c++11 -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.h ValueNotFoundException.cpp
	g++ -g -std=c++11 -c ValueNotFoundException.cpp

clean:
	rm *.o Lab08
	clean done 
