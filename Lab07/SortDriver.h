/**
*	@file : SortDriver.h
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Header file for SortDriver class, Lab07, EECS 268
*/

#ifndef SORT_DRIVER_H
#define SORT_DRIVER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Sorts.h"

class SortDriver
{
public:
    /**
            *  @pre a character array and its size, passed in from main
            *  @post A file is created containing the timing information
            *        of the chosen sort(s) on the supplied file
            *  @return none
            */
    static void run(int argc, char** argv);

    /**
            *  @pre none
            *  @post conditions Prints a menus to help the user use the NumberFileGenerator.
            *  @return none
            */
     static void printHelpMenu();
private:
     /**
             *  @pre The input file was created by a NumberFileGenerator.
             *  @post conditions Prints a menus to help the user use the NumberFileGenerator.
             *  @return True if the file exists, false otherwise.
             */
    static bool isFileAccessible(std::string fileName);

    /**
            *  @pre none
            *  @post none
            *  @return True if the sort parameter matches a valid one (see help menu).
            */
    static bool isSortValid(std::string sortParameter);

    /**
            *  @pre none
            *  @post none
            *  @return True is the file specified by inputFileName exists and the sort
            *          parameter is valid, false otherwise.
            */
    static bool areParametersValid(std::string sortName, std::string inputFileName);

    /**
            *  @pre The input file was created with the Number File Generator
            *  @post The first line of the file is read in, containing the count.
            *  @return Returns how many numbers are in the file.
            */
    static int getFileCount(std::ifstream& inputFile);

    /**
            *  @pre The input file was created with the Number File Generator, the size was read in, and that size if correct.
            *  @post The remainder of input file numbers are read in. File is NOT closed.
            *  @return True if the sort parameter matches a valid one (see help menu).
            */
    static int* createArray(std::ifstream& inputFile, int size);

    /**
            *  @pre Original and copy are valid arrays of the correct size.
            *  @post All values from original are copied into copy.
            *  @return none
            */
    static void copyArray(int original[], int copy[], int size);
};

#endif //SORT_DRIVER_H
