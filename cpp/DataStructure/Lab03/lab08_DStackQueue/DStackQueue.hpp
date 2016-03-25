#pragma once
// STL
#include <vector>
// Current Project
#include "SeqStack.hpp"

/**
 *      _____________     ____________
 *  <-- __stk_front__ <-- __stk_back__ <--
 */
template <typename T>
class DStackQueue {
public:
    DStackQueue() {}
    DStackQueue(const std::vector<T> & rhs) {
        for(const auto & i : rhs)
            this->push(i);
    }
    DStackQueue(const DStackQueue & rhs) :
        m_stkBack(rhs.m_stkBack),
        m_stkFront(rhs.m_stkFront)
    {}
    ~DStackQueue() {}

    /// insert element at the end
    void push(const T & value);

    /// removes the first element
    void pop();

    /// access the first element
    T & front();
    const T & front() const;

    /// access the last element
    T & back();
    const T & back() const;

    /// checks whether the queue is empty
    bool empty() const;

    /// returns the number of elements
    std::size_t size() const;

    /// traverse from front to back
    template <typename UnaryFunc>
    void traverseF2B(UnaryFunc unary);

    /// traverse from back to front
    template <typename UnaryFunc>
    void traverseB2F(UnaryFunc unary);

private:
    /// pour every element from back to front
    void pourToFront();
    /// pour every element from front to back
    void pourToBack();

private:
    SeqStack<T> m_stkBack;
    SeqStack<T> m_stkFront;
};

#include "DStackQueue.tcc"
