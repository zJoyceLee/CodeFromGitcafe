// STL
#include <iostream>
// google-test
#include <gtest/gtest.h>
// Current Project
#include "DStackQueue.hpp"

TEST(DStackQueueTest, constructor) {
    DStackQueue<int> que;
    DStackQueue<int> que2({1,2,3,4,5});
}

TEST(DStackQueueTest, traverse) {
    DStackQueue<int> que({1,3,2,5,4});
    std::vector<int> expectedF2B({1,3,2,5,4});
    std::vector<int> expectedB2F({4,5,2,3,1});
    std::size_t counter = 0;

    counter = 0;
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expectedF2B[counter], i);
        ++counter;
    });

    counter = 0;
    que.traverseB2F([&](const int & i) {
        ASSERT_EQ(expectedB2F[counter], i);
        ++counter;
    });
}

TEST(DStackQueueTest, pushAndPop) {
    DStackQueue<int> que({1,3,2,5,4});
    std::vector<int> expected;
    std::size_t counter = 0;

    que.push(100);
    counter = 0;
    expected = std::vector<int>({1,3,2,5,4,100});
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expected[counter], i);
        ++counter;
    });

    que.push(200);
    counter = 0;
    expected = std::vector<int>({1,3,2,5,4,100,200});
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expected[counter], i);
        ++counter;
    });

    que.pop();
    counter = 0;
    expected = std::vector<int>({3,2,5,4,100,200});
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expected[counter], i);
        ++counter;
    });

    que.pop();
    counter = 0;
    expected = std::vector<int>({2,5,4,100,200});
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expected[counter], i);
        ++counter;
    });

    que.push(300);
    counter = 0;
    expected = std::vector<int>({2,5,4,100,200,300});
    que.traverseF2B([&](const int & i) {
        ASSERT_EQ(expected[counter], i);
        ++counter;
    });
}

TEST(DStackQueueTest, frontAndBack) {
    DStackQueue<int> que({1,3,2,5,4});
    ASSERT_EQ(1, que.front());
    ASSERT_EQ(4, que.back());
    que.push(100);
    ASSERT_EQ(100, que.back());
    que.pop();
    ASSERT_EQ(3, que.front());
}

TEST(DStackQueueTest, empty) {
    DStackQueue<int> que;
    ASSERT_EQ(true, que.empty());
    DStackQueue<int> que2({1,2,3,4,5});
    ASSERT_EQ(false, que2.empty());
}

TEST(DStackQueueTest, size) {
    DStackQueue<int> que;
    ASSERT_EQ(0, que.size());
    DStackQueue<int> que2({1,2,3,4,5});
    ASSERT_EQ(5, que2.size());
    que2.pop();
    ASSERT_EQ(4, que2.size());
}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
