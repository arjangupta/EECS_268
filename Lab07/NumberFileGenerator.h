/**
*	@file : NumberFileGenerator.h
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Header file for NumberFileGenerator class, Lab07, EECS 268
*/

#ifndef NUMBER_FILE_GENERATOR_H
#define NUMBER_FILE_GENERATOR_H

#include <string>
#include <fstream>
#include <iostream>
#include <random>

class NumberFileGenerator
{
public:
    /**
            *  @pre fileName is valid path/filename. Amount is greater than zero
            *  @post A file is created with the amount of number is ascending order. The amount of
            *        numbers in the file is the first entry in the file
            *  @return none
            */
    static void ascending(std::string fileName, int amount);

    /**
            *  @pre fileName is valid path/filename. Amount is greater than zero
            *  @post A file is created with the amount of number is descending order. The amount of
            *        numbers in the file is the first entry in the file
            *  @return none
            */
    static void descending(std::string fileName, int amount);

    /**
            *  @pre fileName is valid path/filename. Amount is greater than zero
            *  @post A file is created with the specifed amount of numbers. All number are random and
            *        fall between min and max (inclusively). The amount of numbers in the file
            *        is the first entry in the file
            *  @return none
            */
    static void random(std::string fileName, int amount, int min, int max);

    /**
            *  @pre fileName is valid path/filename. Amount is greater than zero
            *  @post A file is created with a single number, specified by value, amount of times. The amount of
            *        numbers in the file is the first entry in the file
            *  @return none
            */
    static void singleValue(std::string fileName, int amount, int value);
};

#endif //NUMBER_FILE_GENERATOR_H
