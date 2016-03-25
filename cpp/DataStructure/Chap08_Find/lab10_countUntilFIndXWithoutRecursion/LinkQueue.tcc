#pragma once

template <typename T>
LinkQueue<T>::LinkQueue() {
	rear = front = new Node<T>;
}

template <typename T>
LinkQueue<T>::~LinkQueue() {
	clear();
    delete front;
}

template <typename T>
int LinkQueue<T>::getLength() const {
	int count = 0;
	for (Node<T> *p = front->next; p != nullptr; p = p->next)
		count++;
	return count;
}

template <typename T>
bool LinkQueue<T>::isEmpty() const {
   return rear == front;
}

template <typename T>
void LinkQueue<T>::clear() {
	Node<T> * p = front->next;
    while (p != nullptr)	{
        front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
}

template  <typename T>
void LinkQueue<T>::traverse(void (*Visit)(const T &)) const {
	for (Node<T> *p = front->next; p != nullptr; p = p->next)
		(*Visit)(p->data);
}

template <typename T>
Status LinkQueue<T>::delQueue(T & e) {
	if(!isEmpty()) {
		Node<T> * p = front->next;
		e = p->data;
		front->next = p->next;
		if (rear == p)
			rear = front;
		delete p;
		return SUCCESS;
	} else {
		return UNDER_FLOW;
    }
}

template <typename T>
Status LinkQueue<T>::getHead(T & e) const {
	if(!isEmpty()) {
		e = front->next->data;
		return SUCCESS;
	} else {
		return UNDER_FLOW;
    }
}

template <typename T>
Status LinkQueue<T>::enQueue(const T e) {
	Node<T> * p;
    p = new Node<T>(e);
    if(p){
       rear->next = p;
	   rear = rear->next;
	   return SUCCESS;
     } else {
		return OVER_FLOW;
    }
}

template <typename T>
LinkQueue<T>::LinkQueue(const LinkQueue<T> & copy) {
	rear = front = new Node<T>;
	for (Node<T> *p = copy.front->next; p != nullptr; p = p->next)
		enQueue(p->data);
}

template <typename T>
LinkQueue<T> &LinkQueue<T>::operator =(const LinkQueue<T> & copy) {
	if(&copy != this) {
		clear();
		for (Node<T> *p = copy.front->next; p != nullptr; p = p->next)
			enQueue(p->data);
	}
	return *this;
}
