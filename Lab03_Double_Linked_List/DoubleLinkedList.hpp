/**
*	@file : main.cpp
*	@author :  Arjan Gupta
*	@date : 2015.02.20
*	Purpose: Template implementation file for DoubleLinkedList class of Lab03, EECS 268
*/

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    m_front = nullptr;
    m_back = nullptr;
    m_size = 0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while(m_front!= nullptr)
    {
        remove(m_front->getValue());
    }
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
    if(m_size==0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

template <typename T>
int DoubleLinkedList<T>::size() const
{
    return(m_size);
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
    /* CASE 1: The list is empty
     * In this case, do the following:
     * 1. Create a new empty node
     * 2. Put the passed value inside it
     * 3. Make m_front and m_back point at the new front node
     * 4. Increase m_size
     *
     * CASE 2: The list is not empty
     * In this case, have to do the following:
     * 1. Create a new empty node
     * 2. Put the passed value inside it
     * 3. Attach it to the front
     * 4. Make m_front point at the new front node
     * 5. Increase m_size
     */

    Node<T>* temp = new Node<T>();
    temp->setValue(value);

    if(isEmpty())
    {
        m_front = temp;
        m_back = temp;
    }
    else
    {
        temp->setNext(m_front);
        m_front->setPrevious(temp);
        m_front = temp;
    }

    m_size++;

}

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
    /*
     * CASE 1: The list is empty
     * 1. Call pushFront and pass in the same value
     *
     * CASE 2: The list is not empty
     * 1. Access last node using m_back
     * 2. Create a new node, put in its value and attach it to the back
     * 3. Make m_back point at the new back node
     * 4. Increase m_size
     */

    if(isEmpty())
    {
        pushFront(value);
    }
    else
    {
        Node<T>* tempNewNode = new Node<T>();
        tempNewNode->setValue(value);
        m_back->setNext(tempNewNode);
        tempNewNode->setPrevious(m_back);
        m_back = tempNewNode;
        m_size++;
    }
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value)
{
    /*
     * CASE 1: Node with desired value was not found
     * In this case, return a false.
     *
     * CASE 2: Node with desired value was found
     * In this case, we have 4 sub cases.
     *
     * CASE A: The node found was at the front and at the back
     * 1. Set m_front and m_back to nullptr
     * 2. Delete the found node
     * 3. Decrease m_size
     * 4. Return true
     *
     * CASE B: The node found was at the front but not at the back
     * 1. Assign a pointer to the second node
     * 2. Delete the first node
     * 3. Assign m_front to new front node
     * 4. Assign m_previous of the new front node as nullptr
     * 5. Decrease the m_size
     * 6. Return true
     *
     * CASE C: The node found was at the back but not at the front
     * 1. Assign a pointer to the second-last node
     * 2. Delete the last node
     * 3. Assign m_back to the new last node
     * 4. Assign m_next of the new back as nullptr
     * 5. Decrease the m_size
     * 6. Return true
     *
     * CASE D: The node found was somewhere in between 2 nodes in the list
     * 1. Assign a pointer to the nodes in front and behind the found node
     * 2. Delete the found node
     * 3. Join the front and behind nodes to each other
     * 4. Decrease m_size
     * 5. Return true
     */

    Node<T>* foundNode = find(value);

    if(foundNode == nullptr)
    {
        return(false);
    }
    else if(foundNode == m_front && foundNode == m_back)
    {
        m_front = nullptr;
        m_back = nullptr;
        delete foundNode;
    }
    else if(foundNode == m_front && foundNode != m_back)
    {
        Node<T>* newFront = foundNode->getNext();
        delete foundNode;
        m_front = newFront;
        newFront->setPrevious(nullptr);
    }
    else if(foundNode == m_back && foundNode != m_front)
    {
        Node<T>* newBack = foundNode->getPrevious();
        delete foundNode;
        m_back = newBack;
        newBack->setNext(nullptr);
    }
    else
    {
        Node<T>* behindNode = foundNode->getPrevious();
        Node<T>* frontNode = foundNode->getNext();
        delete foundNode;
        //join the behind and front
        behindNode->setNext(frontNode);
        frontNode->setPrevious(behindNode);
    }

    m_size--;
    return(true);
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (std::runtime_error)
{
    /*
     * CASE 1: listValue is not in the list
     * 1. throw an exception
     *
     * CASE 2: listValue is in the list but is the value of the first node
     * 1. Use pushFront and pass in newValue
     *
     * CASE 3: listValue is in the list and is not the value of the first node
     * 1. Using the pointer to the node of listValue, create a temp node for the previous node
     * 2. Create a node on the heap
     * 3. Put the newValue inside the new node
     * 4. Put the newValue node between the 2 temp nodes
     * 5. Increase m_size
     */

    Node<T>* tempFound = find(listValue);

    if(tempFound == nullptr)
    {
        throw(std::runtime_error("EXCEPTION: Value is not in the list."));
    }
    else if(tempFound == m_front)
    {
        pushFront(newValue);
    }
    else
    {
        Node<T>* tempPrev = tempFound->getPrevious();

        Node<T>* insertNode = new Node<T>();
        insertNode->setValue(newValue);

        insertNode->setPrevious(tempPrev);
        insertNode->setNext(tempFound);

        tempPrev->setNext(insertNode);
        tempFound->setPrevious(insertNode);

        m_size++;
    }
}

template <typename T>
void DoubleLinkedList<T>::insertBehind(T listValue, T newValue) throw (std::runtime_error)
{
    /*
     * CASE 1: listValue is not in the list
     * 1. throw an exception
     *
     * CASE 2: listValue is in the list but is the value of the last node
     * 1. Use pushBack and pass in newValue
     *
     * CASE 3: listValue is in the list and is not the value of the last node
     * 1. Using the pointer to the node of listValue, create a temp node for the next node
     * 2. Create a node on the heap
     * 3. Put the newValue inside the new node
     * 4. Put the newValue node between the 2 temp nodes
     * 5. Decrease m_size
     */

    Node<T>* tempFound = find(listValue);

    if(tempFound == nullptr)
    {
        throw(std::runtime_error("EXCEPTION: Value is not in the list."));
    }
    else if(tempFound == m_back)
    {
        pushBack(newValue);
    }
    else
    {
        Node<T>* tempNext = tempFound->getNext();

        Node<T>* insertNode = new Node<T>();
        insertNode->setValue(newValue);

        insertNode->setNext(tempNext);
        insertNode->setPrevious(tempFound);

        tempNext->setPrevious(insertNode);
        tempFound->setNext(insertNode);

        m_size--;
    }
}

template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const
{
    /*
     * In this find function, we encounter two cases.
     *
     * CASE 1: List is empty
     * In this case, we will just return nullptr
     *
     * CASE 2: List is not empty
     * In this case, we will do the following:
     * 1. Create a temporary node pointer
     * 2. Run the temporary node pointer through the list till the node with the desired value is reached
     * 3. Assign that temporary node pointer to the desired node
     * 4. Return the temporary node
     * 5. If the desired value is not found, return nullptr
     */

    Node<T>* tempSearch = m_front;

    while(tempSearch != nullptr)
    {
        if(tempSearch->getValue() == value)
        {
            return(tempSearch);
        }
        else
        {
            tempSearch = tempSearch->getNext();
        }
    }

    return(nullptr);

}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
    Node<T>* tempPrint = m_front;

    while(tempPrint != nullptr)
    {
        std::cout << tempPrint->getValue();
        tempPrint = tempPrint->getNext();

        if(tempPrint != nullptr)
        {
            std::cout << ",";
        }
    }
}
