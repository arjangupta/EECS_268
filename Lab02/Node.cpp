/**
*	@file : Node.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.09
*	Purpose: Implementation file for Node class, Lab02, EECS 268
*/

#include "Node.h"

Node::Node()
{
    m_value = 0;
    m_next = nullptr;
}

void Node::setValue(int val)
{
    m_value = val;
}

int Node::getValue() const
{
    return (m_value);
}

void Node::setNext(Node* prev)
{
    m_next = prev;
}

Node* Node::getNext() const
{
    return (m_next);
}
