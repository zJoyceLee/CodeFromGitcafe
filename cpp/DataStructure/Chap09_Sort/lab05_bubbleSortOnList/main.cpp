//STL
#include <iostream>
#include <string>
//Current Project
#include "LinkedList.hpp"
#include "LinkedListNode.hpp"
//Current test
#include "gtest/gtest.h"

template <typename T>
void printLST(const LinkedList<T> & lst) {
    for(auto cur = lst.begin(); cur != nullptr; cur = cur->next()) {
        std:: cout << cur->data() << ". ";
    }
    std::cout << std::endl;
}

template <typename T>
void print(const LinkedList<T> & lst) {
    std::cout << '{' << std::endl;
    for (auto i = lst.begin(); i != lst.end(); i = i->next()) {
        std::cout << "  (" << i->data() << ',' << i->prev() << ',' << i->next() << ")" << std::endl;
    }
    std::cout << '}' << std::endl;
}

namespace std {
    template <typename T>
    std::string to_string(const LinkedList<T> & lst) {
        std::string ret;
        ret += '[';
        for (auto i = lst.begin(); i != lst.end(); i = i->next()) {
            ret += std::to_string(i->data());
            ret += ',';
        }

        if(ret.back() == ',') {
            ret.back() = ']';
        } else {
            ret += ']';
        }
        return ret;
    }
}

template <typename T>
LinkedList<T> bubbleSort(LinkedList<T> lst) {
#if 0
    for(auto curj = lst.begin(); curj->next() != nullptr; curj = curj->next()) {
        for(auto cur = lst.begin(); cur->next() != nullptr; cur = cur->next()) {
            if((cur->data()) > (cur->next()->data())) {
//                std::swap(cur->data(), cur->next()->data());

                // both nodes are between begin and end
                // second node at the end
                // third node at the begin
                // only two nodes
                if(cur->prev() != nullptr && cur->next()->next() != nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto prev_tmp = cur->prev();
                    auto next_tmp = tmp->next();
                    prev_tmp->next() = tmp;
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = next_tmp;
                    next_tmp->prev() = cur_tmp;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = prev_tmp;
                    cur = tmp;
                    std::cout << "   in: ";
                    printLST(lst);
                } else if(cur->prev() != nullptr && cur->next() != nullptr && cur->next()->next() == nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto prev_tmp = cur->prev();
                    prev_tmp->next() = tmp;
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = nullptr;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = prev_tmp;
                    cur = tmp;
                    std::cout << "  end: ";
                    printLST(lst);

                } else if(cur->prev() == nullptr && cur->next()->next() != nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    auto next_tmp = tmp->next();
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = next_tmp;
                    next_tmp->prev() = cur_tmp;
                    cur_tmp->prev() = tmp;
                    tmp->prev() = nullptr;
                    cur = tmp;
                    lst.head() = tmp;
                    std::cout << "begin: ";
                    printLST(lst);
                } else if(cur->prev() == nullptr && cur->next() != nullptr && cur->next()->next() == nullptr) {
                    auto cur_tmp = cur;
                    auto tmp = cur->next();
                    tmp->next() = cur_tmp;
                    cur_tmp->next() = nullptr;
                    cur->prev() = tmp;
                    tmp->prev() = nullptr;
                    cur = tmp;
                    lst.head() = tmp;
                    printLST(lst);
                }

            }
        }
    }
    return lst;
#endif
    bool done = false;
    while(!done) {
        done = true;
        auto j = lst.begin();
        while(j->next() != nullptr) {
            auto cur = j;
            auto next = j->next();

            if(cur->data() > next->data()) {
                done = false;
                if(cur->prev() == nullptr && next->next() == nullptr) {
                    // case 1: only 2 nodes
                    next->next() = cur; cur->prev() = next;
                    next->prev() = nullptr; cur->next() = nullptr;
                    // change the first node
                    lst.head() = next;
                } else if(cur->prev() == nullptr) {
                    // case 2: swap the first node and the second node
                    auto n = next->next();
                    next->prev() = nullptr;
                    cur->next() = n; n->prev() = cur;
                    next->next() = cur; cur->prev() = next;
                    // change the first node
                    lst.head() = next;
                } else if(next->next() == nullptr) {
                    // case 3: swap the last node and the node before last
                    auto p = cur->prev();
                    cur->next() = nullptr;
                    next->prev() = p; p->next() = next;
                    next->next() = cur; cur->prev() = next;
                } else {
                    // normal case
                    auto p = cur->prev(); auto n = next->next();
                    next->prev() = p; p->next() = next;
                    cur->next() = n; n->prev() = cur;
                    next->next() = cur; cur->prev() = next;
                }
                j = cur;
                continue;
            }
            j = next;
        }
    }

    return lst;
}

TEST(BubbleSort, teatSortOneNode) {
    EXPECT_EQ("[1]", std::to_string(bubbleSort(LinkedList<int>({1}))));
}

TEST(BubbleSort, testSortTwoNodes) {
    EXPECT_EQ("[1,99]", std::to_string(bubbleSort(LinkedList<int>({99,1}))));
}

TEST(BubbleSort, teatSortThreeNodes1) {
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({1,92,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({3,92,1}))));
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({1,3,92}))));
    EXPECT_EQ("[1,3,92]", std::to_string(bubbleSort(LinkedList<int>({3,1,92}))));
}

TEST(BubbleSort, teatSortThreeNodes2) {
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({92,1,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({92,0,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({1,92,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({0,92,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({1,0,92}))));
    EXPECT_EQ("[0,1,92]", std::to_string(bubbleSort(LinkedList<int>({0,1,92}))));
}

TEST(BubbleSort, testSortMoreThanThreeNodes) {
    LinkedList<int> lst({5,7,3,2,8,4,1,0});
    //printLST(bubbleSort(lst));
    EXPECT_EQ("[0,1,2,3,4,5,7,8]", std::to_string(bubbleSort(LinkedList<int>({5,7,3,2,8,4,1,0}))));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
