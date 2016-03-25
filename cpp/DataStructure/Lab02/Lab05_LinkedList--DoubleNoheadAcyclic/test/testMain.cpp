// gtest
#include <gtest/gtest.h>
// STL
#include <iostream>
#include <vector>
#include <algorithm>
// Current Project
#include "../LinkedList.hpp"
// Current Test
#include "helper.hpp"

TEST(LinkedListNodeTest, constructor) {
    LinkedListNode<int> node;

    ASSERT_EQ(0, node.data());
    ASSERT_EQ(nullptr, node.prev());
    ASSERT_EQ(nullptr, node.next());
}

TEST(LinkedListNodeTest, PrevNext) {
    LinkedListNode<int> node;
    LinkedListNode<int> node2;

    node.next() = &node2;
    node2.prev() = &node;

    ASSERT_EQ(nullptr, node.prev());
    ASSERT_EQ(&node2, node.next());
    ASSERT_EQ(&node, node2.prev());
    ASSERT_EQ(nullptr, node2.next());
}

TEST(LinkedListNodeTest, data) {
    LinkedListNode<int> node;
    ASSERT_EQ(0, node.data());
    node.data() = 100;
    ASSERT_EQ(100, node.data());
}

TEST(LinkedList, BeginEnd) {
    LinkedList<int> lst;
    ASSERT_EQ(nullptr, lst.begin());
    ASSERT_EQ(nullptr, lst.end());
    lst.push_front(0);
    ASSERT_NE(nullptr, lst.begin());
    ASSERT_EQ(nullptr, lst.end());

    ASSERT_EQ(0, lst.begin()->data());
}

TEST(LinkedList, constructor) {
    std::vector<int> vec({1,2,3,4,5});
    LinkedList<int> lst(vec);

    assert_eq_LinkedList_vector(lst, vec);
}

TEST(LinkedList, copyConstructor) {
    LinkedList<int> lst({1,2,3,4,5});
    LinkedList<int> lst2(lst);

    assert_eq_LinkedList_LinkedList(lst, lst2);
}

TEST(LinkedList, push_front) {
    LinkedList<int> lst;
    lst.push_front(0);
    ASSERT_EQ(0, lst.begin()->data());
    lst.push_front(1);
    ASSERT_EQ(1, lst.begin()->data());
    ASSERT_EQ(0, lst.begin()->next()->data());
}

TEST(LinkedList, insertBefore) {
    std::vector<int> vec ({1,2,3,4});
    std::vector<int> vec2({5,1,2,3,4});
    std::vector<int> vec3({5,1,2,6,3,4});
    LinkedList<int> lst(vec);
    lst.insertBefore(lst.begin(), 5);
    assert_eq_LinkedList_vector(lst, vec2);
    lst.insertBefore(lst.begin()->next()->next()->next(), 6);
    assert_eq_LinkedList_vector(lst, vec3);
}

TEST(LinkedList, insertAfter) {
    std::vector<int> vec ({1,2,3,4});
    std::vector<int> vec2({1,5,2,3,4});
    std::vector<int> vec3({1,5,2,3,6,4});
    LinkedList<int> lst(vec);
    lst.insertAfter(lst.begin(), 5);
    assert_eq_LinkedList_vector(lst, vec2);
    lst.insertAfter(lst.begin()->next()->next()->next(), 6);
    assert_eq_LinkedList_vector(lst, vec3);
}

TEST(LinkedList, remove) {
    std::vector<int> vec ({1,2,3,4,5});
    std::vector<int> vec2({2,3,4,5});
    std::vector<int> vec3({2,4,5});
    std::vector<int> vec4({2,4});
    LinkedList<int> lst(vec);
    // remove '1'
    lst.remove(lst.begin());
    assert_eq_LinkedList_vector(lst, vec2);
    // remove '3'
    lst.remove(lst.begin()->next());
    assert_eq_LinkedList_vector(lst, vec3);
    // remove '5'
    lst.remove(lst.begin()->next()->next());
    assert_eq_LinkedList_vector(lst, vec4);
}

TEST(LinkedList, find) {
    LinkedList<int> lst({1,2,3,4,5,5,6});
    LinkedListNode<int> * node = nullptr;

    node = lst.find(lst.begin(), [](const int & i) { return i == 1; });
    ASSERT_EQ(1, node->data());
    ASSERT_EQ(lst.begin(), node);

    node = lst.find(lst.begin(), [](const int & i) { return i == 3; });
    ASSERT_EQ(3, node->data());
    ASSERT_EQ(lst.begin()->next()->next(), node);

    node = lst.find(node->next(), [](const int & i) { return i == 5; });
    ASSERT_EQ(5, node->data());
    ASSERT_EQ(lst.begin()->next()->next()->next()->next(), node);

    node = lst.find(node->next(), [](const int & i) { return i == 5; });
    ASSERT_EQ(5, node->data());
    ASSERT_EQ(lst.begin()->next()->next()->next()->next()->next(), node);

    node = lst.find(lst.begin(), [](const int & i) { return i == 6; });
    ASSERT_EQ(6, node->data());
    ASSERT_EQ(lst.begin()->next()->next()->next()->next()->next()->next(), node);
}

TEST(LinkedList, traverse) {
    std::vector<int> vec({1,2,3,4,5});
    LinkedList<int> lst(vec);

    std::vector<int>::const_iterator citer = vec.cbegin();
    lst.traverse([&](const int & i) {
        ASSERT_EQ(*citer, i);
        ++citer;
    });
}

TEST(LinkedList, swapMinMax) {
    std::vector<int> vec ({1,2,3,4,5});
    std::vector<int> vec2({5,2,3,4,1});
    LinkedList<int> lst(vec);
    lst.swapMinMax(std::less<int>());
    assert_eq_LinkedList_vector(lst, vec2);
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
