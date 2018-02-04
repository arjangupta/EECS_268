/**
*	@file : PreconditionViolationException.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.27
*	Purpose: Implementation file for PreconditionViolationException class, Lab 04, EECS 268
*/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* message)
    : std::runtime_error(message)
{

}
