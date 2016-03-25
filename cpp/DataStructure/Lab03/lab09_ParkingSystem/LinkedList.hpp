
#pragma once
//STL
#include <vector>
//Current Project
#include "LinkedListNode.hpp"

template <typename T>
class LinkedList {
private:
    LinkedListNode<T> * m_head;
private:
    LinkedListNode<T> * findPrevNode(const LinkedListNode<T> * position) const;
public:
    LinkedList();
    LinkedList(const std::vector<T> & vec);
    ~LinkedList();

    LinkedListNode<T> * & begin();
    const LinkedListNode<T> * begin() const;

    LinkedListNode<T> * & end();
    const LinkedListNode<T> * end() const;

    bool isEmpty() const;

    template <typename UnaryFunc>
    LinkedListNode<T> * find(LinkedListNode<T> * startPos, UnaryFunc check) const;
    ///modify:Node * p,p -> m_data.studentNum = new studentNum

    void push_front(const T & element);
    void insertBefore(LinkedListNode<T> * position, const T & element);

    /// @param comparatorLess, accepts a function with signiture of
    ///        `bool (*)(const T & lhs, const T & rhs)`, which returns
    ///        true on lhs < rhs, false otherwise.
    template <typename BiFunc>
    void insertSorted(const T & element, BiFunc comparatorLess);

    void remove(LinkedListNode<T> * position);

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;

    void reversal();

    void swap(LinkedList<T> & rhs);
};


#include "LinkedList.tcc"
