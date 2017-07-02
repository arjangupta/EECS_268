/**
*	@file : Node.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Template header file for Node class, Lab08, EECS 268
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
public:
    /**
                *  @pre none
                *  @post Sets m_left and m_right to nullptr. Leaves m_value alone since we
                *        don't know what type we're dealing with so we don't know what a
                *        good default value is
                *  @return none
                */
    Node();

    /**
                *  @pre none
                *  @post none
                *  @return Create a deep copy of the other node,
                *          meaning it also creates copies of any nodes being pointed to by other
                */
    Node(const Node<T>& other);

    /**
                *  @pre there is a value in the node
                *  @post none
                *  @return the value in the node
                */
    T getValue() const;

    /**
                *  @pre the left of a node exists
                *  @post none
                *  @return a pointer to the left of the node
                */
    Node<T>* getLeft() const;

    /**
                *  @pre the right of this node exists
                *  @post none
                *  @return a pointer to the right node of this node
                */
    Node<T>* getRight() const;

    /**
                *  @pre none
                *  @post changes the value in the node
                *  @return None
                */
    void setValue(T value);

    /**
                *  @pre none
                *  @post sets the left node of this node
                *  @return None
                */
    void setLeft(Node<T>* left);

    /**
                *  @pre none
                *  @post sets the right node of this node
                *  @return None
                */
    void setRight(Node<T>* right);

private:
   Node<T>* m_left;
   Node<T>* m_right;
   T m_value;
};

#include "Node.hpp"

#endif //NODE_H
