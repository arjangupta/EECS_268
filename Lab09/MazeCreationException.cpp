/**
*	@file : MazeCreationException.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Implementation file for MazeCreationException class, Lab09, EECS 268
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char *message) : std::runtime_error(message)
{

}
