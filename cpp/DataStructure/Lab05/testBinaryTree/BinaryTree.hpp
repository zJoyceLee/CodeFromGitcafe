#pragma once
//STL
#include <vector>
//Current Project
#include "LinkQueue.hpp"
#include "BinTreeNode.hpp"

template <typename T>
class BinaryTree {
private:
	BinTreeNode<T> * root;

	BinTreeNode<T> * CopyTree(BinTreeNode<T> * t);

	void Destroy(BinTreeNode<T> * & r);
	void PreOrder(BinTreeNode<T> * r,void(*Visit)(const T &)) const;

	void InOrder(BinTreeNode<T> * r,void (*Visit)(const T &)) const;

	void PostOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const;
    int Height(const BinTreeNode<T> * r) const;

	int NodeCount(const BinTreeNode<T> * r) const;

	BinTreeNode<T> * Parent(BinTreeNode<T> * r, const BinTreeNode<T> * p) const;

public:
	BinaryTree();
	BinaryTree(const T & e);
	~BinaryTree();
	BinTreeNode<T> * GetRoot() const;
	bool IsEmpty() const;
	Status GetElem(BinTreeNode<T> *p, T &e) const;

	Status SetElem(BinTreeNode<T> *p, const T &e);

	void InOrder(void (*Visit)(const T &)) const;
	void PreOrder(void (*Visit)(const T &)) const;
	void PostOrder(void (*Visit)(const T &)) const;
	void LevelOrder(void (*Visit)(const T &)) const;
	int NodeCount() const;
	BinTreeNode<T> *LeftChild(const BinTreeNode<T> *p) const;

	BinTreeNode<T> *RightChild(const BinTreeNode<T> *p) const;

	BinTreeNode<T> *LeftSibling(const BinTreeNode<T> *p) const;

	BinTreeNode<T>*RightSibling(const BinTreeNode<T>*p) const;

	BinTreeNode<T> *Parent(const BinTreeNode<T> *p) const;

	BinTreeNode<T> *Find(const T & e) const;

	void InsertLeftChild(BinTreeNode<T> * p, const T & e);

	void InsertRightChild(BinTreeNode<T> * p, const T & e);

	void DeleteLeftChild(BinTreeNode<T> * p);
	void DeleteRightChild(BinTreeNode<T> * p);
	int	Height() const;
	BinaryTree(const BinaryTree<T> & t);
	BinaryTree(BinTreeNode<T> * r);
	BinaryTree<T> & operator=(const BinaryTree<T> & t);
//--------------------------------------------------------------------
	int countLeaf(const BinTreeNode<T> * r) const;
	int countLeaf() const;
//--------------------------------------------------------------------
	BinaryTree<T> revolute();
	void preOrderRevolute(BinTreeNode<T> * thisNode, BinTreeNode<T> * cpNode);
//--------------------------------------------------------------------
    void printMaxBreadth(BinTreeNode<T> * root);
    void countBreadth();
//--------------------------------------------------------------------
    void nonRecursingInOrder(const BinTreeNode<T> * root, void (*Visit)(const T &)) const;
    void nonRecursingInOrder(void (*Visit)(const T &)) const;

};

template <typename T>
void DisplayBTWithTreeShape(BinTreeNode<T> * r, int level);

template <typename T>
void DisplayBTWithTreeShape(BinaryTree<T> & bt);

template <typename T>
void CreateBinaryTree(BinTreeNode<T> * & r, std::vector<T> pre, std::vector<T> in,
	int preLeft, int preRight, int inLeft, int inRight);

template <typename T>
BinaryTree<T> & CreateBinaryTree(std::vector<T> pre, std::vector<T> in, int n);

#include "BinaryTree.tcc"
