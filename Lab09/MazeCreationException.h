/**
*	@file : MazeCreationException.h
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Header file for MazeCreationException class, Lab09, EECS 268
*/

#ifndef MAZE_CREATION_EXCEPTION_H
#define MAZE_CREATION_EXCEPTION_H

#include <stdexcept>

class MazeCreationException : public std::runtime_error
{
public:
    /**
     * @post Creates an exception with the message
     */
    MazeCreationException(const char* message);
};

#endif //MAZE_CREATION_EXCEPTION_H
