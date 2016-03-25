#pragma once
//STL
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() :
    m_head(new Node<T>())
{
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> & vec) :
    m_head(new Node<T>())
{
    for(auto riter = vec.rbegin(); riter != vec.rend(); ++riter) {
        this->push_front(*riter);
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(this->m_head != nullptr) {
        Node<T> * nextNode = this->m_head->next();
        delete this->m_head;
        this->m_head = nextNode;
    }
}

template <typename T>
Node<T> * & LinkedList<T>::begin() {
    return m_head;
}

template <typename T>
const Node<T> * LinkedList<T>::begin() const {
    return m_head;
}

template <typename T>
Node<T> * & LinkedList<T>::end() {
    return nullptr;
}

template <typename T>
const Node<T> * LinkedList<T>::end() const {
    return nullptr;
}

template <typename T>
Node<T> * LinkedList<T>::findPrevNode(const Node<T> * position) const {
    Node<T> * temp = m_head;
    while(!(temp == nullptr || temp->next() == position))
        temp = temp->next();
    return temp;
}

template <typename T>
template <typename UnaryFunc>
Node<T> * LinkedList<T>::find(Node<T> * startPos, UnaryFunc check) const {
    Node<T> * temp = startPos;
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
    Node<T> * pElementNode = new Node<T>(element);
    Node<T> * firstElem = this->m_head->next();
    this->m_head->next() = pElementNode;
    pElementNode->next() = firstElem;
}

template <typename T>
void LinkedList<T>::insertBefore(Node<T> * position, const T & element) {
    Node<T> * pElementNode = new Node<T>(element);
    Node<T> * prev = findPrevNode(position);
    prev->next() = pElementNode;
    pElementNode->next() = position;
}

template <typename T>
template <typename BiFunc>
void LinkedList<T>::insertSorted(const T & element, BiFunc comparatorLess) {
    /*
    if(m_head->next() == nullptr){
        push_front(element);
        return;
    }
    Node<T> * temp = m_head;
    for(temp = m_head; temp->next() != nullptr; temp = temp->next()) {
        if(comparator(element) == true)
            break;
    }
    insertBefore(temp, element);
    */
    Node<T> * firstGreater = this->find(m_head, [&](const T & elem) {
        return comparatorLess(element, elem);
    });
    insertBefore(firstGreater, element);
}

template <typename T>
void LinkedList<T>::remove(Node<T> * position) {
    Node<T> * temp = this->findPrevNode(position);
    temp -> next() = position -> next();
    delete position;
}

template <typename T>
template <typename UnaryFunc>
void LinkedList<T>::traverse(UnaryFunc visitor) {
    for(Node<T> * cur = this->m_head->next(); cur != nullptr; cur = cur->next())
        visitor(cur->data());
}

template <typename T>
void LinkedList<T>::reversal() {
    LinkedList<T> reversedMyself;
    for(Node<T> * cur = m_head->next(); cur != nullptr; cur = cur->next()) {
        reversedMyself.push_front(cur->data());
    }

    this->swap(reversedMyself);
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T> & rhs) {
    if(this == &rhs)
        return;

    Node<T> * lhsPreserve = this->m_head->next();
    this->m_head->next() = rhs.m_head->next();
    rhs.m_head->next() = lhsPreserve;
}

