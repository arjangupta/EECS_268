/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: main file for Lab09, EECS 268
*/

//Mr. Zhang, thank you so much for being an amazing TA. See you later!

#include "MazeReader.h"
#include "MazeWalker.h"

int main(int argc, char** argv)
{
    bool dfs;
    bool progOK = true;
    std::string fileName;
    MazeReader* reader = nullptr;
    MazeWalker* walker = nullptr;

    if(argc != 3)
    {
        std::cout << "\nPlease enter 3 valid arguments in one of the following ways:\n"
                  << "./Lab09 filename -dfs\n"
                  << "./Lab09 filename -bfs\n\n";
        progOK = false;
    }
    else
    {
        fileName = argv[1];
        std::string searchType = argv[2];

        if(searchType == "-dfs")
        {
            dfs = true;
        }
        else if(searchType == "-bfs")
        {
            dfs = false;
        }
        else
        {
            std::cout << "\nPlease enter 3 valid arguments in one of the following ways:\n"
                      << "./Lab09 filename -dfs\n"
                      << "./Lab09 filename -bfs\n\n";
            progOK = false;
        }
    }

    if(progOK)
    {
        try
        {
            reader = new MazeReader(fileName);
        }
        catch(MazeCreationException& e)
        {
            std::cout << e.what() << std::endl;
            progOK = false;
        }
    }

    if(progOK)
    {
        walker = new MazeWalker(reader->getMaze(), reader->getStartRow(), reader->getStartCol(), reader->getRows(), reader->getCols(), dfs);
        walker->walkMaze();
    }

    delete reader;
    delete walker;
    return (0);
}
