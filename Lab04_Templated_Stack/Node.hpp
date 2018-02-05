/**
*	@file : Node.hpp
*	@author :  Arjan Gupta
*	@date : 2015.02.20
*	Purpose: Template file for Node class, Lab 04 (reiomplemented from Lab03), EECS 268
*/

template <typename T>
Node<T>::Node()
{
    m_previous = nullptr;
    m_next = nullptr;
    m_value = T();
}

template <typename T>
T Node<T>::getValue() const
{
    return m_value;
}

template <typename T>
void Node<T>::setValue(T value)
{
    this->m_value = value;
}

template <typename T>
Node<T>* Node<T>::getPrevious() const
{
    return m_previous;
}

template <typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
    this->m_previous = previous;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
    return m_next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
    this->m_next = next;
}
