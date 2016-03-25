#pragma once

template <typename T>
SeqStack<T>::SeqStack(const std::size_t sz) :
    m_lst(sz)
{
}

template <typename T>
SeqStack<T>::SeqStack(const SeqStack & rhs) :
    m_lst(rhs.m_lst)
{
}

template <typename T>
SeqStack<T>::~SeqStack() {
}

template <typename T>
std::size_t SeqStack<T>::getLength() const {
    return m_lst.getLength();
}

template <typename T>
std::size_t SeqStack<T>::getCapacity() const {
    return m_lst.getCapacity();
}

template <typename T>
void SeqStack<T>::push(const T & element) {
    m_lst.insert(element, 0);
}

template <typename T>
void SeqStack<T>::popOnce() {
    m_lst.remove(0);
}

template <typename T>
void SeqStack<T>::pop(std::size_t popTimes) {
    for(auto i = popTimes; i > 0; --i) {
        if(m_lst.isEmpty()) {
            throw std::out_of_range("Stack is empty now.");
        }
            popOnce();
    }
}

template <typename T>
bool SeqStack<T>::isEmpty() const {
    return m_lst.isEmpty();
}

template <typename T>
template <typename UnaryFunc>
void SeqStack<T>::traverse(UnaryFunc visitor) const {
    m_lst.traverse(visitor);
}
