#pragma once
#include "LinkQueue.hpp"
#include "BinTreeNode.hpp"

template <typename T>
class BinarySortTree {
private:
	BinTreeNode<T> * root;

	BinTreeNode<T> * CopyTree(BinTreeNode<T> * r);
	void Destroy(BinTreeNode<T> * &r);
	void PreOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const;
	void InOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const;
	void PostOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const;
    int Height(const BinTreeNode<T> * r) const;
	int NodeCount(const BinTreeNode<T> * r) const;
	BinTreeNode<T> * Parent(BinTreeNode<T> * r, const BinTreeNode<T> * p) const;
	BinTreeNode<T> * Find(const T & key, BinTreeNode<T> *&f) const;

	void Delete(BinTreeNode<T> *&p);

public:
	BinarySortTree();
	~BinarySortTree();
	BinTreeNode<T> * GetRoot() const;
	bool isEmpty() const;
	Status GetElem(BinTreeNode<T> *p, T &e) const;

	Status SetElem(BinTreeNode<T> *p, const T &e);

	void InOrder(void (*Visit)(const T &)) const;
	void PreOrder(void (*Visit)(const T &)) const;
	void PostOrder(void (*Visit)(const T &)) const;
	void LevelOrder(void (*Visit)(const T &)) const;
	int NodeCount() const;
	BinTreeNode<T> * Find(const T & key) const;
	bool Insert(const T & e);
	bool Delete(const T & key);
	BinTreeNode<T> * LeftChild(const BinTreeNode<T> * p) const;

	BinTreeNode<T> * RightChild(const BinTreeNode<T> * p) const;

	BinTreeNode<T> * Parent(const BinTreeNode<T> * p) const;

	int	Height() const;
	BinarySortTree(const T & e);
	BinarySortTree(const BinarySortTree<T> & copy);
	BinarySortTree(BinTreeNode<T> * r);
	BinarySortTree<T> & operator=(const BinarySortTree<T> & copy);
};

#include "BinarySortTree.tcc"
