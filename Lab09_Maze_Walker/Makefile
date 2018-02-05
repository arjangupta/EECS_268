Lab09: main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o
	g++ -std=c++11 -g main.o MazeReader.o MazeCreationException.o MazeWalker.o Position.o -o Lab09

main.o: main.cpp MazeReader.h MazeWalker.h
	g++ -std=c++11 -g -c main.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -c MazeReader.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp 
	g++ -std=c++11 -g -c MazeCreationException.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -c MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -std=c++11 -g -c Position.cpp

clean: 
	rm *.o Lab09
	clean done