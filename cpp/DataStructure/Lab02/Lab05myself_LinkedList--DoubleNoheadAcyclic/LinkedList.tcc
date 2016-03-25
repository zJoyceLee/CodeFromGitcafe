#pragma once

template <typename T>
LinkedList<T>::LinkedList() :
    m_data(nullptr)
{
}

template <typename T>
LinkedList<T>::LinkedList(const std::vector<T> & vec) :
    m_data(nullptr)
{
    for(auto riter = vec.rbegin(); riter != vec.rend(); ++riter)
        this->push_front(*riter);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList & rhs) :
    m_data(nullptr)
{
    this->m_data = new LinkedListNode<T>(rhs.m_data->data());

    LinkedListNode<T> * lhsCur = m_data;
    const LinkedListNode<T> * rhsCur = rhs.begin()->next();
    while(rhsCur != rhs.end()) {
        this->insertAfter(lhsCur,rhsCur->data());
        lhsCur = lhsCur->next();
        rhsCur = rhsCur->next();
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while(this->m_data != nullptr) {
        auto nextElement = this->m_data->next();
        delete this->m_data;
        this->m_data = nextElement;
    }
}

template <typename T>
void LinkedList<T>::push_front(const T & element) {
    auto pElementNode = new LinkedListNode<T>(element);

    if(this->m_data == nullptr) {
        this->m_data = pElementNode;
        return;
    }//if

    auto firstElement = this->m_data;
    pElementNode->next() = firstElement;
    firstElement->prev() = pElementNode;
    this->m_data = pElementNode;
}

template <typename T>
void LinkedList<T>::insertBefore(LinkedListNode<T> * position, const T & element) {
    auto prevNode = position->prev();

    if(prevNode == nullptr) {
        //insert before "head"
        this->push_front(element);
    } else {
        auto pElementNode = new LinkedListNode<T>(element);

        pElementNode->prev() = prevNode;
        pElementNode->next() = position;

        prevNode->next() = pElementNode;
        position->prev() = pElementNode;
    }
}

template <typename T>
void LinkedList<T>::insertAfter(LinkedListNode<T> * position, const T & element) {
    auto pElementNode = new LinkedListNode<T>(element);
    auto nextNode = position->next();

    if(nextNode == nullptr) {
        //insert at the end
        position->next() = pElementNode;
        pElementNode->prev() = position;
    } else {
        pElementNode->prev() = position;
        pElementNode->next() = pElementNode;

        position->next() = pElementNode;
        nextNode->prev() = pElementNode;
    }
}

template <typename T>
void LinkedList<T>::remove(LinkedListNode<T> * position) {
    auto prevNode = position->prev();
    auto nextNode = position->next();

    if(prevNode == nullptr) {
        nextNode->prev() = nullptr;
        this->m_data = nextNode;
    } else if(nextNode == nullptr) {
        prevNode->next() = nullptr;
    } else {
        prevNode->next() = nextNode;
        nextNode->prev() = prevNode;
    }

    delete position;

}

template <typename T>
template <typename UnaryFunc>
LinkedListNode<T> * LinkedList<T>::find(LinkedListNode<T> * startPosition, UnaryFunc checker) const {
    for(auto cur = startPosition; cur != nullptr; cur = cur->next()) {
        if(checker(cur->data()))
            return cur;
    }
    return nullptr;
}

template <typename T>
template <typename UnaryFunc>
void LinkedList<T>::traverse(UnaryFunc visitor) const {
    for(auto cur = m_data; cur != nullptr; cur = cur->next())
        visitor(cur->data());
}

template <typename T>
template <typename BinaryFunc>
void LinkedList<T>::swapMinMax(BinaryFunc comparatorLess) {
    auto maxDataNode = m_data;
    auto minDataNode = m_data;

    for(auto cur = m_data; cur != nullptr; cur = cur->next()) {
        if(comparatorLess(maxDataNode->data(), cur->data()))
            maxDataNode = cur;
        if(comparatorLess(cur->data(), minDataNode->data()))
            minDataNode = cur;
    }
    std::swap(maxDataNode->data(), minDataNode->data());
}
