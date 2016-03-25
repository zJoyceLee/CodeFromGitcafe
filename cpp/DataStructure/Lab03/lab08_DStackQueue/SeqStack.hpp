#pragma once
//Current Project
#include "SequentialList.hpp"

template <typename T>
class SeqStack {
private:
    SequentialList<T> m_lst;
public:
    SeqStack(const std::size_t sz = 5);
    SeqStack(const SeqStack & rhs);
    ~SeqStack();

    std::size_t getLength() const;
    std::size_t getCapacity() const;

    void push(const T & element);

    void popOnce();
    void pop(std::size_t popTimes);

    T & top();
    const T & top() const;

    bool isEmpty() const;

    void clear();

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;
};

#include "SeqStack.tcc"
