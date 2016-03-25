#pragma once

template <typename T>
void DisplayBTWithTreeShapeHelp(const BinTreeNode<T> *r, int level);

template <typename T>
void DisplayBTWithTreeShape(const BinarySortTree<T> &bt);

template <typename T>
BinarySortTree<T>::BinarySortTree() {
	root = nullptr;
}

template <typename T>
BinarySortTree<T>::~BinarySortTree() {
	Destroy(root);
}

template <typename T>
BinTreeNode<T> * BinarySortTree<T>::GetRoot() const {
	return root;
}

template <typename T>
bool BinarySortTree<T>::isEmpty() const {
	return root == nullptr;
}

template <typename T>
Status BinarySortTree<T>::GetElem(BinTreeNode<T> * p, T & e) const {
	if (p == nullptr) {
		return NOT_PRESENT;
	} else {
		e = p->data;
		return ENTRY_FOUND;
	}
}

template <typename T>
Status BinarySortTree<T>::SetElem(BinTreeNode<T> * p, const T & e) {
	if (p == nullptr) {
		return FAIL;
    } else {
		p->data = e;
		return SUCCESS;
	}
}

template <typename T>
void BinarySortTree<T>::PreOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const {
	if (r != nullptr) {
		(*Visit)(r->data);
		PreOrder(r->leftChild, Visit);
		PreOrder(r->rightChild, Visit);
	}
}

template <typename T>
void BinarySortTree<T>::PreOrder(void (*Visit)(const T &)) const {
	PreOrder(root, Visit);
}

template <typename T>
void BinarySortTree<T>::InOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const {
	if (r != nullptr) {
		InOrder(r->leftChild, Visit);
		(*Visit)(r->data);
		InOrder(r->rightChild, Visit);
	}
}

template <typename T>
void BinarySortTree<T>::InOrder(void (*Visit)(const T &)) const {
	InOrder(root, Visit);
}

template <typename T>
void BinarySortTree<T>::PostOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const{
	if (r != nullptr) {
		PostOrder(r->leftChild, Visit);
		PostOrder(r->rightChild, Visit);
		(*Visit)(r->data);
	}
}

template <typename T>
void BinarySortTree<T>::PostOrder(void (*Visit)(const T &)) const {
	PostOrder(root, Visit);
}

template <typename T>
void BinarySortTree<T>::LevelOrder(void (*Visit)(const T &)) const {
	LinkQueue<BinTreeNode<T> *> q;
	BinTreeNode<T> * t = root;

	if (t != nullptr)
        q.EnQueue(t);
	while (!q.isEmpty()) {
		q.DelQueue(t);
		(*Visit)(t->data);
		if (t->leftChild != nullptr)
			q.EnQueue(t->leftChild);
		if (t->rightChild != nullptr)
			q.EnQueue(t->rightChild);
	}
}

template <typename T>
int BinarySortTree<T>::Height(const BinTreeNode<T> * r) const {
	if(r == nullptr) {
		return 0;
	} else {
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);
		rHeight = Height(r->rightChild);
		return 1 + (lHeight > rHeight ? lHeight : rHeight);
	}
}

template <typename T>
int BinarySortTree<T>::Height() const {
	return Height(root);
}

template <typename T>
BinarySortTree<T>::BinarySortTree(const T & e) {
	root = new BinTreeNode<T>(e);
}

template <typename T>
int BinarySortTree<T>::NodeCount(const BinTreeNode<T> *r) const {
	if (r ==nullptr)
        return 0;
	else
        return 1 + NodeCount(r->leftChild) + NodeCount(r->rightChild);
}

template <typename T>
int BinarySortTree<T>::NodeCount() const {
	return NodeCount(root);
}

template <typename T>
BinTreeNode<T> * BinarySortTree<T>::LeftChild(const BinTreeNode<T> * p) const {
	return p->leftChild;
}

template <typename T>
BinTreeNode<T> * BinarySortTree<T>::RightChild(const BinTreeNode<T> * p) const {
	return p->rightChild;
}

template <typename T>
BinTreeNode<T> * BinarySortTree<T>::Parent(BinTreeNode<T> * r, const BinTreeNode<T> * p) const {
	if(r == nullptr) {
        return nullptr;
	} else if(r->leftChild == p || r->rightChild == p) {
        return r;
	} else {
		BinTreeNode<T> * tmp;
		tmp = Parent(r->leftChild, p);
		if (tmp != nullptr)
           return tmp;

		tmp = Parent(r->rightChild, p);
		if (tmp != nullptr)
           return tmp;
		else
           return nullptr;
	}
}

