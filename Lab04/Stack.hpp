/**
*	@file : Stack.hpp
*	@author :  Arjan Gupta
*	@date : 2015.02.27
*	Purpose: Templated implementation file for Stack class, Lab 04, EECS 268
*/

template <typename T>
Stack<T>::Stack()
{
    m_top = nullptr;
    m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    while(!isEmpty())
    {
        pop();
    }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (m_top == nullptr);
}

template <typename T>
void Stack<T>::push(const T newEntry)
{
    /*
     * CASE 1: Stack is empty
     * 1. Create a new node
     * 2. Put newEntry into it
     * 3. make m_top point at the node
     * 4. increase m_size
     *
     * CASE 2: Stack is not empty
     * 1. Create a new node
     * 2. Put newEntry into it
     * 3. Attach this new node to the top of the list
     * 4. make m_top point at the node
     * 5. increase m_size
     */

    Node<T>* newNodePtr = new Node<T>();
    newNodePtr->setValue(newEntry);

    if(!isEmpty())
    {
        newNodePtr->setNext(m_top);
    }

    m_top = newNodePtr;
    m_size++;
}

template <typename T>
T Stack<T>::pop() throw(PreconditionViolationException)
{
    /*
     * CASE 1: Stack is empty
     * 1. Throw an exception
     *
     * CASE 2: Stack is not empty, has only one node
     * 1. store value of that node
     * 2. delete the node
     * 3. set m_top to nullptr
     * 4. decrease m_size
     * 5. return the stored value
     *
     * CASE 3: Stack is not empty, has more than 1 node
     * 1. store value of the top node
     * 2. create a temporary node pointer to point at the second node from the top
     * 3. delete the node at the top
     * 4. make m_top point at the new first node
     * 5. decrease m_size
     * 6. return the stored value
     */

    if(isEmpty())
    {
        throw(PreconditionViolationException("Exception: Destack attempted on an empty stack"));
    }
    else if(m_top->getNext() == nullptr)
    {
        T storeValue = m_top->getValue();

        delete m_top;
        m_top = nullptr;
        m_size--;

        return (storeValue);
    }
    else
    {
        T storeValue = m_top->getValue();
        Node<T>* secondNodePtr = m_top->getNext();

        delete m_top;
        m_top = secondNodePtr;
        m_size--;

        return (storeValue);
    }
}

template <typename T>
T Stack<T>::peek()const throw(PreconditionViolationException)
{
    if(isEmpty())
    {
        throw(PreconditionViolationException("Exception: Peek attempted on an empty stack"));
    }
    else
    {
        return(m_top->getValue());
    }
}

template <typename T>
int Stack<T>::size() const
{
    return (m_size);
}

template <typename T>
void Stack<T>::print() const
{
    if(isEmpty())
    {
        std::cout << "Stack Empty" << std::endl;
    }
    else
    {
        Node<T>* listTravel = m_top;

        while(listTravel != nullptr)
        {
            std::cout << listTravel->getValue();

            listTravel = listTravel->getNext();

            if(listTravel != nullptr)
            {
                std::cout << ",";
            }
        }
    }
}

template <typename T>
bool Stack<T>::operator < (const StackInterface<T> &rhs) const
{
    return((this->m_size) < (rhs.size()));
}

template <typename T>
bool Stack<T>::operator <= (const StackInterface<T> &rhs) const
{
    return((this->m_size) <= (rhs.size()));
}

template <typename T>
bool Stack<T>::operator > (const StackInterface<T> &rhs) const
{
    return((this->m_size) > (rhs.size()));
}

template <typename T>
bool Stack<T>::operator >= (const StackInterface<T> &rhs) const
{
    return((this->m_size) >= (rhs.size()));
}

template <typename T>
bool Stack<T>::operator == (const StackInterface<T> &rhs) const
{
    return((this->m_size) == (rhs.size()));
}

template <typename T>
bool Stack<T>::operator != (const StackInterface<T> &rhs) const
{
    return((this->m_size) != (rhs.size()));
}
