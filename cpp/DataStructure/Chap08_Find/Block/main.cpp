//STL
#include <vector>
#include <utility>
#include <string>
#include <iostream>
//C-Standard
#include <cmath>
#include <cassert>
//g_test
#include <gtest/gtest.h>
//Current Project
#include "helper.hpp"

template <typename T>
struct Block {
    T maxData;
    std::vector<T> data;
};

std::vector<int> sortToIncreasingOrder(std::vector<int> vec) {
    std::size_t k = 0, index = 0, i = 0, p = 0;
    for(k = 0; k < vec.size() -1; ++k) {
		index = k;
		for(i = k + 1; i < vec.size(); ++i)
            if(vec[i] < vec[index])
                index = i;
        p = vec[index];
        vec[index] = vec[k];
        vec[k] = p;
	}
	return vec;
}

TEST(Block, testSortToIncreasingOrder) {
    assert_eq_vector({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, sortToIncreasingOrder({4, 5, 3, 9, 7, 8, 6, 2, 0, 1}));
    assert_eq_vector({10, 11, 24, 30}, sortToIncreasingOrder({30, 11, 10, 24}));
    assert_eq_vector({72,73,74, 88, 99}, sortToIncreasingOrder({74, 73, 72, 99, 88}));
}

template <typename T>
std::vector<T> copyVec(const std::vector<T> & myvec) {
    std::vector<T> vec;
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        vec.push_back(*it);
    }
    return vec;
}

bool isEven(int num) {
    return (num & 0b1) == 0;
}

int binarySearch2(int target, const std::vector<int> & increasingOrderVec) {
    auto vecSize = increasingOrderVec.size();

    if(vecSize == 0)
        return -1;
    // when size is 1, then divide into 2 halves will not give the right result
    if(vecSize == 1)
        return (target == increasingOrderVec[0]) ? 0 : -1;

    auto mid = isEven(vecSize) ? (vecSize/2) : (vecSize/2+1);
    int midValue = increasingOrderVec[mid];

    if(target == midValue) {
        return static_cast<int>(mid);
    } else if(target < midValue) {
        std::vector<int> tmp(increasingOrderVec.begin(), increasingOrderVec.begin() + mid);
        return binarySearch2(target, tmp);
    } else { // (target > midValue)
        std::vector<int> tmp(increasingOrderVec.begin() + mid, increasingOrderVec.end());
        int ret = binarySearch2(target, tmp);
        if(ret == -1)
            return -1;
        return mid + ret;
    }

    // we must return at all paths, even it is unreachable.
    assert(false && "unreachable");
    return -1;
}

int binarySearch(int low, int high, int target, std::vector<int> increasingOrderVec) {
    int mid = low + (high - low) / 2;
    if(low > high) {
        return -1;
    } else {
        if(increasingOrderVec[mid] == target)
            return mid;
        if(increasingOrderVec[mid] > target)
            return binarySearch(low, mid - 1, target, increasingOrderVec);
        if(increasingOrderVec[mid] < target)
            return binarySearch(mid + 1, high, target, increasingOrderVec);
    }
    // we must return at all paths, even it is unreachable.
    assert(false && "unreachable");
    return -1;
}

TEST(Block, testBinarySearch) {
    std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ( 3, binarySearch(0, num.size(),  3, num));
    EXPECT_EQ(-1, binarySearch(0, num.size(), 20, num));
    EXPECT_EQ( 9, binarySearch(0, num.size(),  9, num));
    EXPECT_EQ( 0, binarySearch(0, num.size(),  0, num));
    EXPECT_EQ(-1, binarySearch(0, num.size(),-33, num));

    num = {3, 20, 21, 22, 30, 35, 40};
    EXPECT_EQ( 0, binarySearch(0, num.size(),  3, num));
    EXPECT_EQ( 5, binarySearch(0, num.size(), 35, num));
    EXPECT_EQ(-1, binarySearch(0, num.size(),  0, num));
    EXPECT_EQ(-1, binarySearch(0, num.size(), 90, num));
    EXPECT_EQ(-1, binarySearch(0, num.size(), 33, num));

    //------------------------------------------------------------------------
    num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ( 3, binarySearch2(  3, num));
    EXPECT_EQ(-1, binarySearch2( 20, num));
    EXPECT_EQ( 9, binarySearch2(  9, num));
    EXPECT_EQ( 0, binarySearch2(  0, num));
    EXPECT_EQ(-1, binarySearch2(-33, num));

    num = {3, 20, 21, 22, 30, 35, 40};
    EXPECT_EQ( 0, binarySearch2(  3, num));
    EXPECT_EQ( 5, binarySearch2( 35, num));
    EXPECT_EQ(-1, binarySearch2(  0, num));
    EXPECT_EQ(-1, binarySearch2( 90, num));
    EXPECT_EQ(-1, binarySearch2( 33, num));
}

