#pragma once
//STL
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() :
    m_head(new LinkedListNode<T>())
{
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> & vec) :
    m_head(new LinkedListNode<T>())
{
    for(auto riter = vec.rbegin(); riter != vec.rend(); ++riter) {
        this->push_front(*riter);
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(this->m_head != nullptr) {
        LinkedListNode<T> * nextNode = this->m_head->next();
        delete this->m_head;
        this->m_head = nextNode;
    }
}

template <typename T>
LinkedListNode<T> * & LinkedList<T>::begin() {
    return m_head;
}

template <typename T>
const LinkedListNode<T> * LinkedList<T>::begin() const {
    return m_head;
}

template <typename T>
LinkedListNode<T> * & LinkedList<T>::end() {
    return nullptr;
}

template <typename T>
const LinkedListNode<T> * LinkedList<T>::end() const {
    return nullptr;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return begin()->next() == nullptr;
}

template <typename T>
LinkedListNode<T> * LinkedList<T>::findPrevNode(const LinkedListNode<T> * position) const {
    LinkedListNode<T> * temp = m_head;
    while(!(temp == nullptr || temp->next() == position))
        temp = temp->next();
    return temp;
}

template <typename T>
template <typename UnaryFunc>
LinkedListNode<T> * LinkedList<T>::find(LinkedListNode<T> * startPos, UnaryFunc check) const {
    LinkedListNode<T> * temp = startPos;
    if(temp == this->m_head)
        temp = temp->next();

    while (temp != nullptr) {
        if(check(temp->data()) == true)
            return temp;
        temp = temp->next();
    }
    return nullptr;
}

///modify:Node * p,p -> m_data.studentNum = new studentNum

template <typename T>
void LinkedList<T>::push_front(const T & element) {
    LinkedListNode<T> * pElementNode = new LinkedListNode<T>(element);
    LinkedListNode<T> * firstElem = this->m_head->next();
    this->m_head->next() = pElementNode;
    pElementNode->next() = firstElem;
}

template <typename T>
void LinkedList<T>::insertBefore(LinkedListNode<T> * position, const T & element) {
    LinkedListNode<T> * pElementNode = new LinkedListNode<T>(element);
    LinkedListNode<T> * prev = findPrevNode(position);
    prev->next() = pElementNode;
    pElementNode->next() = position;
}

template <typename T>
template <typename BiFunc>
void LinkedList<T>::insertSorted(const T & element, BiFunc comparatorLess) {
    LinkedListNode<T> * firstGreater = this->find(m_head, [&](const T & elem) {
        return comparatorLess(element, elem);
    });
    insertBefore(firstGreater, element);
}

template <typename T>
void LinkedList<T>::remove(LinkedListNode<T> * position) {
    LinkedListNode<T> * temp = this->findPrevNode(position);
    temp -> next() = position -> next();
    delete position;
}

template <typename T>
template <typename UnaryFunc>
void LinkedList<T>::traverse(UnaryFunc visitor) const {
    for(LinkedListNode<T> * cur = this->m_head->next(); cur != nullptr; cur = cur->next())
        visitor(cur->data());
}

template <typename T>
void LinkedList<T>::reversal() {
    LinkedList<T> reversedMyself;
    for(LinkedListNode<T> * cur = m_head->next(); cur != nullptr; cur = cur->next()) {
        reversedMyself.push_front(cur->data());
    }

    this->swap(reversedMyself);
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T> & rhs) {
    if(this == &rhs)
        return;

    LinkedListNode<T> * lhsPreserve = this->m_head->next();
    this->m_head->next() = rhs.m_head->next();
    rhs.m_head->next() = lhsPreserve;
}
