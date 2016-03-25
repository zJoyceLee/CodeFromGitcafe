//STL
#include <iostream>
#include <vector>
//Current Project
#include "BinaryTree.hpp"
//gtest
#include "gtest/gtest.h"

template <typename T>
bool isBinarySearchTree(const std::vector<T> & inorder) {
    for(std::size_t i = 0; i < inorder.size() - 1; ++i) {
        T now = inorder[i];
        T post = inorder[i + 1];
        if(now > post) {
            return false;
        }
    }
    return true;
}

class InOrderToVectorHelper {
public:
    InOrderToVectorHelper() : m_inOrderVec() {}

    InOrderToVectorHelper(const std::vector<int> & vec) : m_inOrderVec(vec) {}

    void operator()(const int & element) { toVector(element, m_inOrderVec); }

    std::vector<int> & data() { return m_inOrderVec; }

    std::vector<int> m_inOrderVec;
};

//#ifdef _gtest
TEST(BST, testInOrderFail) {
    std::vector<int> pre = {0,1,3,7,8,4,9,2,5,6};
	std::vector<int>  in = {7,3,8,1,9,4,0,5,2,6};
	BinaryTree<int> bt;
	bt = CreateBinaryTree(pre, in);

#ifdef USE_CLASS
	InOrderToVectorHelper inOrderHelper;
	bt.InOrder(inOrderHelper);
	std::vector<int> & inOrderVec = inOrderHelper.data();
#else
    std::vector<int> inOrderVec;
    bt.InOrder([&inOrderVec](const int & element) {
        toVector(element, inOrderVec);
    });
#endif
	EXPECT_EQ(0, isBinarySearchTree(inOrderVec));
}

TEST(BST, testInOrderSuccess) {
    std::vector<int> pre = {4,2,1,3,5,6};
	std::vector<int>  in = {1,2,3,4,5,6};
	BinaryTree<int> bt;
	bt = CreateBinaryTree(pre, in);

    std::vector<int> inOrderVec;
    bt.InOrder([&inOrderVec](const int & element) {
        toVector(element, inOrderVec);
    });
	EXPECT_EQ(1, isBinarySearchTree(inOrderVec));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
//#endif //_gtest
