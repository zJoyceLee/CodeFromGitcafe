#pragma once
#include "Assistance.hpp"
#include "Node.hpp"

template<typename T>
class LinkStack {
private:
	Node<T> * top;

public:
	LinkStack();
	~LinkStack();
	std::size_t getLength() const;
	bool isEmpty() const;
	void clear();
	void traverse(void (*Visit)(const T &)) const ;
	Status push(const T e);
	Status Top(T & e) const;
	Status pop(T & e);
	LinkStack(const LinkStack<T> & s);
	LinkStack<T> & operator =(const LinkStack<T> & s);
};

#include "LinkStack.tcc"
