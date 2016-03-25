#pragma once
//STL
#include <vector>
//Current Project
#include "Node.hpp"

template <typename T>
class LinkedList {
private:
    Node<T> * m_head;
    std::size_t m_length;
private:
    Node<T> * findPrevNode(const Node<T> * position) const;
public:
    LinkedList();
    LinkedList(const std::vector<T> & vec);
    ~LinkedList();

    Node<T> * & begin();
    const Node<T> * begin() const;

    Node<T> * & end();
    const Node<T> * end() const;

    template <typename UnaryFunc>
    Node<T> * find(Node<T> * startPos, UnaryFunc check) const;
    ///modify:Node * p,p -> m_data.studentNum = new studentNum

    void push_front(const T & element);
    void insertBefore(Node<T> * position, const T & element);

    /// @param comparatorLess, accepts a function with signiture of
    ///        `bool (*)(const T & lhs, const T & rhs)`, which returns
    ///        true on lhs < rhs, false otherwise.
    template <typename BiFunc>
    void insertSorted(const T & element, BiFunc comparatorLess);

    void remove(Node<T> * position);

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor);

    void reversal();

    void swap(LinkedList<T> & rhs);
};


#include "LinkedList.tcc"
