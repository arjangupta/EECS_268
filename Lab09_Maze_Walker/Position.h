/**
*	@file : Position.h
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Header file for Position class, Lab09, EECS 268
*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
        /**
        *	@post Position created with row and col values set.
        */
        Position(int row, int col);

        /**
        *	@return row value
        */
        int getRow() const;

        /**
        *	@return col value
        */
        int getCol() const;

private:
        int m_row;
        int m_col;
};

#endif //POSITION_H
