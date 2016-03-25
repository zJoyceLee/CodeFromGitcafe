//STL
#include <iostream>
//Current Project
#include "Node.hpp"
#include "LinkedList.hpp"
//current test
#include "gtest/gtest.h"

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

#ifdef array
/* a[0] to a[n-1] is the array to sort */
int i,j;
int iMin;

/* advance the position through the entire array */
/*   (could do j < n-1 because single element is also min element) */
for (j = 0; j < n-1; j++) {
    /* find the min element in the unsorted a[j .. n-1] */

    /* assume the min is the first element */
    iMin = j;
    /* test against elements after j to find the smallest */
    for ( i = j+1; i < n; i++) {
        /* if this element is less, then it is the new minimum */
        if (a[i] < a[iMin]) {
            /* found new minimum; remember its index */
            iMin = i;
        }
    }

    if(iMin != j) {
        swap(a[j], a[iMin]);
    }
}
#endif // array

template <typename T>
LinkedList<T> selectSort(LinkedList<T> lst) {
    if(lst.begin() == nullptr)
        return lst;

    Node<T> * i_prev = lst.getHead(), * i = nullptr;
    Node<T> * iMin_prev, * iMin = nullptr;
    Node<T> * j = lst.begin(), * j_prev = lst.getHead();

    //for(j = lst.begin(); j->next() != lst.end(); j = j->next()) {
    while(j->next() != nullptr) {
        iMin = j;
        Node<T> * j_next = j->next();

        //for(i = j->next(); i != lst.end(); i = i->next()){
        i = j->next();
        while(i != lst.end()) {

            if(i->data() < iMin->data()) {
                iMin = i;
                iMin_prev = i_prev;
            }

            i_prev = i;
            i = i->next();
        }

        if(iMin != j) {
            // do swap
            if(j->next() == iMin) {
                Node<T> * iMin_next = iMin->next();
                j_prev->next() = iMin;
                iMin->next() = j;
                j->next() = iMin_next;
            } else if(j->next() == iMin_prev) {
                auto iMin_next = iMin->next();
                j_prev->next() = iMin;
                iMin->next() = iMin_prev;
                iMin_prev->next() = j;
                j->next() = iMin_next;
            } else {
                auto iMin_next = iMin->next();
                j_prev->next() = iMin;
                iMin->next() = j->next();
                iMin_prev->next() = j;
                j->next() = iMin_next;
            }

            j_prev = iMin;
            j = j_next;
            continue;
        }

        j_prev = j;
        j = j_next;
    }
    return lst;
}

TEST(LinkedList, testConstruct) {
    LinkedList<int> lst({1,2,3,4});
}

TEST(selectSort, testSortOneNode) {
    EXPECT_EQ("[1]", std::to_string(selectSort(LinkedList<int>({1}))));
}

TEST(selectSort, testSortTwoNodes) {
    EXPECT_EQ("[1,99]", std::to_string(selectSort(LinkedList<int>({99,1}))));
    EXPECT_EQ("[1,99]", std::to_string(selectSort(LinkedList<int>({1,99}))));
}

TEST(selectSort, teatSortThreeNodes1) {
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({92,1,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({1,92,3}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({3,92,1}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({1,3,92}))));
    EXPECT_EQ("[1,3,92]", std::to_string(selectSort(LinkedList<int>({3,1,92}))));
}

TEST(selectSort, teatSortThreeNodes2) {
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({92,1,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({92,0,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({1,92,0}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({0,92,1}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({1,0,92}))));
    EXPECT_EQ("[0,1,92]", std::to_string(selectSort(LinkedList<int>({0,1,92}))));
}

TEST(selectSort, testSortMoreThanThreeNodes) {
    LinkedList<int> lst({5,7,3,2,8,4,1,0});
    EXPECT_EQ("[0,1,2,3,4,5,7,8]", std::to_string(selectSort(LinkedList<int>({5,7,3,2,8,4,1,0}))));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
