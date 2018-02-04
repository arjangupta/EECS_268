/**
*	@file : NumberFileDriver.cpp
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Implementation file for NumberFileDriver class, Lab07, EECS 268
*/

#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char **argv)
{
    std::string option = argv[2];
    std::string fileName = argv[3];
    int amount = std::stoi(argv[4]);

    if(isValidOption(option))
    {
        if(option == "-a")
        {
            NumberFileGenerator::ascending(fileName, amount);
        }
        else if(option == "-d")
        {
            NumberFileGenerator::descending(fileName, amount);
        }
        else if(option == "-s")
        {
            int value = std::stoi(argv[5]);
            NumberFileGenerator::singleValue(fileName, amount, value);
        }
        else if(option == "-r")
        {
            int min = std::stoi(argv[5]);
            int max = std::stoi(argv[6]);
            NumberFileGenerator::random(fileName, amount, min, max);
        }
    }
    else
    {
        printHelpMenu();
    }
}

void NumberFileDriver::printHelpMenu()
{
    std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
                << "./prog -create -a filename amount\n"
                << "./prog -create -d filename amount\n"
                << "./prog -create -s filename amount value\n"
                << "./prog -create -r filename amount min max\n"
                << "Option explainations:\n"
                << "\t-a for ascending\n"
                << "\t-d for descending\n"
                << "\t-s for a single value\n"
                << "\t-r for random values\n"
                << "\tfilename is the ouput file name\n"
                << "\tamount is the amount of random numbers to place in the file\n"
                << "\tvalue is the single number that will be written to file in -s mode\n"
                << "\tmin is the low end of the range of random numbers\n"
                << "\tmax is the high end (non-inclusive) of the range of random numbers\n";
}

bool NumberFileDriver::isValidOption(std::string option)
{
    if(option == "-a" || option == "-d" || option == "-r" || option == "-s")
    {
        return (true);
    }
    else
    {
        return (false);
    }
}
