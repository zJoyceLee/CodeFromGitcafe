#pragma once
//STL
#include <vector>
//Current Project
#include "Node.hpp"

template <typename T>
class LinkedList {
private:
    LinkedListNode<T> * m_data;
public:
    LinkedList();
    LinkedList(const std::vector<T> & vec);
    LinkedList(const LinkedList & rhs);
    ~LinkedList();

    LinkedListNode<T> * begin() { return m_data; }
    const LinkedListNode<T> * begin() const { return m_data; }

    LinkedListNode<T> * end() { return nullptr; }
    const LinkedListNode<T> * end() const { return nullptr; }

    void push_front(const T & element);

    void insertBefore(LinkedListNode<T> * position, const T & element);
    void insertAfter(LinkedListNode<T> * position, const T & element);

    void remove(LinkedListNode<T> * position);

    template <typename UnaryFunc>
    LinkedListNode<T> * find(LinkedListNode<T> * startPosition, UnaryFunc checker) const;

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;

    template <typename BinaryFunc>
    void swapMinMax(BinaryFunc comparatorLess);
};

#include "LinkedList.tcc"
