#pragma once
//STL
#include <vector>
//Current-Project
#include "BinaryTreeNode.hpp"

template <typename T>
class BinaryTree {
private:
    BinaryTreeNode<T> m_root;

private:
    template <typename UnaryFunc>
    void preOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func);

    template <typename UnaryFunc>
    void inOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func);

    template <typename UnaryFunc>
    void postOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func);

public:
    BinaryTree(const T & value) :
        m_root(value)
    {}

    BinaryTree(const std::vector<T> & pre_vec, const std::vector<T> & in_vec) :
        m_root(pre_vec.begin())
    {

    }

    ~BinaryTree() {}

    BinaryTreeNode<T> * getRoot() { return &(this->m_root); }
    const BinaryTreeNode<T> * getRoot() const { return &(this->m_root); }

    template <typename UnaryFunc>
    void preOrder(UnaryFunc func);

    template <typename UnaryFunc>
    void inOrder(UnaryFunc func);

    template <typename UnaryFunc>
    void postOrder(UnaryFunc func);

    template <typename UnaryFunc>
    void levelOrder(UnaryFunc func);
};

#include "BinaryTree.tcc"
