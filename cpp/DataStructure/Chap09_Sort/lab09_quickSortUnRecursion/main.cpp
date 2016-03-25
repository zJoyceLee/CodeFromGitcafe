//STL
#include <vector>
#include <iostream>
#include <stack>
//Current Test
#include "helper.hpp"
#include "gtest/gtest.h"

template <typename T>
void printVec(const std::vector<T> & myvec) {
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        std::cout  << *it << ". ";
    }std::cout  << std::endl;
}

template <typename T>
bool isOrdered(const std::vector<T> & myvec) {
    for(std::size_t i = 0; i < myvec.size() - 1; ++i) {
        T cur = myvec[i];
        T post = myvec[i + 1];
        if(cur > post) {
            return false;
        }
    }
    return true;
}

template <typename T>
int partitionMykeys(std::vector<T> & vec, int low, int high){
    T pivot = vec[low];
    while(low < high) {
        while(low < high && vec[high] >= pivot) {
            --high;
        }
        vec[low] = vec[high];
        while(low < high && vec[low] <= pivot) {
            ++low;
        }
        vec[high] = vec[low];
    }
    vec[low] = pivot;
    return low;
}

template<typename T>
void quickSortUnrecursion(std::vector<T> & vec, int low, int high){
    std::stack<int> mystack;
    if(low < high){
        int mid = partitionMykeys(vec,low,high);
        if(low < mid - 1) {
            mystack.push(low);
            mystack.push(mid - 1);
        }
        if(mid + 1 < high) {
            mystack.push(mid + 1);
            mystack.push(high);
        }
        //save index
        while(!mystack.empty()) {
            int q = mystack.top();
            mystack.pop();
            int p = mystack.top();
            mystack.pop();
            mid = partitionMykeys(vec,p,q);
            if(p < mid - 1) {
                mystack.push(p);
                mystack.push(mid - 1);
            }
            if(mid + 1 < q) {
                mystack.push(mid + 1);
                mystack.push(q);
            }
        }
    }
}

TEST(partitionMykeys, testIndex) {
    std::vector<int> myvec1 = {0,1,2,3,4,5,6};
    ASSERT_EQ(0, partitionMykeys(myvec1,0,6));
}

TEST(QuickSort, testEmpty) {
    std::vector<int> myvec = {};
    quickSortUnrecursion(myvec,0,-1);
    assert_eq_vector({}, myvec);
}

TEST(QuickSort, testOneElement) {
    std::vector<int> myvec = {5};
    quickSortUnrecursion(myvec,0,0);
    assert_eq_vector({5}, myvec);
}

TEST(QuickSort, testTwoElements) {
    std::vector<int> myvec = {5,3};
    quickSortUnrecursion(myvec,0,1);
    assert_eq_vector({3,5}, myvec);

    std::vector<int> myvec2 = {3,5};
    quickSortUnrecursion(myvec2,0,1);
    assert_eq_vector({3,5}, myvec2);
}

TEST(QuickSort, testThreeElements) {
    std::vector<int> myvec1 = {5,3,7};
    quickSortUnrecursion(myvec1,0,2);
    assert_eq_vector({3,5,7}, myvec1);

    std::vector<int> myvec2 = {5,7,3};
    quickSortUnrecursion(myvec2,0,2);
    assert_eq_vector({3,5,7}, myvec2);

    std::vector<int> myvec3 = {3,5,7};
    quickSortUnrecursion(myvec3,0,2);
    assert_eq_vector({3,5,7}, myvec3);

    std::vector<int> myvec4 = {3,7,5};
    quickSortUnrecursion(myvec4,0,2);
    assert_eq_vector({3,5,7}, myvec4);

    std::vector<int> myvec5 = {7,5,3};
    quickSortUnrecursion(myvec5,0,2);
    assert_eq_vector({3,5,7}, myvec5);

    std::vector<int> myvec6 = {7,3,5};
    quickSortUnrecursion(myvec6,0,2);
    assert_eq_vector({3,5,7}, myvec6);
}

TEST(QuickSort, testNomal) {
    std::vector<int> myvec = {5,3,7,6,4,2,1};
    quickSortUnrecursion(myvec,0,6);
    assert_eq_vector({1,2,3,4,5,6,7}, myvec);
}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
