//STL
#include <iostream>
#include <vector>
//Current Project
#include "BinaryTree.hpp"

template <typename T>
void printVec(std::vector<T> myvec) {
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        std::cout << *it;
    }
    std::cout << ". " ;
}

template <typename T>
void printTest(BinaryTree<T> btree, std::vector<T> vec1, std::vector<T> vec2) {
    std::cout << "make up by : ";
    printVec(vec1);
    printVec(vec2);
    DisplayBTWithTreeShape<T>(btree);
    std::cout << std::endl;
    std::cout << "preOrder   : ";
        btree.PreOrder(Write<T>);
            std::cout << std::endl;
    std::cout << "inOrder    : ";
        btree.InOrder(Write<T>);
            std::cout << std::endl;
    std::cout << "posteOrder : ";
        btree.PostOrder(Write<T>);
            std::cout << std::endl;
    std::cout << "levelOrder : ";
        btree.LevelOrder(Write<T>);
            std::cout << std::endl;
    std::cout << "nodeCount  : " << btree.NodeCount() << std::endl;
    std::cout << "treeHeight : " << btree.Height() << std::endl;
    //------------------------------------------------------------------------
    std::cout << "(1) countLeaves : " << btree.countLeaf();
    //------------------------------------------------------------------------
    BinaryTree<T> btreeRevolute = btree.revolute();
    std::cout << std::endl << "(2) BinaryTree Revolute: ";
    DisplayBTWithTreeShape<T>(btreeRevolute);
    std::cout << std::endl;
    //------------------------------------------------------------------------
    //btree.printMaxBreadth(btree.GetRoot());
	std::cout << "(3) countBreadth : ";
         btree.countBreadth();
            std::cout << std::endl;
    //------------------------------------------------------------------------
    std::cout << "(4)   InOrd: ";
        btree.InOrder(Write<char>);
            std::cout << std::endl;
    std::cout << "(4) nRInOrd: ";
        btree.nonRecursingInOrder(Write<char>);
            std::cout << std::endl;
    //------------------------------------------------------------------------
}

int main(int argc, char * argv[])
{
	std::vector<char> pre{'A','B','D','E','G','H','C','F','I'}; //pre
	std::vector<char> in{'D','B','G','E','H','A','C','F','I'};  // in
	int n = 9;						                  //node number
	BinaryTree<char> bt;
	bt = CreateBinaryTree(pre, in, n);           //make up binary tree
	printTest(bt, pre, in);

	pre = std::vector<char>{'A','B','C','D','E','F','G'};
	in  = std::vector<char>{'G','F','E','D','C','B','A'};
	n = pre.size();
	bt = CreateBinaryTree(pre, in, n);
	printTest(bt, pre, in);

	pre = std::vector<char>{'A','B','C','D','E','F','G'};
	in  = std::vector<char>{'A','B','C','D','E','F','G'};
	n = pre.size();
	bt = CreateBinaryTree(pre, in, n);
	printTest(bt, pre, in);

	pre = std::vector<char>{'A','B','C','D','E','F','G','H','I','J'};
	in  = std::vector<char>{'G','F','E','D','I','J','H','C','B','A'};
	n = pre.size();
	bt = CreateBinaryTree(pre, in, n);
	printTest(bt, pre, in);

	pre = std::vector<char>{'A','B','C','H','J','I','D','E','F','G'};
	in  = std::vector<char>{'A','B','J','H','I','C','D','E','F','G'};
	n = pre.size();
	bt = CreateBinaryTree(pre, in, n);
	printTest(bt, pre, in);

    std::cout << std::endl;
	return 0;
}

