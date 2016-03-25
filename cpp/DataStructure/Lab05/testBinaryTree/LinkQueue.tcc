#pragma once

template<typename T>
LinkQueue<T>::LinkQueue() :
    front(),
    rear()
{
	rear = front = new Node<T>;
}

template<typename T>
LinkQueue<T>::~LinkQueue() {
	Clear();
    delete front;
}

template<typename T>
int LinkQueue<T>::GetLength() const {
	int count = 0;
	for (Node<T> *p = front->next; p != NULL; p = p->next)
		count++;
	return count;
}

template<typename T>
bool LinkQueue<T>::IsEmpty() const {
   return rear == front;
}

template<typename T>
void LinkQueue<T>::Clear() {
	Node<T> *p = front->next;
    while (p != NULL) {
        front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
}

template <typename T>
void LinkQueue<T>::Traverse(void (*Visit)(const T &)) const {
	for (Node<T> *p = front->next; p != NULL; p = p->next)
		(*Visit)(p->data);
}

template<typename T>
Status LinkQueue<T>::DelQueue(T & e) {
	if (!IsEmpty()) {
		Node<T> *p = front->next;
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

template<typename T>
Status LinkQueue<T>::GetHead(T & e) const {
	if (!IsEmpty()) {
		e = front->next->data;
		return SUCCESS;
	} else {
		return UNDER_FLOW;
    }
}

template<typename T>
Status LinkQueue<T>::EnQueue(const T e) {
	Node<T> *p;
    p = new Node<T>(e);
    if (p) {
       rear->next = p;
	   rear = rear->next;
	   return SUCCESS;
     } else {
		return OVER_FLOW;
    }
}

template<typename T>
LinkQueue<T>::LinkQueue(const LinkQueue<T> &copy) {
	rear = front = new Node<T>;
	for (Node<T> *p = copy.front->next; p != NULL; p = p->next)
		EnQueue(p->data);
}

template<typename T>
LinkQueue<T> &LinkQueue<T>::operator =(const LinkQueue<T> &copy) {
	if(&copy != this) {
		Clear();
		for(Node<T> *p = copy.front->next; p != NULL; p = p->next)
			EnQueue(p->data);
	}
	return *this;
}
