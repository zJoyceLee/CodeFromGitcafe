//STL
#include <iostream>
#include <vector>
//Current Project
#include "helper.hpp"
//Current Test
#include "gtest/gtest.h"

template <typename T>
std::vector<T> bubble(std::vector<T> myvec) {
    T temp;
    for(std::size_t j = 0; j < myvec.size() - 1; ++j) {
        for(std::size_t i = 0; i < myvec.size()- 1 - j; ++i){
            if(myvec[i] > myvec[i + 1]){
                temp = myvec[i];
                myvec[i] = myvec[i + 1];
                myvec[i + 1] = temp;
            }
        }
    }
    return myvec;
}

//TEST(BubbleSort, testSortNull) {
//    std::vector<int> myvec = {};
//    assert_eq_vector({}, bubble(myvec));
//}

TEST(BubbleSort, testSortOne) {
    std::vector<int> myvec = {1};
    assert_eq_vector({1}, bubble(myvec));
}

TEST(BubbleSort, testSortTwoDatas) {
    std::vector<int> myvec = {99,1};
    assert_eq_vector({1,99}, bubble(myvec));

    std::vector<int> ordered = {1,99};
    assert_eq_vector({1,99}, bubble(ordered));
}

TEST(BubbleSort, testSortThreeDatas) {
    std::vector<int> myvec1 = {99,77,88};
    assert_eq_vector({77,88,99}, bubble(myvec1));

    std::vector<int> myvec4 = {99,88,77};
    assert_eq_vector({77,88,99}, bubble(myvec4));

    std::vector<int> myvec2 = {77,99,88};
    assert_eq_vector({77,88,99}, bubble(myvec2));

    std::vector<int> myvec5 = {88,99,77};
    assert_eq_vector({77,88,99}, bubble(myvec5));

    std::vector<int> myvec3 = {77,88,99};
    assert_eq_vector({77,88,99}, bubble(myvec3));

    std::vector<int> myvec6 = {88,77,99};
    assert_eq_vector({77,88,99}, bubble(myvec6));
}

TEST(BubbleSort, testSortMoreThanThree) {
    std::vector<int> myvec = {5,7,3,2,8,4,1,0};
    assert_eq_vector({0,1,2,3,4,5,7,8}, bubble(myvec));
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
