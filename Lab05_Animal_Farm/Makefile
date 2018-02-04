Lab05: main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Cow.o Chicken.o CyberChicken.o -o Lab05

main.o: main.cpp Node.h Node.hpp Stack.h Stack.hpp StackInterface.h
	g++ -g -std=c++11 -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp
	g++ -g -std=c++11 -c AnimalPen.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -c FarmAnimal.cpp

Cow.o: Cow.h Cow.cpp
	g++ -g -std=c++11 -c Cow.cpp

Chicken.o: Chicken.h Chicken.cpp
	g++ -g -std=c++11 -c Chicken.cpp

CyberChicken.o: CyberChicken.h CyberChicken.cpp
	g++ -g -std=c++11 -c CyberChicken.cpp

clean:
	rm *.o Lab05
	clean done