template <typename T>
BinTreeNode<T> *BinarySortTree<T>::Parent(const BinTreeNode<T> * p) const {
	return Parent(root, p);
}

template <typename T>
BinTreeNode<T> *BinarySortTree<T>::Find(const T & key, BinTreeNode<T> *&f) const {
	BinTreeNode<T> * p = GetRoot();
	f = nullptr;

	while (p != nullptr && p->data != key)	{
		if(key < p->data) {
	        std::cout << "smaller than" << p->data << std::endl;
			f = p;
			p = p->leftChild;
		} else {
	        std::cout << "bigger than" << p->data << std::endl;
			f = p;
			p = p->rightChild;
		}
	}
	return p;
}

template <typename T>
BinTreeNode<T> *BinarySortTree<T>::Find(const T & key)	const {
	BinTreeNode<T> *f;
	return Find(key, f);
}

template <typename T>
bool BinarySortTree<T>::Insert(const T & e) {
	BinTreeNode<T> * f;

	std::cout << "find process of insert" << e << std::endl;
	if(Find(e, f) == nullptr) {
		BinTreeNode<T> * p;
		p = new BinTreeNode<T>(e);
		if(isEmpty())
			root = p;
		else if(e < f->data)
			f->leftChild = p;
		else
			f->rightChild = p;
		return true;
	} else {
		return false;
    }
}

template <typename T>
void BinarySortTree<T>::Delete(BinTreeNode<T> *&p) {
	BinTreeNode<T> * tmpPtr, * tmpF;
	if(p->leftChild == nullptr && p->rightChild == nullptr) {
		delete p;
		p = nullptr;
	} else if(p->leftChild == nullptr) {
		tmpPtr = p;
		p = p->rightChild;
		delete tmpPtr;
	} else if(p->rightChild == nullptr) {
		tmpPtr = p;
		p = p->leftChild;
		delete tmpPtr;
	} else {
		tmpF = p;
		tmpPtr = p->leftChild;
		while(tmpPtr->rightChild != nullptr) {
			tmpF = tmpPtr;
			tmpPtr = tmpPtr->rightChild;
		}
		p->data = tmpPtr->data;

		if (tmpF->rightChild == tmpPtr)
			Delete(tmpF->rightChild);
		else
			Delete(tmpF->leftChild);
	}
}

template <typename T>
bool BinarySortTree<T>::Delete(const T & key) {
	BinTreeNode<T> * p, * f;
	p = Find(key, f);
	if( p == nullptr) {
		return false;
	} else {
		if(f == nullptr)
			Delete(p);
		else if (key < f->data)
			Delete(f->leftChild);
		else
			Delete(f->rightChild);
		return true;
    }
}

template <typename T>
void BinarySortTree<T>::Destroy(BinTreeNode<T> *&r) {
	if(r != nullptr) {
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r = nullptr;
	}
}

template <typename T>
BinTreeNode<T> * BinarySortTree<T>::CopyTree(BinTreeNode<T> * copy) {
	if (copy == nullptr) {
		return nullptr;
	} else {
		BinTreeNode<T> * lChild = CopyTree(copy->leftChild);
		BinTreeNode<T> * rChild = CopyTree(copy->rightChild);
		BinTreeNode<T> * r = new BinTreeNode<T>(copy->data, lChild, rChild);
		return r;
	}
}

template <typename T>
BinarySortTree<T>::BinarySortTree(const BinarySortTree<T> & copy) {
	root = CopyTree(copy.root);
}

template <typename T>
BinarySortTree<T>::BinarySortTree(BinTreeNode<T> * r) {
	root = r;
}

template <typename T>
BinarySortTree<T> & BinarySortTree<T>::operator=(const BinarySortTree<T> & copy) {
	if(&copy != this) {
		Destroy(root);
		root = CopyTree(copy.root);
	}
	return *this;
}

template <typename T>
void DisplayBTWithTreeShapeHelp(const BinTreeNode<T> * r, int level) {
	if(r != nullptr) {
		DisplayBTWithTreeShapeHelp<T>(r->rightChild, level + 1);
		std::cout << std::endl << std::endl;
		for(int i = 0; i < level - 1; i++)
			std::cout << "   ";
		std::cout << r->data;
		DisplayBTWithTreeShapeHelp<T>(r->leftChild, level + 1);
	}
}

template <typename T>
void DisplayBTWithTreeShape(const BinarySortTree<T> & bt) {
	DisplayBTWithTreeShapeHelp<T>(bt.GetRoot(), 1);
	std::cout << std::endl;
}

