#pragma once
// STL
#include <vector>

template <typename T>
class MaxHeap {
private:
    std::vector<T> m_data;
public:
    MaxHeap() {}
    MaxHeap(const std::vector<T> & vec);

    ~MaxHeap() {}

    void push(const T & val);

    const T & top() const { return m_data[0]; }
    T & top() { return m_data[0]; }

    void pop();

    std::vector<T> & data() { return m_data; }
    const std::vector<T> & data() const { return m_data; }
};

#include "MaxHeap.tcc"