int findRange(int target, std::vector<int> increasingOrderVec) {
    int low = 0;
    int high = increasingOrderVec.size() - 1;
    int mid = 0;
    while(low <= high) {
        mid = (low + high) / 2;
        if(target == increasingOrderVec[mid])
            return mid;
        else if(target <= increasingOrderVec[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    if(std::size_t(low) > increasingOrderVec.size() - 1)
        return -1;
    return low;
}

TEST(Block, testFindRange) {
    //---------------------------------0---1---2---3---4---5---6
    EXPECT_EQ( 0, findRange( 0, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findRange(90, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ( 5, findRange(33, {3, 20, 21, 22, 30, 35, 40}));

    EXPECT_EQ( 0,findRange(  8, {10, 24, 33, 99}));
    EXPECT_EQ( 1,findRange( 22, {10, 24, 33, 99}));
    EXPECT_EQ( 2,findRange( 29, {10, 24, 33, 99}));
    EXPECT_EQ( 3,findRange( 88, {10, 24, 33, 99}));
    EXPECT_EQ(-1,findRange(100, {10, 24, 33, 99}));
}

int findByLoop(int target, const std::vector<int> & vec) {
    for(std::size_t i = 0; i < vec.size(); ++i) {
        if(vec[i] == target) {
            return i;
        }
    }
    return -1;
}

TEST(Block, testFindByLoop) {
    std::vector<int> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    EXPECT_EQ( 3, findByLoop(  3, num));
    EXPECT_EQ(-1, findByLoop( 20, num));
    EXPECT_EQ( 9, findByLoop(  9, num));
    EXPECT_EQ( 0, findByLoop(  0, num));
    EXPECT_EQ(-1, findByLoop(-33, num));

    //------------------------------0---1---2---3---4---5---6
    EXPECT_EQ( 0, findByLoop( 3, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ( 5, findByLoop(35, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findByLoop( 0, {3, 20, 21, 22, 30, 35, 40}));
    EXPECT_EQ(-1, findByLoop(90, {3, 20, 21, 22, 30, 35, 40}));
}

std::pair<int, int> blockFind(int target, std::vector<Block<int>> myBlocks) {
    std::pair<int, int> position;
    std::vector<int> iNodeData;
    int indexInINode = -1;
    for(std::size_t i = 0; i < myBlocks.size(); ++i) {
        iNodeData.push_back(myBlocks[i].maxData);
    }
    int iNode = findRange(target, iNodeData);
    if(iNode == -1) {
        position.first = iNode;
        position.second = indexInINode;
        return position;
    }
    indexInINode = findByLoop(target, myBlocks[iNode].data);
    position.first = iNode;
    position.second = indexInINode;
    return position;
}

TEST(Block, testBlockFInd) {
    std::vector<Block<int>> myBlocks = {
        {10, { 7, 3, 2,10, 1}},
        {24, {13,19,24,21,15}},
        {33, {33,29,31,25,32}},
        {99, {45,66,77,88,99}}
    };
    std::pair<int, int> expect;

    //std::cout << "(" << blockFind(45, myBlocks).first << "," << blockFind(45, myBlocks).second << ")" << std::endl;
    expect.first = 3;
    expect.second = 0;
    assert_eq_pair(expect, blockFind(45, myBlocks));

    expect.first = 0;
    expect.second = 0;
    assert_eq_pair(expect, blockFind(7, myBlocks));

    expect.first = 2;
    expect.second = 3;
    assert_eq_pair(expect, blockFind(25, myBlocks));

    expect.first = -1;
    expect.second = -1;
    assert_eq_pair(expect, blockFind(100, myBlocks));

    expect.first = 3;
    expect.second = -1;
    assert_eq_pair(expect, blockFind(55, myBlocks));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
