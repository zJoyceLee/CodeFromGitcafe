#pragma once

template<typename T>
LinkStack<T>::LinkStack() {
	top = nullptr;
}

template<typename T>
LinkStack<T>::~LinkStack() {
	clear();
}

template <typename T>
std::size_t LinkStack<T>::getLength() const {
	std::size_t count = 0;
	Node<T> *p;
	for (p = top; p != nullptr; p = p->next)
		count++;
	return count;
}

template<typename T>
bool LinkStack<T>::isEmpty() const {
	return top == nullptr;
}

template<typename T>
void LinkStack<T>::clear() {
	Node<T> * p;
	while(top != nullptr) {
		p = top;
		top = top->next;
		delete p;
	}
}

template <typename T>
void LinkStack<T>::traverse(void (*Visit)(const T &)) const {
	Node<T> * p;
	for (p = top; p != nullptr; p = p->next)
		(*Visit)(p->data);
}

template<typename T>
Status LinkStack<T>::push(const T e) {
	Node<T> * p = new Node<T>(e, top);
	if (p == nullptr) {
		return OVER_FLOW;
	} else {
		top = p;
		return SUCCESS;
	}
}

template<typename T>
Status LinkStack<T>::Top(T & e) const {
	if(isEmpty()) {
		return UNDER_FLOW;
	} else {
		e = top->data;
		return SUCCESS;
	}
}

template<typename T>
Status LinkStack<T>::pop(T & e) {
	if(isEmpty()) {
		return UNDER_FLOW;
	} else {
		Node<T> * p = top;
		e = top->data;
		top = top->next;
		delete p;
		return SUCCESS;
	}
}

template<typename T>
LinkStack<T>::LinkStack(const LinkStack<T> & s) {
	if (s.isEmpty()) {
		top = nullptr;
	} else {
		top = new Node<T>(s.top->data);
		Node<T> * q = top;
		for (Node<T> *p = s.top->next; p != nullptr; p = p->next){
			q->next = new Node<T>(p->data);
			q = q->next;
		}
	}
}


template<typename T>
LinkStack<T> &LinkStack<T>::operator = (const LinkStack<T> & s) {
	if (&s != this)	{
		clear();
   		if(!s.isEmpty()) {
			top = new Node<T>(s.top->data);
			Node<T> *q = top;
			for(Node<T> *p = s.top->next; p != nullptr; p = p->next) {
                q->next = new Node<T>(p->data);
				q = q->next;
			}
		}
	}
	return *this;
}
