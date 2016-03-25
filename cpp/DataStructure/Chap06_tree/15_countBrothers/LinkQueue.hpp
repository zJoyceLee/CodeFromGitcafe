#pragma once
#include "Assistance.hpp"
#include "Node.hpp"

template<typename T>
class LinkQueue {
protected:
	Node<T> *front, *rear;

public:
	LinkQueue();
	~LinkQueue();
	int GetLength() const;
	bool IsEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const T &)) const ;
	Status DelQueue(T &e);
	Status GetHead(T &e) const;
	Status EnQueue(const T e);
	LinkQueue(const LinkQueue<T> &copy);
	LinkQueue<T> &operator =(const LinkQueue<T> &copy);
};

#include "LinkQueue.tcc"
