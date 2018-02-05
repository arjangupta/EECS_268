/**
*	@file : NumberFileDriver.h
*	@author : Arjan Gupta
*	@date : 2015.04.03
*	Purpose: Header file for NumberFileDriver class, Lab07, EECS 268
*/

#ifndef NUMBER_FILE_DRIVER
#define NUMBER_FILE_DRIVER

#include "NumberFileGenerator.h"

class NumberFileDriver
{
public:
    /**
            *  @pre arguments is a valid 2-D array and the arguments contained within are valid.
            *       The argc and argv should be passed directly from main
            *  @post If the arguments are valid, a number file is created following those specifications.
            *        Otherwise, the help menu is printed and no files are created.
            *  @return none
            */
    static void run(int argc, char** argv);

    /**
            *  @pre none
            *  @post Prints a menus to help the user use the NumberFileGenerator.
            *  @return none
            */
    static void printHelpMenu();

private:
    /**
            *  @pre none
            *  @post none
            *  @return True if the option passed in is valid. Valid options are: "-a", "-d",
            *          "-r", and "-s". This is case sensitive.
            */
    static bool isValidOption(std::string option);
};

#endif //NUMBER_FILE_DRIVER
