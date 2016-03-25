#pragma once

template<typename T>
class Node {
private:
    T m_data;
    Node * m_pNode;
public:
    Node();
    Node(const T & element);
    ~Node();

    T & data() { return m_data; }
    const T & data() const { return m_data; }

    Node * & next() { return m_pNode; }
    const Node * next() const { return m_pNode; }
};

#include "Node.tcc"
