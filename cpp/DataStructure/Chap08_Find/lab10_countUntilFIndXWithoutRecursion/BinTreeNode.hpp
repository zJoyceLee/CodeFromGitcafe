#pragma once

template <typename T>
struct BinTreeNode {
	T data;
	BinTreeNode<T> * leftChild;
	BinTreeNode<T> * rightChild;


	BinTreeNode() :
       data(),
       leftChild(nullptr),
       rightChild(nullptr)
	{}

	BinTreeNode(const T & d, BinTreeNode<T> * lChild = nullptr, BinTreeNode<T> * rChild = nullptr) :
        data(d),
        leftChild(lChild),
        rightChild(rChild)
	{}
};
