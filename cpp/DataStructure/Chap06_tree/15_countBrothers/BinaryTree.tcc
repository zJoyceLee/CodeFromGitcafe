#pragma once

template <typename T>
BinaryTree<T>::BinaryTree() :
    root(nullptr)
{
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	Destroy(root);
}

template <typename T>
BinTreeNode<T> *BinaryTree<T>::GetRoot() const {
	return root;
}

template <typename T>
bool BinaryTree<T>::IsEmpty() const {
	return root == nullptr;
}

template <typename T>
Status BinaryTree<T>::GetElem(BinTreeNode<T> * p, T & e) const {
	if (p == nullptr) {
		return NOT_PRESENT;
    } else {
		e = p->data;
		return ENTRY_FOUND;
	}
}

template <typename T>
Status BinaryTree<T>::SetElem(BinTreeNode<T> * p, const T & e) {
	if (p == nullptr) {
		return FAIL;
    } else {
		p->data = e;
		return SUCCESS;
	}
}

template <typename T>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * r, void (*Visit)(const T &)) const {
	if (r != nullptr) {
		(*Visit)(r->data);
		PreOrder(r->leftChild, Visit);
		PreOrder(r->rightChild, Visit);
	}
}

template <typename T>
void BinaryTree<T>::PreOrder(void (*Visit)(const T &)) const {
	PreOrder(root, Visit);
}

template <typename T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *r, void (*Visit)(const T &)) const {
	if (r != nullptr) {
		InOrder(r->leftChild, Visit);
		(*Visit)(r->data);
		InOrder(r->rightChild, Visit);
	}
}

template <typename T>
void BinaryTree<T>::InOrder(void (*Visit)(const T &)) const {
	InOrder(root, Visit);
}

template <typename T>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *r, void (*Visit)(const T &)) const {
	if (r != nullptr) {
		PostOrder(r->leftChild, Visit);
		PostOrder(r->rightChild, Visit);
		(*Visit)(r->data);
	}
}

template <typename T>
void BinaryTree<T>::PostOrder(void (*Visit)(const T &)) const {
	PostOrder(root, Visit);
}

template <typename T>
void BinaryTree<T>::LevelOrder(void (*Visit)(const T &)) const {
	LinkQueue<BinTreeNode<T> *> q;
	BinTreeNode<T> * p;

	if (root != nullptr)
        q.EnQueue(root);
	while (!q.IsEmpty()) {
		q.DelQueue(p);
		(*Visit)(p->data);
		if (p->leftChild != nullptr)
			q.EnQueue(p->leftChild);
		if (p->rightChild != nullptr)
			q.EnQueue(p->rightChild);
	}
}

template <typename T>
int BinaryTree<T>::Height(const BinTreeNode<T> * r) const {
	if(r == nullptr) {
		return 0;
    } else {
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);
		rHeight = Height(r->rightChild);
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
	}
}

template <typename T>
int BinaryTree<T>::Height() const {
	return Height(root);
}

template <typename T>
BinaryTree<T>::BinaryTree(const T & e) {
	root = new BinTreeNode<T>(e);
}

template <typename T>
int BinaryTree<T>::NodeCount(const BinTreeNode<T> * r) const {
	if (r ==nullptr)
       return 0;
	else
       return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;
}

