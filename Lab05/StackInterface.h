/**
*	@file : StackInterface.h
*	@author :  Arjan Gupta
*	@date : 2015.02.27
*	Purpose: Templated interface file for StackInterface, Lab 05 (reimplemented from Lab 04), EECS 268
*/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{
public:
    /**
        *  @pre None
        *  @post None
        *  @return None
        */
    virtual ~StackInterface() {};

    /**
        *  @pre None
        *  @post None
        *  @return true if the stack is empty, false otherwise
        */
    virtual bool isEmpty() const = 0;

    /**
        *  @pre a const variable of type T
        *  @post entry added to top of stack
        *  @return None
        */
    virtual void push(const T newEntry) = 0;

    /**
        *  @pre None
        *  @post Top of stack is removed if the stack is not empty.
        *  @return value of the entry at the top of the stack
        */
    virtual T pop() throw(PreconditionViolationException) = 0;

    /**
        *  @pre None
        *  @post None
        *  @return value at the top of the stack
        */
    virtual T peek() const throw(PreconditionViolationException) = 0;

    /**
        *  @pre None
        *  @post None
        *  @return size of the stack
        */
    virtual int size() const = 0;

    /**
        *  @pre None
        *  @post prints the values in the stack or "Stack is empty" if it is empty
        *  @return None
        */
    virtual void print() const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is less than the rhs's size
        */
    virtual bool operator < (const StackInterface<T> &rhs) const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is less than or equal to the rhs's size
        */
    virtual bool operator <= (const StackInterface<T> &rhs) const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is more than the rhs's size
        */
    virtual bool operator > (const StackInterface<T> &rhs) const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if the size of this stack is more than or equal to the rhs's size
        */
    virtual bool operator >= (const StackInterface<T> &rhs) const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if both stacks are equal
        */
    virtual bool operator == (const StackInterface<T> &rhs) const = 0;

    /**
        *  @pre None
        *  @post None
        *  @return true if size of both stacks are not equal
        */
    virtual bool operator != (const StackInterface<T> &rhs) const = 0;
};

#endif //STACK_INTERFACE_H
