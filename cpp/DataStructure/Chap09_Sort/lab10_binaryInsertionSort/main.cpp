//STL
#include <iostream>
#include <vector>
//Current Test
#include "helper.hpp"
#include "gtest/gtest.h"

template <typename T>
std::vector<T> insertOrdered(const T & value, std::vector<T> myvec) {
    bool inserted = false;
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        if(*it > value) {
            myvec.insert(it, value);
            inserted = true;
            break;
        }
    }
    if(!inserted) {
        myvec.push_back(value);
    }
    return myvec;
}

template <typename T>
std::vector<T> binaryInsertionSort(std::vector<T> mykeys) {
    std::vector<T> d_smaller, d_bigger;
    T pivot = mykeys[0];
    d_smaller.push_back(pivot);
    for(std::size_t i = 1; i < mykeys.size(); ++i) {
        if(mykeys[i] > pivot) {
            d_bigger = insertOrdered(mykeys[i], d_bigger);
        } else {
            d_smaller = insertOrdered(mykeys[i], d_smaller);
        }
    }
    for(std::size_t i = 0; i < d_bigger.size(); ++i) {
        d_smaller.push_back(d_bigger[i]);
    }
    mykeys = d_smaller;
    return mykeys;
}

TEST(insertOrdered, testEmpty) {
    assert_eq_vector({5}, insertOrdered(5, {}));
}

TEST(insertOrdered, testOneElement) {
    assert_eq_vector({5,7}, insertOrdered(5, {7}));
    assert_eq_vector({5,7}, insertOrdered(7, {5}));
    assert_eq_vector({8,14,14,35,99}, insertOrdered(35, {8,14,14,99}));
}

TEST(insertOrdered, testTwoElements) {
    assert_eq_vector({5,7,9}, insertOrdered(5, {7,9}));
    assert_eq_vector({5,7,9}, insertOrdered(7, {5,9}));
    assert_eq_vector({5,7,9}, insertOrdered(9, {5,7}));
}

TEST(insertOrdered, testManyElements) {
    assert_eq_vector({8,14,14,35,99}, insertOrdered(35, {8,14,14,99}));
    assert_eq_vector({8,14,14,35,99}, insertOrdered(8, {14,14,35,99}));
    assert_eq_vector({8,14,14,35,99}, insertOrdered(14, {8,14,35,99}));
    assert_eq_vector({8,14,14,35,99}, insertOrdered(14, {8,14,35,99}));
    assert_eq_vector({8,14,14,35,99}, insertOrdered(99, {8,14,14,35}));
}

TEST(InsertSort, testAllInSmaller) {
    assert_eq_vector({1,2,3,4,5,6,7}, binaryInsertionSort(std::vector<int>{7,5,4,2,1,3,6}));
}

TEST(InsertSort, testAllInBigger) {
    assert_eq_vector({1,2,3,4,5,6,7}, binaryInsertionSort(std::vector<int>{1,5,4,2,7,3,6}));
}

TEST(InsertSort, testDevideInTwoPart) {
    assert_eq_vector({1,2,3,4,5,6,7}, binaryInsertionSort(std::vector<int>{4,5,1,2,7,3,6}));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

