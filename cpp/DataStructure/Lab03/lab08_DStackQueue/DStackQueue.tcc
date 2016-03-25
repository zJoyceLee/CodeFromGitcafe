#pragma once
#include "DStackQueue.hpp"

template <typename T>
void DStackQueue<T>::push(const T & value) {
    // if front is empty, just push into back
    // if front is not, pour everything into back first,
    //    then push value into back
    if(!this->m_stkFront.isEmpty())
        this->pourToBack();
    this->m_stkBack.push(value);
}

template <typename T>
void DStackQueue<T>::pop() {
    if(!this->m_stkBack.isEmpty())
        this->pourToFront();
    this->m_stkFront.popOnce();
}

template <typename T>
T & DStackQueue<T>::front() {
    if(!this->m_stkBack.isEmpty())
        this->pourToFront();
    return this->m_stkFront.top();
}

template <typename T>
const T & DStackQueue<T>::front() const {
    if(!this->m_stkBack.isEmpty())
        this->pourToFront();
    return this->m_stkFront.top();
}

template <typename T>
T & DStackQueue<T>::back() {
    if(!this->m_stkFront.isEmpty())
        this->pourToBack();
    return this->m_stkBack.top();
}

template <typename T>
const T & DStackQueue<T>::back() const {
    if(!this->m_stkFront.isEmpty())
        this->pourToBack();
    return this->m_stkBack.top();
}

template <typename T>
bool DStackQueue<T>::empty() const {
    return (this->m_stkBack.isEmpty() && this->m_stkFront.isEmpty());
}

template <typename T>
std::size_t DStackQueue<T>::size() const {
    if(!this->m_stkFront.isEmpty())
        return this->m_stkFront.getLength();
    return this->m_stkBack.getLength();
}

template <typename T>
template <typename UnaryFunc>
void DStackQueue<T>::traverseF2B(UnaryFunc unary) {
    if(this->m_stkFront.isEmpty())
        this->pourToFront();
    this->m_stkFront.traverse(unary);
}

template <typename T>
template <typename UnaryFunc>
void DStackQueue<T>::traverseB2F(UnaryFunc unary) {
    if(this->m_stkBack.isEmpty())
        this->pourToBack();
    this->m_stkBack.traverse(unary);
}

template <typename T>
void DStackQueue<T>::pourToFront() {
    this->m_stkBack.traverse([&](const T & item) {
        this->m_stkFront.push(item);
    });
    this->m_stkBack.clear();
}

template <typename T>
void DStackQueue<T>::pourToBack() {
    this->m_stkFront.traverse([&](const T & item) {
        this->m_stkBack.push(item);
    });
    this->m_stkFront.clear();
}
