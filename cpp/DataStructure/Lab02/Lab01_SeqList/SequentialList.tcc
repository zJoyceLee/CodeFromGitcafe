#pragma once
// STL
#include <limits>
#include <stdexcept>

template <typename T, std::size_t N>
const std::size_t SequentialList<T, N>::npos = std::numeric_limits<std::size_t>::max();

template <typename T, std::size_t N>
int SequentialList<T, N>::transformAndCheckIndex(int index) const {
    /// 1. preprocess
    if(index < 0) {
        index += m_curLen;
    }//if

    /// 2. valid conditions
    if(index < 0 || index >= m_curLen){
        throw std::out_of_range("index out of range!");
    }

    return index;
}

template <typename T, std::size_t N>
int SequentialList<T, N>::transformAndCheckIndexWithCurLen(int index) const {
    /// 1. preprocess
    if(index < 0) {
        index += m_curLen;
    }//if

    /// 2. valid conditions
    if(index < 0 || index > m_curLen){
        throw std::out_of_range("index out of range!");
    }

    return index;
}

template <typename T, std::size_t N>
SequentialList<T, N>::SequentialList() :
    m_data(nullptr),
    m_curLen(0),
    m_maxLen(N)
{
    m_data = new T[m_maxLen];
}

template <typename T, std::size_t N>
SequentialList<T, N>::~SequentialList() {
    delete[] m_data;
}

template <typename T, std::size_t N>
std::size_t SequentialList<T, N>::getLength() const {
    return m_curLen;
}

template <typename T, std::size_t N>
T & SequentialList<T, N>::operator[](int index) {
    index = transformAndCheckIndex(index);
    return m_data[index];
}

template <typename T, std::size_t N>
const T & SequentialList<T, N>::operator[](int index) const {
    index = transformAndCheckIndex(index);
    return m_data[index];
}

template <typename T, std::size_t N>
template <typename BiFunc>
std::size_t SequentialList<T, N>::find(const T & element, int startIndex, BiFunc comparator) const {
    startIndex = transformAndCheckIndex(startIndex);

    for(std::size_t index = startIndex; index < m_curLen; ++index) {
        if(comparator(element, m_data[index]) == true)
            return index;
    }
    return SequentialList::npos;
}

template <typename T, std::size_t N>
template <typename UnaryFunc>
std::size_t SequentialList<T, N>::find(int startIndex, UnaryFunc checker) const {
    startIndex = transformAndCheckIndex(startIndex);

    for(std::size_t index = startIndex; index < m_curLen; ++index) {
        if(checker(m_data[index]) == true)
            return index;
    }
    return SequentialList::npos;
}

template <typename T, std::size_t N>
template <typename UnaryFunc>
std::vector<std::size_t> SequentialList<T, N>::findAll(UnaryFunc checker) const {
    std::vector<std::size_t> ret;

    std::size_t index;
    int startPosition = 0;
    do {
        index = find(startPosition, checker);
        if(index == SequentialList<T, N>::npos)
            break;
        ret.push_back(index);
        startPosition = index + 1;
    } while(true);
    return ret;
}

template <typename T, std::size_t N>
void SequentialList<T, N>::insert(const T & element, int position) {
    position = transformAndCheckIndexWithCurLen(position);

    /// 1. valid conditions
    if(position > m_curLen) {
        throw std::out_of_range("position out of range!");
    }//if

    if(m_curLen == m_maxLen) {
        throw std::runtime_error("SequentialList is out of space");
    }

    /// 2. preprocess
    if(m_curLen != 0) {
        for(std::size_t index = m_curLen - 1; index >= position; --index){
            m_data[index + 1] = m_data[index];
        }
    }//if

    /// 3. work
    m_data[position] = element;
    ++m_curLen;
}

template <typename T, std::size_t N>
template <typename BiFunc>
void SequentialList<T, N>::insertSorted(const T & element, BiFunc comparator) {
    std::size_t index = 0;
    for(index = 0; index < m_curLen; ++index) {
        if(comparator(element, m_data[index]) == true)
            break;
    }
    insert(element, index);
}

template <typename T, std::size_t N>
void SequentialList<T, N>::push_back(const T & element) {
    insert(element, m_curLen);
}

template <typename T, std::size_t N>
void SequentialList<T, N>::remove(int position) {
    position = transformAndCheckIndex(position);

    if(position >= m_curLen) {
        throw std::out_of_range("position out of range!");
    }
    for(std::size_t index = position; index < m_curLen - 1; ++index){
        m_data[index] = m_data[index + 1];
    }
    --m_curLen;
}

template <typename T, std::size_t N>
bool SequentialList<T, N>::isEmpty() const {
    return (m_curLen == 0);
}

template <typename T, std::size_t N>
void SequentialList<T, N>::clear() {
    m_curLen = 0;
}

template <typename T, std::size_t N>
template <typename BiFunc>
std::size_t SequentialList<T, N>::maxIndex(BiFunc comparator) const {
    std::size_t ret = 0;
    for(std::size_t index = 1; index < m_curLen; ++index) {
        if(comparator(m_data[index], m_data[ret]) == true)
            ret = index;
    }
    return ret;
}

template <typename T, std::size_t N>
template <typename BiFunc>
std::size_t SequentialList<T, N>::minIndex(BiFunc comparator) const {
    std::size_t ret = 0;
    for(std::size_t index = 1; index < m_curLen; ++index) {
        if(comparator(m_data[index], m_data[ret]) == true)
            ret = index;
    }
    return ret;
}

