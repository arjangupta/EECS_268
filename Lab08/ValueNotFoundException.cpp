/**
*	@file : ValueNotFoundException.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Implementation file for ValueNotFoundException class, Lab08, EECS 268
*/

#include "ValueNotFoundException.h"

ValueNotFoundException::ValueNotFoundException(const char* message)
    : std::runtime_error(message)
{

}

