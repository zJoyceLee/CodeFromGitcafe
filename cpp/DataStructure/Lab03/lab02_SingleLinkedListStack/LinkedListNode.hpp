#pragma once

template<typename T>
class LinkedListNode {
private:
    T m_data;
    LinkedListNode * m_pNode;
public:
    LinkedListNode();
    LinkedListNode(const T & element);
    ~LinkedListNode();

    T & data() { return m_data; }
    const T & data() const { return m_data; }

    LinkedListNode * & next() { return m_pNode; }
    const LinkedListNode * next() const { return m_pNode; }
};

#include "LinkedListNode.tcc"
