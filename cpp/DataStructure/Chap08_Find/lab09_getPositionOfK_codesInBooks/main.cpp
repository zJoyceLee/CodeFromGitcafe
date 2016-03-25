//STL
#include <iostream>
#include <vector>
//Current-Project
#include "BinaryAvlTree.hpp"
//g-test
#include "gtest/gtest.h"

///lsize = the node num of leftTree + 1
///find no.k 's position
int main(int argc, char * argv[])
{
    try
	{
		BinaryAVLTree<int> bt;
		int elem[] = {11, 39, 23, 68, 85, 8, 3, 46, 27, 50};
		int n = 10;

		std::cout << "从空树开始依次插入元素{11, 39, 23, 68, 85, 8, 3, 46, 27, 50}，构造二叉平衡树。" << std::endl;
		for (int i = 0; i < n; i++) {
			std::cout << "插入第" << i + 1 << "元素" << elem[i] << std::endl;
			bt.Insert(elem[i]);
            DisplayBTWithTreeShape(bt);
		    std::cout << std::endl;

        }

		std::cout << "构造的二叉平衡树，括号内的数字为结点的平衡因子:" << std::endl;
		DisplayBTWithTreeShape(bt);
		std::cout << std::endl;


		std::cout << "结点数:" << bt.NodeCount();
		std::cout << std::endl;


		std::cout << "先序遍历:" << std::endl;
		bt.PreOrder(Write<int>);
		std::cout << std::endl;


		std::cout << "中序遍历:" << std::endl;
		bt.InOrder(Write<int>);
		std::cout << std::endl;


		std::cout << "后序遍历:" << std::endl;
		bt.PostOrder(Write<int>);
		std::cout << std::endl;


		std::cout << "层次遍历:" << std::endl;
		bt.LevelOrder(Write<int>);
		std::cout << std::endl;


		bt.Insert(25);
		std::cout << "插入数据元素25后:" << std::endl;
		DisplayBTWithTreeShape(bt);
		std::cout << std::endl;


		bt.Delete(23);
		std::cout << "删除数据元素23后:" << std::endl;
		DisplayBTWithTreeShape(bt);
		std::cout << std::endl;


		bt.Delete(8);
		std::cout << "删除数据元素8后:" << std::endl;
		DisplayBTWithTreeShape(bt);
		std::cout << std::endl;
	}
	catch (Error err)
	{
		err.Show();
	}
	return 0;
}

