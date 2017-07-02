Lab01: main.o Pokemon.o Dice.o Colosseum.o
	g++ -std=c++11 -g main.o Pokemon.o Dice.o Colosseum.o -o Lab01

main.o: main.cpp Dice.h Colosseum.h Pokemon.h
	g++ -std=c++11 -g -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -c Pokemon.cpp

Dice.o: Dice.h Dice.cpp
	g++ -std=c++11 -g -c Dice.cpp

Colosseum.o: Colosseum.h Colosseum.cpp
	g++ -std=c++11 -g -c Colosseum.cpp

clean: 
	rm *.o main
	clean done 
