#pragma once

template <typename T>
class BinaryTreeNode {
private:
    T m_data;
    BinaryTreeNode * m_left;
    BinaryTreeNode * m_right;
public:
    BinaryTreeNode(const T & value) :
        m_data(value),
        m_left(nullptr),
        m_right(nullptr)
    {}

    ~BinaryTreeNode() {}

    T * getData() { return &(this->m_data); }
    const T * getData() const { return &(this->m_data); }

    BinaryTreeNode * getLeft() { return this->m_left; }
    const BinaryTreeNode * getLeft() const { return this->m_left; }

    BinaryTreeNode * getRight() { return this->m_right; }
    const BinaryTreeNode * getRight() const { return this->m_right; }
};
