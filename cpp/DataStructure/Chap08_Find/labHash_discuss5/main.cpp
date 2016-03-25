//STL
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
//C-Standard
#include <cstdio>
//Current Project
#include "helper.hpp"
//g-test
#include "gtest/gtest.h"

template <typename T>
void printVec(const std::vector<T> & vec) {
    for(std::size_t i = 0; i < vec.size() - 1; ++i) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[vec.size() - 1] << std::endl;
}

std::size_t myHash(int key) {
    std::size_t position = (3 * key) % 11;
    return position;
}

std::size_t myReHash(int key) {
    std::size_t position = (7 * key) % 10 + 1;
    return position;
}

std::size_t conflict(int key, std::size_t m, std::size_t i) {
    std::size_t position = (myHash(key) + i * myReHash(key)) % m;
    // in this case m = 11, i is increasing from 1 to m - 1
    return position;
}

std::size_t conflictTest(int myHashValue, int myReHashValue, std::size_t m, std::size_t i) {
    // myHashValue ranges from [0, m-1]
    // myReHashValue ranges from [1, m-1]
    return (myHashValue + i * myReHashValue) % m;
}

std::size_t findEmptyBucketSteps(
        const std::vector<std::pair<int, bool>> &myvec,
        std::size_t currentBucketIndex,
        std::size_t bucketSize,
        int myReHashValue)
{
    // if current bucket is empty, then ASL is 0
    if(myvec[currentBucketIndex].second == false) {
        printf("bucket %ld: no rehash, steps %d\n", currentBucketIndex, 0);
        return 0;
    }

    // if current bucket is not empty, use conflict to find an empty one
    // the steps to find the first bucket that is not filled, aka `pair.second` is false.
    std::size_t steps = 0;
    for(steps = 1; steps < bucketSize; ++steps) {
        int myHashValue = currentBucketIndex;
        int rehashBucketIndex = conflictTest(myHashValue, myReHashValue, bucketSize, steps);
        // check whether we find the bucket that is not filled
        if(myvec[rehashBucketIndex].second == false)
            break;
    }

    printf("bucket %ld: rehash %d, steps %ld\n", currentBucketIndex, myReHashValue, steps);
    return steps;
}

double calculateAverageStepsForBucket(
        const std::vector<std::pair<int, bool>> &myvec,
        std::size_t currentBucketIndex,
        std::size_t bucketSize)
{
    std::vector<std::size_t> currentBucketStepsVector;
    for (int myReHashValue = 1; myReHashValue < (int)(bucketSize); ++myReHashValue) {
        std::size_t steps = findEmptyBucketSteps(myvec, currentBucketIndex,
                                                 bucketSize, myReHashValue);
        currentBucketStepsVector.push_back(steps);
    }

    // average
    double stepsSum = std::accumulate(currentBucketStepsVector.begin(),
                                      currentBucketStepsVector.end(),
                                      0);
    double average = stepsSum / currentBucketStepsVector.size();
    printf("bucket %ld: average steps %lf\n", currentBucketIndex, average);
    return average;
}

TEST(Hash, testHash) {
    std::vector<int> myvec = {22,41,53,46,30,13,1,67};
    std::vector<std::size_t> hashResult;
    for (std::size_t i = 0; i < myvec.size(); ++i) {
        hashResult.push_back(myHash(myvec[i]));
    }
    assert_eq_vector({0,2,5,6,2,6,3,3}, hashResult);

}

TEST(Hash, testConstruct) {
    std::vector<std::pair<int, bool>> myvec;
    for(std::size_t i = 0; i < 11; ++i){
        myvec.push_back({0, false});
    }; // initialization
    std::vector<int> mykeys = {22,41,53,46,30,13,1,67};

    double countFindPosition = double(mykeys.size()); // ASL

    for(std::size_t index = 0; index < mykeys.size(); ++index) {
        int key = mykeys[index]; // index is increasing
        std::size_t position = myHash(key);
        std::size_t rePosition = myvec.size();
         if(myvec[position].second == false) {
            myvec[position] = {key, true};
        } else {
            std::size_t i = 1;
            do{
                if(i == 11)
                    break;
                rePosition = conflict(key, 11, i);
                ++i;
            } while(myvec[rePosition].second == true);
            myvec[rePosition] = {key, true};
            countFindPosition += double(i - 1); // ASL
        }
    } // (1) construct

    std::cout << "ASL(success): " << countFindPosition / mykeys.size() << ". should be: " << 17./8 << std::endl;
    EXPECT_EQ(countFindPosition / mykeys.size(), 17./8); // ASL

    ///{{22,true},{67,true},{41,true},{30,true},{0, false},{53,true},{46,true},{0, false},{13,true},{0, false},{1,true}}
    std::vector<int> resultVec;
    for(std::size_t i = 0; i < myvec.size(); ++i) {
        resultVec.push_back(myvec[i].first);
    }
    assert_eq_vector({ 22, 67, 41, 30,  0, 53, 46,  0, 13,  0,  1}, resultVec);
}

TEST(Hash, testSearchFailureASL) {
    std::vector<std::pair<int, bool>> myvec;
    for(std::size_t i = 0; i < 11; ++i){
        myvec.push_back({0, false});
    }; // initialization
    std::vector<int> mykeys = {22,41,53,46,30,13,1,67};

    for(std::size_t index = 0; index < mykeys.size(); ++index) {
        int key = mykeys[index]; // index is increasing
        std::size_t position = myHash(key);
        std::size_t rePosition = myvec.size();
         if(myvec[position].second == false) {
            myvec[position] = {key, true};
        } else {
            std::size_t i = 1;
            do{
                rePosition = conflict(key, 11, i);
                ++i;
            } while(myvec[rePosition].second == true);
            myvec[rePosition] = {key, true};
        }
    } // (1) construct

    // --------------------------------------------------------

    // (2) test search failure ASL

    // for each bucket (aka position)
    std::size_t bucketSize = 11;
    double sumUp = 0.;
    for(std::size_t bucketIndex = 0; bucketIndex < bucketSize; ++bucketIndex) {
        double currentBucketAverageSteps = calculateAverageStepsForBucket(myvec, bucketIndex, bucketSize);
        sumUp += currentBucketAverageSteps;
    }
    printf("Search Failed ASL: %lf\n", sumUp/bucketSize);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
