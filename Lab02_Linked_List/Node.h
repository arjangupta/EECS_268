/**
*	@file : Node.h
*	@author :  Arjan Gupta
*	@date : 2015.02.09
*	Purpose: Header file for Node class, Lab02, EECS 268
*/

#ifndef NODE_H
#define NODE_H

class Node
{
public:

    /**
        *  @pre None
        *  @post Initializes private member variables appopriately
        *  @return Initializes m_next to nullptr and m_value to 0
        */
    Node();

    /**
        *  @pre calls an int val
        *  @post sets m_value to val
        *  @return None
        */
    void setValue(int val);

    /**
        *  @pre None
        *  @post None
        *  @return the int m_value
        */
    int getValue() const;

    /**
        *  @pre takes in a Node pointer
        *  @post sets m_next
        *  @return None
        */
    void setNext(Node* prev);

    /**
        *  @pre None
        *  @post None
        *  @return m_next
        */
    Node* getNext() const;

private:
    int m_value;
    Node* m_next;
};

#endif //NODE_H
