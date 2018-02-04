/**
*	@file : PreconditionViolationException.h
*	@author :  Arjan Gupta
*	@date : 2015.02.27
*	Purpose: Header file for PreconditionViolationException class, Lab 04, EECS 268
*/

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXPCETION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error
{
public:
    /**
        *  @pre A string
        *  @post passes in the string to std::execption
        *  @return none
        */
    PreconditionViolationException(const char* message);
};

#endif //PRECONDITION_VIOLATION_EXCPETION_H
