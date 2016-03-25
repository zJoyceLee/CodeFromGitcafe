#pragma once
// STL
#include <vector>

template <typename T>
class SequentialList {
public:
    /// npos -- not a position
    const static std::size_t npos;
private:
    T * m_data;
    std::size_t m_curLen;
    std::size_t m_maxLen;
private:
    /// return the normalized index from [0, m_curLen) on valid
    /// throw out_of_range if invalid
    int transformAndCheckIndex(int index) const;

    /// return the normalized index from [0, m_curLen] on valid
    /// throw out_of_range if invalid
    int transformAndCheckIndexWithCurLen(int index) const;

    bool isFull() const;

    void expand();

public:
    SequentialList(const std::size_t n);
    SequentialList(const std::size_t n, const SequentialList & rhs);
    ~SequentialList();

    void swap(SequentialList & rhs);

    std::size_t getLength() const;

    std::size_t getCapacity() const;

    T & operator[](int index);
    const T & operator[](int index) const;

    template <typename BiFunc>
    std::size_t find(const T & element, int startIndex, BiFunc comparator) const;
    template <typename UnaryFunc>
    std::size_t find(int startIndex, UnaryFunc checker) const;
    template <typename UnaryFunc>
    std::vector<std::size_t> findAll(UnaryFunc checker) const;

    /// insert `element` before `position`
    void insert(const T & element, int position);

    template <typename BiFunc>
    void insertSorted(const T & element, BiFunc comparator);

    void push_back(const T & element);

    /// remove the element at `position`
    void remove(int position);

    bool isEmpty() const;

    void clear();

    template <typename UnaryFunc>
    void traverse(UnaryFunc visitor) const;

    template <typename BiFunc>
    std::size_t maxIndex(BiFunc comparator) const;
    template <typename BiFunc>
    std::size_t minIndex(BiFunc comparator) const;
};

#include "SequentialList.tcc"

