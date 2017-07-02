Lab02: main.o LinkedList.o Node.o
	g++ -std=c++11 -g main.o LinkedList.o Node.o -o Lab02

main.o: main.cpp LinkedList.h
	g++ -std=c++11 -g -c main.cpp

LinkedList.o: LinkedList.h Node.h LinkedList.cpp
	g++ -std=c++11 -g -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean: 
	rm *.o main
	clean done 

