#pragma once
//Current Project
#include "LinkedListNode.hpp"
#include "LinkedList.hpp"

template <typename T>
class SingleLinkedStack {
private:
    LinkedList<T> m_lst;
public:
    void popOnce();
public:
    SingleLinkedStack();
    SingleLinkedStack(const SingleLinkedStack<T> & rhs);
    ~SingleLinkedStack();

    bool isEmpty();

    void push(const T & element);

    void pop(std::size_t popTimes);

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;

};

#include "SingleLinkedStack.tcc"
