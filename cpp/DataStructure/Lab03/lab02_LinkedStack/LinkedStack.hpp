#pragma once
#include "LinkedList.hpp"

template <typename T>
class LinkedStack {
private:
    LinkedList<T> m_lst;
public:
    LinkedStack();
    ~LinkedStack();
    void push(LinkedList<T> push_front);


};

#include "LinkedStack.tcc"
