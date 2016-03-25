#pragma once
// STL
#include <limits>
#include <stdexcept>
#include <algorithm>

template <typename T>
const std::size_t SequentialList<T>::npos = std::numeric_limits<std::size_t>::max();

template <typename T>
int SequentialList<T>::transformAndCheckIndex(int index) const {
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

template <typename T>
int SequentialList<T>::transformAndCheckIndexWithCurLen(int index) const {
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

template <typename T>
bool SequentialList<T>::isFull() const {
    return m_curLen == m_maxLen;
}

template <typename T>
void SequentialList<T>::expand() {
    SequentialList list2(this->m_maxLen * 2, * this);
    this->swap(list2);
}

template <typename T>
SequentialList<T>::SequentialList(const std::size_t n) :
    m_data(nullptr),
    m_curLen(0),
    m_maxLen(n)
{
    m_data = new T[m_maxLen];
}

template <typename T>
SequentialList<T>::SequentialList(const std::size_t n, const SequentialList & rhs) :
    m_data(nullptr),
    m_curLen(0),
    m_maxLen(std::max(n, rhs.getLength()))
{
    m_data = new T[m_maxLen];
    for(std::size_t i = 0; i < rhs.getLength(); ++i) {
        this->m_data[i] = rhs[i];
        ++this->m_curLen;
    }
}

template <typename T>
SequentialList<T>::~SequentialList() {
    delete[] m_data;
}

template <typename T>
void SequentialList<T>::swap(SequentialList & rhs) {
    auto tmp = this->m_data;
    this->m_data = rhs.m_data;
    rhs.m_data = tmp;

    std::swap(this->m_curLen, rhs.m_curLen);
    std::swap(this->m_maxLen, rhs.m_maxLen);
}

template <typename T>
std::size_t SequentialList<T>::getLength() const {
    return m_curLen;
}

template <typename T>
std::size_t SequentialList<T>::getCapacity() const {
    return m_maxLen;
}

template <typename T>
T & SequentialList<T>::operator[](int index) {
    index = transformAndCheckIndex(index);
    return m_data[index];
}

template <typename T>
const T & SequentialList<T>::operator[](int index) const {
    index = transformAndCheckIndex(index);
    return m_data[index];
}

template <typename T>
template <typename BiFunc>
std::size_t SequentialList<T>::find(const T & element, int startIndex, BiFunc comparator) const {
    startIndex = transformAndCheckIndex(startIndex);

    for(std::size_t index = startIndex; index < m_curLen; ++index) {
        if(comparator(element, m_data[index]) == true)
            return index;
    }
    return SequentialList::npos;
}

template <typename T>
template <typename UnaryFunc>
std::size_t SequentialList<T>::find(int startIndex, UnaryFunc checker) const {
    startIndex = transformAndCheckIndex(startIndex);

    for(std::size_t index = startIndex; index < m_curLen; ++index) {
        if(checker(m_data[index]) == true)
            return index;
    }
    return SequentialList::npos;
}

template <typename T>
template <typename UnaryFunc>
std::vector<std::size_t> SequentialList<T>::findAll(UnaryFunc checker) const {
    std::vector<std::size_t> ret;

    std::size_t index;
    int startPosition = 0;
    do {
        index = find(startPosition, checker);
        if(index == SequentialList<T>::npos)
            break;
        ret.push_back(index);
        startPosition = index + 1;
    } while(true);
    return ret;
}

template <typename T>
void SequentialList<T>::insert(const T & element, int position) {

    if(isFull())
        expand();

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
        for(std::size_t index = m_curLen - 1; index > position; --index){
            m_data[index + 1] = m_data[index];
        }
        m_data[position + 1] = m_data[position];
    }//if

    /// 3. work
    m_data[position] = element;
    ++m_curLen;
}

template <typename T>
template <typename BiFunc>
void SequentialList<T>::insertSorted(const T & element, BiFunc comparator) {
    std::size_t index = 0;
    for(index = 0; index < m_curLen; ++index) {
        if(comparator(element, m_data[index]) == true)
            break;
    }
    insert(element, index);

    if(isFull())
        expand();
}

template <typename T>
void SequentialList<T>::push_back(const T & element) {
    insert(element, m_curLen);

    if(isFull())
        expand();
}

template <typename T>
void SequentialList<T>::remove(int position) {
    position = transformAndCheckIndex(position);

    if(position >= m_curLen) {
        throw std::out_of_range("position out of range!");
    }
    for(std::size_t index = position; index < m_curLen - 1; ++index){
        m_data[index] = m_data[index + 1];
    }
    --m_curLen;
}

template <typename T>
bool SequentialList<T>::isEmpty() const {
    return (m_curLen == 0);
}

template <typename T>
void SequentialList<T>::clear() {
    m_curLen = 0;
}

template <typename T>
template <typename UnaryFunc>
void SequentialList<T>::traverse(UnaryFunc visitor) const {
    for(std::size_t i = 0; i < getLength(); ++i) {
        visitor(m_data[i]);
    }
}

template <typename T>
template <typename BiFunc>
std::size_t SequentialList<T>::maxIndex(BiFunc comparator) const {
    std::size_t ret = 0;
    for(std::size_t index = 1; index < m_curLen; ++index) {
        if(comparator(m_data[index], m_data[ret]) == true)
            ret = index;
    }
    return ret;
}

template <typename T>
template <typename BiFunc>
std::size_t SequentialList<T>::minIndex(BiFunc comparator) const {
    std::size_t ret = 0;
    for(std::size_t index = 1; index < m_curLen; ++index) {
        if(comparator(m_data[index], m_data[ret]) == true)
            ret = index;
    }
    return ret;
}


