/**
*	@file : BinarySearchTree.h
*	@author :  Arjan Gupta
*	@date : 2015.04.08
*	Purpose: Template implementation file for BinarySearchTree class, Lab08, EECS 268
*/

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
    deleteTree(this->m_root);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
    if(other.m_root == nullptr)
    {
        m_root = nullptr;
    }
    else
    {
        m_root = new Node<T>(*(other.m_root));
    }
}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone()
{
    BSTI<T>* tempPtr = new BinarySearchTree<T>(*(this));
    return tempPtr;
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    return (m_root == nullptr);
}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
    return (add(value, this->m_root));
}

template <typename T>
T BinarySearchTree<T>::search(T value) const throw (ValueNotFoundException)
{
    try
    {
      return (search(value, m_root));
    }
    catch(ValueNotFoundException &v)
    {
        std::cout << v.what() << std::endl;
    }
}

template <typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
    if(isEmpty())
    {
        std::cout << "Tree empty" << std::endl;
    }
    else
    {
        printTree(m_root, order);
    }
}

template <typename T>
void BinarySearchTree<T>::sortedPrint() const
{
    if(isEmpty())
    {
        std::cout << "Tree empty" << std::endl;
    }
    else
    {
        printTree(m_root, IN_ORDER);
    }
}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
    if(isEmpty())
    {
        //nothing to delete
    }
    else
    {
        if(subTree->getLeft() != nullptr)
        {
            deleteTree(subTree->getLeft());
        }

        if(subTree->getRight() != nullptr)
        {
            deleteTree(subTree->getRight());
        }

        delete subTree;
        subTree = nullptr;
    }
}

template <typename T>
bool BinarySearchTree<T>::add(T value, Node<T>* subtree)
{
    /*
     * 1. compare value with subtree->getValue();
     * 2. base the comparison of 1, check if left/right subtree is nullptr;
     *      if no recursive call add to subtree;
     *      if yes create new node and make it a left/right node of subtree.
     */
    if(m_root == nullptr)
    {
        m_root = new Node<T>();
        m_root->setValue(value);
    }
    else
    {
        if(value <= subtree->getValue())
        {
            if(subtree->getLeft() == nullptr)
            {
                Node<T>* tempNode = new Node<T>();
                tempNode->setValue(value);
                subtree->setLeft(tempNode);
            }
            else
            {
                add(value, subtree->getLeft());
            }
        }
        else
        {
            if(subtree->getRight() == nullptr)
            {
                Node<T>* tempNode = new Node<T>();
                tempNode->setValue(value);
                subtree->setRight(tempNode);
            }
            else
            {
                add(value, subtree->getRight());
            }
        }
    }
    return (true);
}

template <typename T>
T BinarySearchTree<T>::search(T value, Node<T>* subtree) const throw(ValueNotFoundException)
{
    if(subtree == nullptr)
    {
        throw(ValueNotFoundException("Exception: Value not found"));
    }
    else if(subtree->getValue() == value)
    {
        return (value);
    }
    else
    {
        if(value < subtree->getValue())
        {
            search(value, subtree->getLeft());
        }
        else
        {
            search(value, subtree->getRight());
        }
    }
}

template <typename T>
void BinarySearchTree<T>::printTree(Node<T>* subtree, Order order) const
{
    if(subtree != nullptr)
    {
        if(order == PRE_ORDER)
        {
            //print in pre order
            std::cout << subtree->getValue() << " ";
            printTree(subtree->getLeft(), order);
            printTree(subtree->getRight(), order);
        }
        else if(order == IN_ORDER)
        {
            //print in in order
            printTree(subtree->getLeft(), order);
            std::cout << subtree->getValue() << " ";
            printTree(subtree->getRight(), order);
        }
        else
        {
            //print in post order
            printTree(subtree->getLeft(), order);
            printTree(subtree->getRight(), order);
            std::cout << subtree->getValue() << " ";
        }
    }
}
