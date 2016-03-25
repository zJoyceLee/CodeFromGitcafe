#pragma once
// STL
#include <vector>
// Current Project
#include "LinkedListNode.hpp"

template <typename T>
class LinkedList {
private: // variable
    LinkedListNode<T> * m_data;
private: //
public: // function
    LinkedList(const std::vector<T> & vec);
    /// added 12-03
    LinkedList(const LinkedList & rhs);
    ~LinkedList();

    LinkedListNode<T> *& head() { return m_data; }
    const LinkedListNode<T> * head() const { return m_data; }

    LinkedListNode<T> * begin() { return m_data; }
    const LinkedListNode<T> * begin() const { return m_data; }

    LinkedListNode<T> * end() { return nullptr; }
    const LinkedListNode<T> * end() const { return nullptr; }

    void push_front(const T & element);
    /// fixed 12-03
    void insertBefore(LinkedListNode<T> * position, const T & element);
    /// added 12-03
    void insertAfter(LinkedListNode<T> * position, const T & element);

    /// fixed 12-03
    void remove(LinkedListNode<T> * position);

    template <typename UnaryFunc>
    LinkedListNode<T> * find(LinkedListNode<T> * startPosition, UnaryFunc checker) const;

    /// fixed 12-03: add const
    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;

    template <typename BinaryFunc>
    void swapMinMax(BinaryFunc comparatorLess);

};//class LinkedList

#include "LinkedList.tcc"
