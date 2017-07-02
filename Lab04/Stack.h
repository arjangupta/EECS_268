/**
*	@file : Stack.h
*	@author :  Arjan Gupta
*	@date : 2015.02.27
*	Purpose: Templated header file for Stack class, Lab 04, EECS 268
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"
#include "StackInterface.h"

template <typename T>
class Stack: public StackInterface<T>
{
public:

    /**
        *  @pre None
        *  @post initialize m_size and m_top
        *  @return initialize m_size to 0 and m_top to nullptr
        */
    Stack();

    /**
        *  @pre None
        *  @post None
        *  @return None
        */
    virtual ~Stack();

    /**
        *  @pre None
        *  @post None
        *  @return true if the stack is empty, false otherwise
        */
    virtual bool isEmpty() const;

    /**
        *  @pre a const variable of type T
        *  @post entry added to top of stack
        *  @return None
        */
    virtual void push(const T newEntry);

    /**
        *  @pre None
        *  @post Top of stack is removed if the stack is not empty.
        *  @return value of the entry at the top of the stack
        */
    virtual T pop() throw(PreconditionViolationException);

    /**
        *  @pre None
        *  @post None
        *  @return value at the top of the stack
        */
    virtual T peek() const throw(PreconditionViolationException);

    /**
        *  @pre None
        *  @post None
        *  @return size of the stack
        */
    virtual int size() const;

    /**
        *  @pre None
        *  @post prints the values in the stack or "Stack is empty" if it is empty
        *  @return None
        */
    virtual void print() const;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is less than the rhs's size
        */
    virtual bool operator < (const StackInterface<T> &rhs) const;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is less than or equal to the rhs's size
        */
    virtual bool operator <= (const StackInterface<T> &rhs) const;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is more than the rhs's size
        */
    virtual bool operator > (const StackInterface<T> &rhs) const;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is more than or equal to the rhs's size
        */
    virtual bool operator >= (const StackInterface<T> &rhs) const;

    /**
        *  @pre None
        *  @post None
        *  @return true if both stacks are equal
        */
    virtual bool operator == (const StackInterface<T> &rhs) const;

    /**
        *  @pre None
        *  @post None
        *  @return true if size of both stacks are not equal
        */
    virtual bool operator != (const StackInterface<T> &rhs) const;

private:
    Node<T>* m_top;
    int m_size;
};

#include "Stack.hpp"

#endif //STACK_H
