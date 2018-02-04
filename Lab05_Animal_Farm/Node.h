/**
*	@file : Node.h
*	@author :  Arjan Gupta
*	@date : 2015.02.20
*	Purpose: Header file for Node class, Lab 05 (reimplemented from Lab03), EECS 268
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    /**
        *  @pre None
        *  @post initializes m_next, m_previous, and m_value
        *  @return initializes m_next and m_previous to nullptr, and initializes m_value to the copy constructor
        */
    Node();

    /**
        *  @pre None
        *  @post None
        *  @return value in the node (m_value)
        */
    T getValue() const;

    /**
        *  @pre a value of type T
        *  @post sets m_value to the value passed in
        *  @return None
        */
    void setValue(T value);

    /**
        *  @pre None
        *  @post None
        *  @return a pointer to the previous node
        */
    Node<T>* getPrevious() const;

    /**
        *  @pre a pointer to a node
        *  @post assigns m_previous the pointer passed in
        *  @return None
        */
    void setPrevious(Node<T>* previous);

    /**
        *  @pre None
        *  @post None
        *  @return a pointer to the next node
        */
    Node<T>* getNext() const;

    /**
        *  @pre a pointer to a node
        *  @post assigns m_next to the pointer passed in
        *  @return None
        */
    void setNext(Node<T>* next);

private:
    T m_value;
    Node<T>* m_previous;
    Node<T>* m_next;
};

#include "Node.hpp"

#endif //NODE_H
