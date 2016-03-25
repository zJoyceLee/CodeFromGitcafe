#pragma once

template <typename T>
SeqQueue<T>::SeqQueue() :
    m_lst()
{
}

template <typename T>
SeqQueue<T>::SeqQueue(const SeqQueue & rhs) :
    m_lst(rhs.m_lst)
{
}

template <typename T>
~SeqQueue() {
}

template <typename T>
bool SeqQueue<T>::isEmpty() const {
    return m_lst.isEmpty();
}

template <typename T>
void SeqQueue<T>::eQueue(const T & element) {
    m_lst.push_front(element);
}

template <typename T>
void SeqQueue<T>::dQueue() {
    m_lst.remove(m_lst.end());
}

