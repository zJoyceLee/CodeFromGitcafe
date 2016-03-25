//STL
#include <iostream>
#include <vector>
//C-Standard
#include <cassert>
//Current Project
#include "Assistance.hpp"
#include "BinTreeNode.hpp"
#include "BinaryTree.hpp"
#include "helper.hpp"
//gtest
#include "gtest/gtest.h"

enum class EGthanXStatus : int {
    Check = 0,
    AllYes,
    AllNo
};

void EGthanX_impl(const BinTreeNode<int> * root, const int x, std::vector<int> & vec) {
    if(root == nullptr)
        return;

    const int & rootData = root->data;
    if(rootData > x) {
        EGthanX_impl(root->rightChild, x, vec);
        vec.push_back(rootData);
        EGthanX_impl(root->leftChild,  x, vec);
    } else if(rootData < x) {
        EGthanX_impl(root->rightChild, x, vec);
        // throw away rootData
        // don't need the check on left children since they're all less than x
        return;
    } else if(rootData == x){
        // don't need the check because right children are least equal to rootData
        EGthanX_impl(root->rightChild, x, vec);
        vec.push_back(rootData);
        // check on left children that are equal to rootData
        EGthanX_impl(root->leftChild,  x, vec);
    } else {
        assert(false && "path unreachable");
    }
}


std::vector<int> EGthanX(const BinaryTree<int> & BST, const int x) {
    std::vector<int> ret;
    EGthanX_impl(BST.GetRoot(), x, ret);
    return ret;
}

TEST(beEqualOrGreaterThanX, test1) {
    std::vector<int> pre = {4,2,1,3,5,6};
	std::vector<int>  in = {1,2,3,4,5,6};
	BinaryTree<int> bt = CreateBinaryTree(pre, in);

    std::vector<int> result;

    result = EGthanX(bt, 3);
    assert_eq_vector({6,5,4,3}, result);

    result = EGthanX(bt, 1);
    assert_eq_vector({6,5,4,3,2,1}, result);

    result = EGthanX(bt, 7);
    assert_eq_vector({}, result);

    result = EGthanX(bt, -10);
    assert_eq_vector({6,5,4,3,2,1}, result);
}

TEST(beEqualOrGreaterThanX, test2) {
    std::vector<int> pre = { 61, 59,  6, 60, 99, 72,101};
	std::vector<int>  in = {  6, 59, 60, 61, 72, 99,101};
	BinaryTree<int> bt = CreateBinaryTree(pre, in);

    std::vector<int> result;

    result = EGthanX(bt, 3);
    assert_eq_vector({101, 99, 72, 61, 60, 59,  6}, result);

    result = EGthanX(bt, 61);
    assert_eq_vector({101, 99, 72, 61}, result);

    result = EGthanX(bt, 101);
    assert_eq_vector({101}, result);

    result = EGthanX(bt, 120);
    assert_eq_vector({}, result);

    result = EGthanX(bt, 6);
    assert_eq_vector({101, 99, 72, 61, 60, 59,  6}, result);
}

#if false
TEST(beEqualOrGreaterThanX, test3) {
    std::vector<int> pre = {5,5,0,0,0,5,9,9,9};
	std::vector<int>  in = {0,0,0,5,5,5,9,9,9};
	BinaryTree<int> bt = CreateBinaryTree(pre, in);

    std::vector<int> result;

    result = EGthanX(bt, 5);
    assert_eq_vector({9,9,9,5,5,5}, result);

    result = EGthanX(bt, 0);
    assert_eq_vector({9,9,9,5,5,5,0,0,0}, result);

    result = EGthanX(bt, 101);
    assert_eq_vector({}, result);

    result = EGthanX(bt, 9);
    assert_eq_vector({9,9,9}, result);
}
#endif

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
