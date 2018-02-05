/**
*	@file : Node.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Template implementation file for Node class, Lab08, EECS 268
*/

template <typename T>
Node<T>::Node()
{
    m_left = nullptr;
    m_right = nullptr;
}

template <typename T>
Node<T>::Node(const Node<T>& other)
{
    m_left = nullptr;
    m_right = nullptr;

    m_value = other.getValue();

    if(other.getLeft() != nullptr)
    {
        m_left = new Node<T>(*(other.getLeft()));
    }

    if(other.getRight() != nullptr)
    {
        m_right = new Node<T>(*(other.getRight()));
    }
}

template <typename T>
T Node<T>::getValue() const
{
    return m_value;
}

template <typename T>
Node<T>* Node<T>::getLeft() const
{
    return m_left;
}

template <typename T>
Node<T>* Node<T>::getRight() const
{
    return m_right;
}

template <typename T>
void Node<T>::setValue(T value)
{
    m_value = value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left)
{
    m_left = left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right)
{
    m_right = right;
}
