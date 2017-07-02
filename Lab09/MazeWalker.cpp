/**
*	@file : MazeWalker.cpp
*	@author :  Arjan Gupta
*	@date : 2015.04.15
*	@brief: Implementation file for MazeWalker class, Lab09, EECS 268
*/

#include "MazeWalker.h"

MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs) :
    m_curPos(0,0), m_startPos(startRow, startCol)
{
    m_maze = mazePtr;
    m_isDFS = dfs;
    m_rows = rows;
    m_cols = cols;
    m_visited = new bool*[m_rows];
    for(int i = 0; i < m_rows; i++)
    {
        m_visited[i] = new bool[m_cols];
        for(int j = 0; j < m_cols; j++)
        {
            m_visited[i][j] = false;
        }
    }
}

MazeWalker::~MazeWalker()
{
   for(int i = 0; i < m_rows; i++)
   {
       delete[] m_visited[i];
   }
   delete[] m_visited;
}

void MazeWalker::printMaze()
{
    for(int i = 0; i < m_rows; i++)
    {
        for(int j = 0; j < m_cols; j++)
        {
            std::cout << m_visited[i][j];
        }
        std::cout << "\n";
    }
    std::cout << "Visiting position: " << m_curPos.getRow() << ", " << m_curPos.getCol() << "\n"
              << "--------------------------\n";
}

void MazeWalker::walkMaze()
{
    //move to the starting point
    //print the maze and visiting position
    //check moves: up, right, down, left
    //if move has not been made before, load possible moves onto data structure
    //Repeat
    bool noWayOut = false;

    move(m_startPos);
    printMaze();

    while(!isGoalReached() && !noWayOut)
    {
        storeValidMoves();

        if(m_isDFS)
        {
            if(!m_moveStack.empty())
            {
                move(m_moveStack.top());
                m_moveStack.pop();
                printMaze();
            }
            else
            {
                noWayOut = true;
            }
        }
        else
        {
            if(!m_moveQueue.empty())
            {
                move(m_moveQueue.front());
                m_moveQueue.pop();
                printMaze();
            }
            else
            {
                noWayOut = true;
            }
        }
    }

    if(isGoalReached())
    {
        std::cout << "\nExit found!\n\n";
    }
    else if(noWayOut)
    {
        std::cout << "\nNo way out!\n\n";
    }
}

void MazeWalker::storeValidMoves()
{
    //Check up, down, right, left and push onto appropriate data structure.
    //Specifically using this order to check because the examples on the wiki page check the same way

    int row = m_curPos.getRow();
    int col = m_curPos.getCol();

    //CHECK UP
    if(row > 0)
    {
        if((m_maze[row - 1][col] != 'W') && !(m_visited[row - 1][col]))
        {
            Position up(row-1, col);
            if(m_isDFS)
            {
                m_moveStack.push(up);
            }
            else
            {
                m_moveQueue.push(up);
            }
        }
    }

    //CHECK DOWN
    if(row < (m_rows - 1))
    {
        if((m_maze[row + 1][col]) != 'W' && !(m_visited[row + 1][col]))
        {
            Position down(row + 1, col);
            if(m_isDFS)
            {
                m_moveStack.push(down);
            }
            else
            {
                m_moveQueue.push(down);
            }
        }
    }

    //CHECK RIGHT
    if(col < (m_cols - 1))
    {
        if((m_maze[row][col + 1]) != 'W' && !(m_visited[row][col + 1]))
        {
            Position right(row, col+1);
            if(m_isDFS)
            {
                m_moveStack.push(right);
            }
            else
            {
                m_moveQueue.push(right);
            }
        }
    }

    //CHECK LEFT
    if(col > 0)
    {
        if((m_maze[row][col-1]) != 'W' && !(m_visited[row][col-1]))
        {
            Position left(row, col-1);
            if(m_isDFS)
            {
                m_moveStack.push(left);
            }
            else
            {
                m_moveQueue.push(left);
            }
        }
    }
}

void MazeWalker::move(Position &p)
{
    m_curPos = p;
    m_visited[m_curPos.getRow()][m_curPos.getCol()] = true;
}

bool MazeWalker::isGoalReached() const
{
    return (m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E');
}
