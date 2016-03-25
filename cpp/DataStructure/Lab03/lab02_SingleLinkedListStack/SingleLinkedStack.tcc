#pragma once
//STL
#include <stdexcept>

template <typename T>
SingleLinkedStack<T>::SingleLinkedStack() :
    m_lst()
{
}

template <typename T>
SingleLinkedStack<T>::SingleLinkedStack(const SingleLinkedStack<T> & rhs) :
    m_lst(rhs.m_lst)
{
}

template <typename T>
SingleLinkedStack<T>::~SingleLinkedStack() {
}

template <typename T>
void SingleLinkedStack<T>::popOnce() {
    m_lst.remove(m_lst.begin()->next());
}

template <typename T>
bool SingleLinkedStack<T>::isEmpty() {
    return m_lst.isEmpty();
}

template <typename T>
void SingleLinkedStack<T>::push(const T & element){
    m_lst.push_front(element);
}

template <typename T>
void SingleLinkedStack<T>::pop(std::size_t popTimes) {
    for(auto i = popTimes; i > 0; --i) {
        if(m_lst.isEmpty()) {
            throw std::out_of_range("Stack is empty now.");
        }
            popOnce();
    }


}
//passing ‘const LinkedList<CarInfo>’ as ‘this’ argument of ‘void LinkedList<T>::remove(LinkedListNode<T>*) [with T = CarInfo]’ discards qualifiers [-fpermissive]|

template <typename T>
template <typename UnaryFunc>
void SingleLinkedStack<T>::traverse(UnaryFunc visitor) const {
    m_lst.traverse(visitor);
}
