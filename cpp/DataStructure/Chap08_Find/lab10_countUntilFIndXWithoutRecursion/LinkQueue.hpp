#pragma once
//Current Project
#include "Assistance.hpp"
#include "Node.hpp"

template <typename T>
class LinkQueue {
private:
	Node<T> * front, * rear;

public:
	LinkQueue();
	~LinkQueue();
	int getLength() const;
	bool isEmpty() const;
	void clear();
	void traverse(void (*Visit)(const T &)) const ;
	Status delQueue(T & e);
	Status getHead(T & e) const;
	Status enQueue(const T e);
	LinkQueue(const LinkQueue<T> & copy);
	LinkQueue<T> &operator =(const LinkQueue<T> & copy);
};

#include "LinkQueue.tcc"
