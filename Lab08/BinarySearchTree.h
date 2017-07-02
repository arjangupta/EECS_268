/**
*	@file : BinarySearchTree.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Template header file for BinarySearchTree class, Lab08, EECS 268
*/

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BSTI.h"
#include "Node.h"
#include <iostream>

template <typename T>
class BinarySearchTree : public BSTI<T>
{
public:
    /**
                *  @pre none
                *  @post none
                *  @return Sets m_root to nullptr
                */
     BinarySearchTree();

     /**
                 *  @pre called in clone method, when this BinarySearchTree needs to be deep copied
                 *  @post none
                 *  @return creates a deep copy of other BST
                 */
     BinarySearchTree(const BinarySearchTree<T>& other);

     /**
                 *  @pre none
                 *  @post none
                 *  @return Calls private method, deleteTree(Node<T>* subTree)
                 *          and passes in m_root as the starting point for deletion
                 */
     virtual ~BinarySearchTree();

    /**
                *  @pre "this" is in a valid state
                *  @post Creates a deep copy of "this"
                *  @return Returns a pointer to a deep copy of "this"
                */
    virtual BSTI<T>* clone();

    /**
                *  @pre none
                *  @post none
                *  @return true if no nodes in the tree, otherwise false.
                */
    virtual bool isEmpty() const;

    /**
                *  @pre value is a valid T
                *  @post a new Node<T> is created an inserted into the tree based
                *  @return false if the value couldn't be added
                */
    virtual bool add(T value);

    /**
                *  @pre The type T is comparable by the == operator
                *  @post none
                *  @return if the value is in the tree, the value is returned, otherwise an exception is thrown.
                *  @throws ValueNotFoundException if the value is not in the tree
                */
    virtual T search(T value) const throw (ValueNotFoundException);

    /**
                *  @pre none
                *  @post the contents of the tree are printed to the console in the specified order
                *  @return none
                */
    virtual void printTree(Order order) const;

    /**
                *  @pre none
                *  @post the contents of the tree are printed to the console in in-order
                *  @return none
                */
    virtual void sortedPrint() const;

private:

    /**
                *  @pre none
                *  @post adds the value to the correct branch (left or right) of the subtree
                *  @return true if add operation was successful
                */
    bool add(T value, Node<T>* subtree);

    /**
                *  @pre none
                *  @post deletes the left subtree, right subtree, and root node of the subtree passed in
                *  @return none
                */
    void deleteTree(Node<T>* subTree);

    /**
                *  @pre none
                *  @post none
                *  @return if the value is in the tree, the value is returned, otherwise an exception is thrown.
                */
    T search(T value, Node<T>* subtree) const throw( ValueNotFoundException );

    /**
                *  @pre none
                *  @post prints the tree in PRE_ORDER or IN_ORDER or POST_ORDER using the subtree and the "order".
                *  @return none
                */
    void printTree(Node<T>* subtree, Order order) const;

    Node<T>* m_root;
};

#include "BinarySearchTree.hpp"

#endif //BINARY_SEARCH_TREE_H
