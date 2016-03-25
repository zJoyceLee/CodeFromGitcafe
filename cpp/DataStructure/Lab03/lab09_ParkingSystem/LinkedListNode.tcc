#pragma once

template <typename T>
LinkedListNode<T>::LinkedListNode() :
    m_data(),
    m_pNode(nullptr)
{
}

template <typename T>
LinkedListNode<T>::LinkedListNode(const T & element) :
    m_data(element),
    m_pNode(nullptr)
{
}

template <typename T>
LinkedListNode<T>::~LinkedListNode()
{
}
