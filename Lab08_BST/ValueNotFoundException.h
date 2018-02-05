/**
*	@file : ValueNotFoundException.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Header file for ValueNotFoundException class, Lab08, EECS 268
*/

#ifndef VALUE_NOT_FOUND_EXCEPTION_H
#define VALUE_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class ValueNotFoundException : public std::runtime_error
{
public:
    /**
            *  @pre A string
            *  @post passes in the string to std::execption
            *  @return none
            */
        ValueNotFoundException(const char* message);
};

#endif //VALUE_NOT_FOUND_EXCEPTION_H
