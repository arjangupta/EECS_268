/**
*	@file : Position.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Implementation file for Position class, Lab09, EECS 268
*/

#include "Position.h"

Position::Position(int row, int col)
{
    m_row = row;
    m_col = col;
}

int Position::getCol() const
{
    return (m_col);
}

int Position::getRow() const
{
    return (m_row);
}
