#pragma once

template <typename T>
void assert_eq_LinkedList_vector(const LinkedList<T> & lst, const std::vector<T> & vec) {
    /// indexCounter is used to calculate the index of node
    std::size_t indexCounter = 0;

    const LinkedListNode<T> * node = lst.begin();
    typename std::vector<T>::const_iterator vecIter = vec.begin();
    while(node != lst.end()) {
        ASSERT_EQ(*vecIter, node->data())
            << "lhs LinkedList and rhs vector are not equal, index: " << std::to_string(indexCounter) << std::endl
            << "lst: " << to_string(lst) << std::endl
            << "vec: " << to_string(vec);

        node = node->next();
        ++vecIter;
        ++indexCounter;
    }//while
}

template <typename T>
void assert_eq_LinkedList_LinkedList(const LinkedList<T> & lhs, const LinkedList<T> & rhs) {
    /// indexCounter is used to calculate the index of node
    std::size_t indexCounter = 0;

    const LinkedListNode<T> * lhsNode = lhs.begin();
    const LinkedListNode<T> * rhsNode = rhs.begin();
    while(lhsNode != lhs.end() && rhsNode != rhs.end()) {
        ASSERT_EQ(lhsNode->data(), rhsNode->data())
            << "lhs and rhs LinkedList are not equal, index: " << std::to_string(indexCounter) << std::endl
            << "lhs: " << to_string(lhs) << std::endl
            << "rhs: " << to_string(rhs);

        lhsNode = lhsNode->next();
        rhsNode = rhsNode->next();
        ++indexCounter;
    }//while

    /// if `lhs` and `rhs` are of different size, the check may succeed under such circumstances:
    ///     lhs: [1, 2, 3, 4]
    ///     rhs: [1, 2, 3, 4, 5]
    /// so we must ensure that `lhs` and `rhs` both reach the end(), in other words, with the same size.
    ASSERT_EQ(lhsNode, lhs.end()) << "lhs LinkedList is bigger in size" << std::endl
        << "lhs: " << to_string(lhs) << std::endl
        << "rhs: " << to_string(rhs);
    ASSERT_EQ(rhsNode, rhs.end()) << "rhs LinkedList is bigger in size" << std::endl
        << "lhs: " << to_string(lhs) << std::endl
        << "rhs: " << to_string(rhs);
}

template <typename T>
std::string to_string(const LinkedList<T> & lst) {
    std::ostringstream oss;
    oss << "[";
    lst.traverse([&] (const T & data) { oss << data << ","; });
    oss << "\b]";
    return oss.str();
}

template <typename T>
std::string to_string(const std::vector<T> & vec) {
    std::ostringstream oss;
    oss << "[";
    for(auto i : vec)
        oss << i << ",";
    oss << "\b]";
    return oss.str();
}
