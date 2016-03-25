#pragma once

template <typename T>
Node<T>::Node() :
    m_data(),
    m_pNode(nullptr)
{
}

template <typename T>
Node<T>::Node(const T & element) :
    m_data(element),
    m_pNode(nullptr)
{
}

template <typename T>
Node<T>::~Node()
{
}
