/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.03
*	Purpose: main file for Sorting and NumberFile program, Lab07, EECS 268
*/

#include "SortDriver.h"
#include "NumberFileDriver.h"

int main(int argc, char** argv)
{
    if(argc >= 5)
    {
        std::string mode = argv[1];

        //Check for number file creation fla
        if(mode == "-create")
        {
            NumberFileDriver::run(argc, argv);
        }
        //Check for sort flag
        else if (mode == "-sort")
        {
            SortDriver::run(argc, argv);
        }
    }
    else
    {
        NumberFileDriver::printHelpMenu();
        SortDriver::printHelpMenu();
    }
}
