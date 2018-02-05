/**
*	@file : BSTI.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Header file for BSTI Interface, Lab08, EECS 268
*/

#ifndef BSTI_H
#define BSTI_H

#include "ValueNotFoundException.h"

enum Order
{
   PRE_ORDER, IN_ORDER, POST_ORDER
};

template <typename T>
class BSTI
{
public:
    /**
                *  @pre A BSTI exists
                *  @post Deletes the entire tree
                *  @return None
                */
    virtual ~BSTI(){}

    /**
                *  @pre "this" is in a valid state
                *  @post Creates a deep copy of "this"
                *  @return Returns a pointer to a deep copy of "this"
                */
    virtual BSTI* clone() = 0;

    /**
                *  @pre none
                *  @post none
                *  @return true if no nodes in the tree, otherwise false.
                */
    virtual bool isEmpty() const = 0;

    /**
                *  @pre value is a valid T
                *  @post a new Node<T> is created an inserted into the tree based
                *  @return false if the value couldn't be added
                */
    virtual bool add(T value) = 0;

    /**
                *  @pre The type T is comparable by the == operator
                *  @post none
                *  @return if the value is in the tree, the value is returned, otherwise an exception is thrown.
                *  @throws ValueNotFoundException if the value is not in the tree
                */
    virtual T search(T value) const throw (ValueNotFoundException) = 0;

    /**
                *  @pre none
                *  @post the contents of the tree are printed to the console in the specified order
                *  @return none
                */
    virtual void printTree(Order order) const = 0;

    /**
                *  @pre none
                *  @post the contents of the tree are printed to the console in in-order
                *  @return none
                */
    virtual void sortedPrint() const = 0;
};

#endif //BSTI_H
