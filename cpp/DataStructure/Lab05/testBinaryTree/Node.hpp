#pragma once

template <typename T>
struct Node
{
	T data;
	Node<T> * next;

	Node() :
        data(),
        next(nullptr)
    {}

	Node(T item, Node<T> * link = nullptr) :
        data(item),
        next(link)
    {}
};
