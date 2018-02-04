Lab04: main.o PreconditionViolationException.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o -o Lab04

main.o: main.cpp Node.h Node.hpp Stack.h Stack.hpp StackInterface.h
	g++ -g -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

clean:
	rm *.o Lab04
	clean done 
