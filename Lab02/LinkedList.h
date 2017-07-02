/**
*	@file : LinkedList.h
*	@author :  Arjan Gupta
*	@date : 2015.02.09
*	Purpose: Header file of LinkedList class
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList
{
public:
    /**
        *  @pre None
        *  @post Initializes private member variables appopriately
        *  @return Initializes m_front to nullptr and m_size to 0
        */
    LinkedList();

    /**
        *  @pre None
        *  @post Deletes all nodes in the list
        *  @return None
        */
    ~LinkedList();

    /**
        *  @pre None
        *  @post None
        *  @return returns true if the list is empty, false otherwise
        */
    bool isEmpty() const;

    /**
        *  @pre None
        *  @post None
        *  @return returns the number of elements in the list
        */
    int size() const;

    /**
        *  @pre an int variable that you would like to search for in the list
        *  @post checks every node for te desired value
        *  @return returns true if the value is in the list, false otherwise
        */
    bool search(int value) const;

    /**
        *  @pre None
        *  @post prints the list to the console. "List empty" if it is empty
        *  @return None
        */
    void printList() const;

    /**
        *  @pre an int variable that you would like to add to the back of the list
        *  @post One new element added to the end of the list
        *  @return None
        */
    void addBack(int value);

    /**
        *  @pre an int variable that you would like to add to the front o the list
        *  @post One new element added to the front of the list.
        *  @return None
        */
    void addFront(int value);

    /**
        *  @pre None
        *  @post One element is removed from the back of the list.
        *  @return Returns true if the back element was removed, false if the list is empty.
        */
    bool removeBack();

    /**
        *  @pre None
        *  @post One element is removed from the front of the list.
        *  @return returns true if the front element was removed, false if the list is empty.
        */
    bool removeFront();

private:
    Node* m_front;
    int m_size;
};

#endif //LINKEDLIST_H
