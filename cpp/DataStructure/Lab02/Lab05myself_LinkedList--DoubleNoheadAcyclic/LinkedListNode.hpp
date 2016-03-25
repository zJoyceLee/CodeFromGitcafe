#pragma once

template <typename T>
class LinkedListNode {
private:
    T m_data;
    LinkedListNode * m_prev;
    LinkedListNode * m_next;
public:
    LinkedListNode() :
        m_data(),
        m_prev(nullptr),
        m_next(nullptr)
    {}

    LinkedListNode(const T & element) :
        m_data(element),
        m_prev(nullptr),
        m_next(nullptr)
    {}

    ~LinkedListNode() {}

    T & data() { return m_data; }
    const T & data() const { return m_data; }

    LinkedListNode * & prev() { return m_prev; }
    const LinkedListNode * & prev() const { return m_prev; }

    LinkedListNode * & next() { return m_next; }
    const LinkedListNode * next() const { return m_next; }

};
