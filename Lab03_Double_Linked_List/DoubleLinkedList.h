/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.20
*	Purpose: Template header file for DoubleLinkedList class of Lab03, EECS 268
*/

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
#include <stdexcept>
#include <iostream>
#include <string>

template <typename T>
class DoubleLinkedList
{
public:
    /**
        *  @pre None
        *  @post initializes m_front, m_back, and m_size
        *  @return initializes m_front and m_back to nullptr, and initializes m_size to 0
        */
    DoubleLinkedList();

    /**
        *  @pre None
        *  @post Deallocates all nodes
        *  @return None
        */
    ~DoubleLinkedList();

    /**
        *  @pre None
        *  @post None
        *  @return true if m_size is zero, false otherwise
        */
    bool isEmpty() const;

    /**
        *  @pre None
        *  @post None
        *  @return size of the list
        */
    int size() const;

    /**
        *  @pre a value to put in the node
        *  @post puts that node at the front of the list
        *  @return none
        */
    void pushFront(T value);

    /**
        *  @pre a value to put in the node
        *  @post puts that node at the back of the list
        *  @return None
        */
    void pushBack(T value);

    /**
        *  @pre takes in value of type T
        *  @post deletes the node containing the passed value
        *  @return None
        */
    bool remove(T value);

    /**
        *  @pre Takes in 2 values of type T
        *  @post Finds a node with value in the list, then places the new Value node ahead of that found node
        *  @return None
        */
    void insertAhead(T listValue, T newValue) throw (std::runtime_error);

    /**
        *  @pre Takes in 2 values of type T
        *  @post Finds a node with value in the list, then places the new Value node behind that found node
        *  @return None
        */
    void insertBehind(T listValue, T newValue) throw (std::runtime_error);

    /**
        *  @pre None
        *  @post None
        *  @return a pointer to the first node in the list (from front to back) that contains the value
        *          or nullptr if not found
        */
    Node<T>* find(T value) const;

    /**
        *  @pre None
        *  @post The list is printed to the screen
        *  @return None
        */
    void printList() const;

private:
    Node<T>* m_front;
    Node<T>* m_back;
    int m_size;
};

#include "DoubleLinkedList.hpp"

#endif //DOUBLELINKEDLIST_H
