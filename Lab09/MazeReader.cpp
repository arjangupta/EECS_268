/**
*	@file : MazeReader.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Implementation file for MazeReader class, Lab09, EECS 268
*/

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException)
{
    m_in.open(file);
    m_maze = nullptr;

    if(!m_in.good())
    {
        throw(MazeCreationException("\nException: The file could not be opened."));
    }
    else
    {
        m_in >> m_rows;
        m_in >> m_cols;
        m_in >> m_startRow;
        m_in >> m_startCol;

        if(m_rows <= 0 || m_cols <= 0)
        {
            throw(MazeCreationException("\nException: The rows or columns are zero or less\n"));
        }
        else if(m_startRow < 0 || m_startCol < 0 || m_startRow > m_rows || m_startCol > m_cols)
        {
            throw(MazeCreationException("\nException: Invalid starting poistion\n"));
        }

        m_maze = new char*[m_rows];

        for(int i = 0; i < m_rows; i++)
        {
            m_maze[i] = new char[m_cols];
        }

        readMaze();
    }
}

MazeReader::~MazeReader()
{
    if(m_maze != nullptr)
    {
        for(int i = 0; i < m_rows; i++)
        {
            delete[] m_maze[i];
        }
        delete[] m_maze;
    }
}

void MazeReader::readMaze() throw (MazeCreationException)
{
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_cols; j++)
        {
            m_in >> m_maze[i][j];
        }
    }
}

char** MazeReader::getMaze() const
{
    return (m_maze);
}

int MazeReader::getCols() const
{
    return (m_cols);
}

int MazeReader::getRows() const
{
    return (m_rows);
}

int MazeReader::getStartCol() const
{
    return (m_startCol);
}

int MazeReader::getStartRow() const
{
    return (m_startRow);
}
