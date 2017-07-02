/**
*	@file : NumberFileGenerator.cpp
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Header file for NumberFileGenerator class, Lab07, EECS 268
*/

#include "NumberFileGenerator.h"

void NumberFileGenerator::ascending(std::string fileName, int amount)
{
    std::ofstream outputFile(fileName);

    outputFile << amount << "\n";

    for(int i = 0; i < amount; i++)
    {
        outputFile << i << "\n";
    }

    outputFile.close();

    std::cout << amount << " numbers stored in " << fileName << std::endl;
}

void NumberFileGenerator::descending(std::string fileName, int amount)
{
    std::ofstream outputFile(fileName);

    outputFile << amount << "\n";

    for(int i = amount; i > 0; i--)
    {
        outputFile << i << "\n";
    }

    outputFile.close();

    std::cout << amount << " numbers stored in " << fileName << std::endl;
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
    static std::default_random_engine generator(time(nullptr));
    static std::uniform_int_distribution<int> distribution(min, max);
    std::ofstream outputFile(fileName);

    outputFile << amount << "\n";

    for(int i = 0; i < amount; i++)
    {
        outputFile << distribution(generator) << "\n";
    }

    outputFile.close();

    std::cout << amount << " numbers stored in " << fileName << std::endl;
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{
    std::ofstream outputFile(fileName);

    outputFile << amount << "\n";

    for(int i = 0; i < amount; i++)
    {
        outputFile << value << "\n";
    }

    outputFile.close();

    std::cout << amount << " numbers stored in " << fileName << std::endl;
}