template <typename T>
int BinaryTree<T>::NodeCount() const {
	return NodeCount(root);
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::LeftChild(const BinTreeNode<T> * p) const {
	return p->leftChild;
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::RightChild(const BinTreeNode<T> * p) const {
	return p->rightChild;
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::LeftSibling(const BinTreeNode<T> * p) const {
    BinTreeNode<T> * r = Parent(root, p);
    if (r == nullptr)
       return nullptr;
    else if (r->rightChild == p)
	   return r->leftChild;
    else
       return nullptr;
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::RightSibling(const BinTreeNode<T> * p) const {
    BinTreeNode<T> * r = Parent(root, p);
    if (r == nullptr)
       return nullptr;
    else if (r->leftChild == p)
	   return r->rightChild;
    else
       return nullptr;
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::Parent(BinTreeNode<T> * r, const BinTreeNode<T> * p) const {
	if (r == nullptr)
       return nullptr;
	else if (r->leftChild == p || r->rightChild == p)
       return r;
	else	{
		BinTreeNode<T> *tmp;
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
BinTreeNode<T> * BinaryTree<T>::Parent(const BinTreeNode<T> * p) const {
	return Parent(root, p);
}

template <typename T>
void BinaryTree<T>::InsertLeftChild(BinTreeNode<T> * p, const T & e) {
	if (p == nullptr) {
		return;
    } else {
		BinTreeNode<T> * child =  new BinTreeNode<T>(e);
		if (p->leftChild != nullptr)
			child->leftChild = p->leftChild;
		p->leftChild = child;
		return;
	}
}

template <typename T>
void BinaryTree<T>::InsertRightChild(BinTreeNode<T> * p, const T & e) {
	if (p == nullptr) {
		return;
	} else {
		BinTreeNode<T> * child =  new BinTreeNode<T>(e);
		if (p->rightChild != nullptr)
			child->rightChild = p->rightChild;
		p->rightChild = child;
		return;
	}
}

template <typename T>
void BinaryTree<T>::DeleteLeftChild(BinTreeNode<T> * p) {
	if (p == nullptr)
		return;
	else
		Destroy(p->leftChild);
}

template <typename T>
void BinaryTree<T>::DeleteRightChild(BinTreeNode<T> * p) {
	if (p == nullptr)
		return;
	else
		Destroy(p->rightChild);
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::Find(const T & e) const {
	LinkQueue<BinTreeNode<T> *> q;
	BinTreeNode<T> * p;

	if (root != nullptr) q.EnQueue(root);
	while (!q.IsEmpty()) {
		q.DelQueue(p);
		if (p->data == e)
			return p;
		if (p->leftChild != nullptr)
			q.EnQueue(p->leftChild);
		if (p->rightChild != nullptr)
			q.EnQueue(p->rightChild);
	}
	return nullptr;
}


template <typename T>
void BinaryTree<T>::Destroy(BinTreeNode<T> * & r){
	if(r != nullptr) {
		Destroy(r->leftChild);
		Destroy(r->rightChild);
		delete r;
		r = nullptr;
	}
}

template <typename T>
BinTreeNode<T> * BinaryTree<T>::CopyTree(BinTreeNode<T> * t)
{
	if (t == nullptr) {
		return nullptr;
    } else {
		BinTreeNode<T> * lChild = CopyTree(t->leftChild);
		BinTreeNode<T> * rChild = CopyTree(t->rightChild);
		BinTreeNode<T> * r = new BinTreeNode<T>(t->data, lChild, rChild);

		return r;
	}
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> & t) {
	root = CopyTree(t.root);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinTreeNode<T> * r) {
	root = r;
}

template <typename T>
BinaryTree<T> & BinaryTree<T>::operator=(const BinaryTree<T> & t) {
	if (&t != this)	{
		Destroy(root);
		root = CopyTree(t.root);
	}
	return *this;
}

//---------------------------------------------------------------------------------------
template <typename T>
std::size_t BinaryTree<T>::countBrothers(const std::vector<T> & vec) {
    std::size_t finalBrotherNum = 0;
    for(std::size_t i = 0; i < vec.size(); ++i) {
        std::size_t brother = 1;
        BinTreeNode<T> * mynode = Find(vec[i]);
        if(mynode == this->GetRoot())
            continue;

        while(mynode->rightChild != nullptr) {
            mynode = mynode->rightChild;
            ++brother;
        }
        if(finalBrotherNum < brother) {
            finalBrotherNum = brother;
        }
    }
    return finalBrotherNum;
}

template <typename T>
void CreateBinaryTree(BinTreeNode<T> * & r, std::vector<T> pre, std::vector<T> in, int preLeft, int preRight, int inLeft, int inRight) {
	if (inLeft > inRight) {
        r = nullptr;
	}
	else {
		r = new BinTreeNode<T>(pre[preLeft]);
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
			mid++;
		CreateBinaryTree(r->leftChild, pre, in, preLeft+1, preLeft + mid - inLeft, inLeft, mid - 1);

		CreateBinaryTree(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1,
			inRight);
	}
}

template <typename T>
BinaryTree<T> & CreateBinaryTree(const std::vector<T> &pre, const std::vector<T> &in) {
    std::size_t n = pre.size();
	BinTreeNode<T> * r;
	CreateBinaryTree<T>(r, pre, in, 0, n - 1, 0, n - 1);

	BinaryTree<T> * bt = new BinaryTree<T>(r);
	return * bt;
}

template <typename T>
std::size_t countDepth(BinTreeNode<T> * node) {
    std::size_t leftDepth = 0, rightDepth = 0;
    if(node == nullptr)
        return 0;
    if(node->leftChild == nullptr && node->rightChild == nullptr)
        return 1;
    if(node->leftChild != nullptr) {
        leftDepth = 1 + countDepth(node->leftChild);
    }
    if(node->rightChild != nullptr) {
        rightDepth = countDepth(node->rightChild);
    }
    return std::max(leftDepth, rightDepth);
}
