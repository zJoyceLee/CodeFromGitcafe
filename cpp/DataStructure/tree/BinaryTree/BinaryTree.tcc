#pragma once

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::preOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func) {
    if(node != nullptr) {
        func(node);
        preOrder_impl(node->getLeft(), func);
        preOrder_impl(node->getRight(), func);
    }
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::inOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func) {
    if(node != nullptr) {
        preOrder_impl(node->getLeft(), func);
        func(node);
        preOrder_impl(node->getRight(), func);
    }
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::postOrder_impl(BinaryTreeNode<T> * node, UnaryFunc func) {
    if(node != nullptr) {
        preOrder_impl(node->getLeft(), func);
        preOrder_impl(node->getRight(), func);
        func(node);
    }
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::preOrder(UnaryFunc func) {
    preOrder_impl(this->getRoot(), func);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::inOrder(UnaryFunc func) {
    inOrder_impl(this->getRoot(), func);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::postOrder(UnaryFunc func) {
    postOrder_impl(this->getRoot(), func);
}

template <typename T>
template <typename UnaryFunc>
void BinaryTree<T>::levelOrder(UnaryFunc func) {

}

