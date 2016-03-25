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
template <typename UnaryFunc>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * r, UnaryFunc & Visit) const {
	if (r != nullptr) {
		Visit(r->data);
		PreOrder(r->leftChild, Visit);
		PreOrder(r->rightChild, Visit);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PreOrder(BinTreeNode<T> * r, const UnaryFunc & Visit) const {
	if (r != nullptr) {
		Visit(r->data);
		PreOrder(r->leftChild, Visit);
		PreOrder(r->rightChild, Visit);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PreOrder(UnaryFunc & Visit) const {
	PreOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PreOrder(const UnaryFunc & Visit) const {
	PreOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::InOrder(BinTreeNode<T> *r, UnaryFunc & Visit) const {
	if (r != nullptr) {
		InOrder(r->leftChild, Visit);
		Visit(r->data);
		InOrder(r->rightChild, Visit);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::InOrder(BinTreeNode<T> *r, const UnaryFunc & Visit) const {
	if (r != nullptr) {
		InOrder(r->leftChild, Visit);
		Visit(r->data);
		InOrder(r->rightChild, Visit);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::InOrder(UnaryFunc & Visit) const {
	InOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::InOrder(const UnaryFunc & Visit) const {
	InOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *r, UnaryFunc & Visit) const {
	if (r != nullptr) {
		PostOrder(r->leftChild, Visit);
		PostOrder(r->rightChild, Visit);
		Visit(r->data);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PostOrder(BinTreeNode<T> *r, const UnaryFunc & Visit) const {
	if (r != nullptr) {
		PostOrder(r->leftChild, Visit);
		PostOrder(r->rightChild, Visit);
		Visit(r->data);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PostOrder(UnaryFunc & Visit) const {
	PostOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::PostOrder(const UnaryFunc & Visit) const {
	PostOrder(root, Visit);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::LevelOrder(UnaryFunc & Visit) const {
	LinkQueue<BinTreeNode<T> *> q;
	BinTreeNode<T> * p;

	if (root != nullptr)
        q.EnQueue(root);
	while (!q.IsEmpty()) {
		q.DelQueue(p);
		Visit(p->data);
		if (p->leftChild != nullptr)
			q.EnQueue(p->leftChild);
		if (p->rightChild != nullptr)
			q.EnQueue(p->rightChild);
	}
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::LevelOrder(const UnaryFunc & Visit) const {
	LinkQueue<BinTreeNode<T> *> q;
	BinTreeNode<T> * p;

	if (root != nullptr)
        q.EnQueue(root);
	while (!q.IsEmpty()) {
		q.DelQueue(p);
		Visit(p->data);
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
//--------------------------------------------------------------------------------------
//(1) countLeaf :
template <typename T>
int BinaryTree<T>::countLeaf(const BinTreeNode<T> * r) const {
    if (r ==nullptr)
        return 0;
    else if(r->leftChild == nullptr && r->rightChild == nullptr)
        return 1;
	else
        return countLeaf(r->leftChild) + countLeaf(r->rightChild);
}
template <typename T>
int BinaryTree<T>::countLeaf() const {
    return countLeaf(root);
}

//---------------------------------------------------------------------------------------
//(2) revolute() :
template <typename T>
void BinaryTree<T>::preOrderRevolute(BinTreeNode<T>* thisNode, BinTreeNode<T> * cpNode) {
    if(thisNode == nullptr)
        return;
    if(thisNode->rightChild != nullptr)
        InsertLeftChild(cpNode, thisNode->rightChild->data);
    if(thisNode->leftChild != nullptr)
        InsertRightChild(cpNode, thisNode->leftChild->data);

    preOrderRevolute(thisNode->leftChild, cpNode->rightChild);
    preOrderRevolute(thisNode->rightChild, cpNode->leftChild);
}

template <typename T>
BinaryTree<T> BinaryTree<T>::revolute() {
    BinaryTree<T> ret;
    ret.root = new BinTreeNode<T>(this->root->data);
    preOrderRevolute(this->root, ret.root);
    return ret;
}

//---------------------------------------------------------------------------------------
//(3) countBreadth() :
template <typename T>
//void BinaryTree<T>::printNodeByLevel(BinTreeNode<T> * root) {
void BinaryTree<T>::printMaxBreadth(BinTreeNode<T> * root) {
    if(root == nullptr)
        return;
    std::vector<BinTreeNode<T> *> vec;
    vec.push_back(root);
    std::size_t cur = 0;
    std::size_t last = 1;
    std::vector<std::size_t> breadth;
    while(cur < vec.size()) {
        last = vec.size();
        std::size_t number = 0;
        while(cur < last) {
            //std::cout << vec[cur]->data <<" ";

            if(vec[cur]->leftChild != nullptr)
                vec.push_back(vec[cur]->leftChild);
            if(vec[cur]->rightChild != nullptr)
                vec.push_back(vec[cur]->rightChild);
            ++cur;
            ++number;
        }
        breadth.push_back(number);
        //std::cout << std::endl;
    }
    std::size_t maxBreadth = 0;
    for(auto it = breadth.begin(); it != breadth.end(); ++it) {
        //std::cout << *it << " " ;
        if(maxBreadth < *it)
            maxBreadth = *it;
    }
    std::cout << maxBreadth;
}

template <typename T>
void BinaryTree<T>::countBreadth() {
    printMaxBreadth(root);
}

//---------------------------------------------------------------------------------------
//(4) nonRecursingInOrder() :
template <typename T>
void BinaryTree<T>::nonRecursingInOrder(const BinTreeNode<T> * root, void (*Visit)(const T &)) const {
    std::vector<const BinTreeNode<T> *> virtualStack;
    if(root == nullptr)
        return;

    // start off
    const BinTreeNode<T> * node = root;
    virtualStack.push_back(root);
    do {
        // left recurse
        node = node->leftChild;
        while(node != nullptr) {
            virtualStack.push_back(node);
            node = node->leftChild;
        }

        // visit the parent node
        do {
            if(virtualStack.empty())
                break;
            node = virtualStack.back();
            virtualStack.pop_back();
            Visit(node->data);
        } while(node->rightChild == nullptr);

        // get the right child
        if(node->rightChild != nullptr) {
            node = node->rightChild;
            virtualStack.push_back(node);
        }
    } while(!virtualStack.empty());
}

template <typename T>
void BinaryTree<T>::nonRecursingInOrder(void (*Visit)(const T &)) const {
    nonRecursingInOrder(root, Visit);
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
template <typename T>
void DisplayBTWithTreeShape(BinTreeNode<T> * r, int level) {
	if(r != nullptr) {
		DisplayBTWithTreeShape<T>(r->rightChild, level + 1);
		std::cout << std::endl;
		for(int i = 0; i < level - 1; i++)
			std::cout << "  ";
		std::cout << r->data;
		DisplayBTWithTreeShape<T>(r->leftChild, level + 1);
	}
}

template <typename T>
void DisplayBTWithTreeShape(BinaryTree<T> & bt) {
	DisplayBTWithTreeShape<T>(bt.GetRoot(), 1);
	//std::cout << std::endl;
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
BinaryTree<T> & CreateBinaryTree(const std::vector<T> & pre, const std::vector<T> & in) {
	int n = int(pre.size());
	BinTreeNode<T> * r;
	CreateBinaryTree<T>(r, pre, in, 0, n - 1, 0, n - 1);

	BinaryTree<T> * bt = new BinaryTree<T>(r);
	return * bt;
}
