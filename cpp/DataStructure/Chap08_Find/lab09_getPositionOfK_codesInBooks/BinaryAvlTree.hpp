#pragma once
//Current Project
#include "Assistance.hpp"
#include "LinkQueue.hpp"
#include "LinkStack.hpp"
#include "BinAvlTreeNode.hpp"

// 平衡二叉树类
template <typename T>
class BinaryAVLTree
{
protected:
//  平衡二叉树的数据成员:
	BinAVLTreeNode<T> *root;

//	辅助函数:
	BinAVLTreeNode<T> *CopyTreeHelp(BinAVLTreeNode<T> *  copy);	// 复制平衡二叉树
	void DestroyHelp(BinAVLTreeNode<T> * & r);						// 销毁以r为根的平衡二叉树
	void PreOrderHelp(BinAVLTreeNode<T> * r, void (*Visit)(const T & )) const;	// 先序遍历以r为根的平衡二叉树
	void InOrderHelp(BinAVLTreeNode<T> * r, void (*Visit)(const T & )) const;	// 中序遍历以r为根的平衡二叉树
	void PostOrderHelp(BinAVLTreeNode<T> * r, void (*Visit)(const T & )) const;	// 后序遍历以r为根的平衡二叉树
    int HeightHelp(const BinAVLTreeNode<T> * r) const;				// 求以r为根的平衡二叉树的高
	int NodeCountHelp(const BinAVLTreeNode<T> * r) const;				// 求以r为根的平衡二叉树的结点个数
	BinAVLTreeNode<T> * ParentHelp(BinAVLTreeNode<T> * r,
		const BinAVLTreeNode<T> * p) const;							// 在以r为根的平衡二叉树中求p的双亲
	BinAVLTreeNode<T> * Find(const T & key, BinAVLTreeNode<T> *& f) const;
		// 查找关键字为key的数据元素,返回指向关键字为key的元素的指针,用f返回其双亲.

	BinAVLTreeNode<T> *Find(const T & key, BinAVLTreeNode<T> *& f,
		LinkStack<BinAVLTreeNode<T> *> & s);
		 // 查找关键字为key的数据元素,返回指向关键字为key的元素的指针,并用f返回其双亲,栈s存储查找路径.

	BinAVLTreeNode<T> *Find(const T & key, BinAVLTreeNode<T> *& f,
		BinAVLTreeNode<T> *& a, BinAVLTreeNode<T> *& af);
		 // 查找关键字为key的数据元素,返回指向关键字为key的元素的指针,并用f返回其双亲,a为离插入结点最近的平衡因子不等于0的结点,af是a的双亲.

	void LeftRotate(BinAVLTreeNode<T> *& subRoot);
		// 对以subRoot为根的二叉树作左旋处理,处理之后subRoot指向新的树根结点,也就是旋转处理前的右子树的根结点
	void RightRotate(BinAVLTreeNode<T> *& subRoot);
		// 对以subRoot为根的二叉树作右旋处理,处理之后subRoot指向新的树根结点,也就是旋转处理前的左子树的根结点
	void DeleteLeftBalance(BinAVLTreeNode<T> *& subRoot, bool & isShorter);
		// 对以subRoot为根的二叉树删除时作左平衡处理,处理后subRoot指向新的树根结点
	void DeleteRightBalance(BinAVLTreeNode<T> *& subRoot, bool & isShorter);
		// 对以subRoot为根的二叉树删除时作右平衡处理,处理后subRoot指向新的树根结点
	void DeleteBalance(const T & key, LinkStack<BinAVLTreeNode<T> *> & s);
		// 从删除结点根据查找路径进行回溯,并作平衡处理
	void DeleteHelp(const T & key, BinAVLTreeNode<T> *& p,
		LinkStack< BinAVLTreeNode<T> *> & s);		// 删除p指向的结点

public:
//  平衡二叉树方法声明及重载编译系统默认方法声明:
	BinaryAVLTree();											// 无参数的构造函数
	virtual ~BinaryAVLTree();									// 析构函数
	BinAVLTreeNode<T> *GetRoot() const;					// 返回平衡二叉树的根
	bool isEmpty() const;										// 判断平衡二叉树是否为空
	Status GetElem(BinAVLTreeNode<T> *p, T & e) const;
		// 用e返回结点数据元素值
	Status SetElem(BinAVLTreeNode<T> *p, const T & e);
		// 将结p的值置为e
	void InOrder(void (*Visit)(const T & )) const;		// 平衡二叉树的中序遍历
	void PreOrder(void (*Visit)(const T & )) const;		// 平衡二叉树的先序遍历
	void PostOrder(void (*Visit)(const T & )) const;		// 平衡二叉树的后序遍历
	void LevelOrder(void (*Visit)(const T & )) const;		// 平衡二叉树的层次遍历
	int NodeCount() const;										// 求平衡二叉树的结点个数
	BinAVLTreeNode<T> *Find(const T & key) const;	// 查找关键字为key的数据元素
	bool Insert(const T & e);								// 插入数据元素e
	bool Delete(const T & key);							// 删除关键字为key的数据元素
	BinAVLTreeNode<T> *LeftChild(const BinAVLTreeNode<T> *p) const;
		// 返回平衡二叉树结点p的左孩子
	BinAVLTreeNode<T> *RightChild(const BinAVLTreeNode<T> *p) const;
		// 返回平衡二叉树结点p的右孩子
	BinAVLTreeNode<T> *Parent(const BinAVLTreeNode<T> *p) const;
		// 返回平衡二叉树结点p的双亲
	int	Height() const;											// 求平衡二叉树的高
	BinaryAVLTree(const T & e);							// 建立以e为根的平衡二叉树
	BinaryAVLTree(const BinaryAVLTree<T> & copy);			// 复制构造函数
	BinaryAVLTree(BinAVLTreeNode<T> *r);					// 建立以r为根的平衡二叉树
	BinaryAVLTree<T> & operator=(const BinaryAVLTree<T>&  copy);	// 赋值语句重载
};

#include "BinaryAvlTree.tcc"
