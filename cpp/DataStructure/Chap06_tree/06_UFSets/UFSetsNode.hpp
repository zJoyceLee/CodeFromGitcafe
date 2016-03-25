#pragma once

template <typename T>
struct UFSetsNode {
    T data;
    int parentIndex;
};

template <typename T>
bool operator==(const UFSetsNode<T> & lhs, const UFSetsNode<T> & rhs) {
    return (lhs.data == rhs.data) && (lhs.parentIndex == rhs.parentIndex);
}
