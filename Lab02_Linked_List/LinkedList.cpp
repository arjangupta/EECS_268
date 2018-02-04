/**
*	@file : LinkedList.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.09
*	Purpose: Implementation file for LinkedList class, Lab02
*/

#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_front = nullptr;
    m_size = 0;
}

LinkedList::~LinkedList()
{
    while(removeFront())
    {
        //if this loop is entered, it means 1 element has been removed
    }
}

bool LinkedList::isEmpty() const
{
    if(m_size != 0)
    {
        return (false);
    }
    else
    {
        return (true);
    }
}

int LinkedList::size() const
{
    return (m_size);
}

bool LinkedList::search(int value) const
{
    Node* tempNode = m_front;

    while(tempNode != nullptr)
    {
        if(tempNode->getValue() == value)
        {
            return (true);
        }

        tempNode = tempNode->getNext();
    }

    return (false);
}

void LinkedList::printList() const
{
    /* first of all, we need to check if the list is empty.
     * if it is not empty, we can proceed to print hte values.
     * if it is empty, we must tell the user so.
     */

    if(!isEmpty())
    {
        Node* tempNode = m_front;

        while(tempNode != nullptr)
        {
            std::cout << tempNode->getValue() << " ";

            tempNode = tempNode->getNext();

            if(tempNode == nullptr)
            {
                std::cout << "\n";
            }
        }
    }
    else
    {
        std::cout << "List Empty." << std::endl;
    }
}

void LinkedList::addBack(int value)
{
    /* first of all, we need to check if the list is empty.
     * if it is not empty, we can proceed to search for the last node.
     * if it is empty, we can just add the first node to the list.
     */

    if(!isEmpty())
    {
        //first we need to make our pointer reach the last node

        Node* tempNode = m_front;

        while(tempNode->getNext() != nullptr)
        {
            tempNode = tempNode->getNext();
        }

        //now tempNode is pointing at the last node in the list.

        //create a new node to add the new element
        Node* newBoxPtr = new Node();

        //set the value of the new node
        newBoxPtr->setValue(value);

        //attach the new node to the list
        tempNode->setNext(newBoxPtr);

        //node added to the back. Increment the size of the list.
        m_size++;
    }
    else
    {
        addFront(value);
    }
}

void LinkedList::addFront(int value)
{
    //create a node on the heap
    Node* tempNode = new Node();

    //assign it its value
    tempNode->setValue(value);

    //attach the Node to the head of the list
    tempNode->setNext(m_front);

    //make m_front point at the new head of the list
    m_front = tempNode;

    //now that the new node has been added, increment the size of the list.
    m_size++;
}

bool LinkedList::removeBack()
{
    /* first of all, we need to check if the list is empty.
     * if it is not empty, we can proceed to search for the last node.
     * if it is empty, we must return a false because there are no nodes to remove.
     */

    if(!isEmpty())
    {
        /* We need to make a temporary pointer reach the last node, so that we can remove that last node.
         * However, we also need a pointer that reaches the last but one node, so that we can assign
         * that node to null pointer after the last node is removed.
         */

        Node* tempNode = m_front; //this pointer will reach the last node
        Node* breadCrumb = m_front;

        while(tempNode->getNext() != nullptr)
        {
            tempNode = tempNode->getNext();

            if(tempNode->getNext() != nullptr)
            {
                breadCrumb = breadCrumb->getNext();
            }
        }

        //now tempNode is pointing at the last node in the list and breadCrumb is pointing at the second last node.

        /* we want to:
         * 1. assign the second last node's m_next to nullptr
         * 2. remove the last node
         * 3. decrement the size of the list
         * 4. return a true, indicating that the node has been removed.
         */

        breadCrumb->setNext(nullptr); //step 1

        delete tempNode; //step 2

        m_size--; //step 3

        return(true); //step 4
    }
    else
    {
        //the list is empty, so there is nothing to remove. Return a false.

        return (false);
    }

}

bool LinkedList::removeFront()
{
    /* first of all, we need to check if the list is empty.
     * if it is not empty, we can proceed to remove the first node.
     * if it is empty, we must return a false because there are no nodes to remove.
     */

    if(!isEmpty())
    {
        /* we want to:
         * 1. remove the first node
         * 2. assign m_front to point at the second node
         * 3. decrement the size of the list
         * 4. return a true, indicating that the node has been removed.
         */

        delete m_front; //step 1

        m_front = m_front->getNext(); //step 2

        m_size--; //step 3

        return(true); //step 4
    }
    else
    {
        //the list is empty, so there is nothing to remove. Return a false.

        return (false);
    }
}
