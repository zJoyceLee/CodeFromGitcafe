#include "BinaryTree.hpp"
//STL
#include <iostream>
// gtest
#include <gtest/gtest.h>

TEST(NodeTest, testGetData) {
    BinaryTreeNode<int> node(1024);
    *(node.getData()) = 100;
    ASSERT_EQ(100, *(node.getData()));
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

