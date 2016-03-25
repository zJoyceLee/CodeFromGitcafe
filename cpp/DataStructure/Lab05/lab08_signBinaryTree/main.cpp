// STL
#include <iostream>
#include <string>
#include <utility>
// gtest
#include <gtest/gtest.h>

#define USE_TEST

std::pair<int, int> taggedTreeFind(std::pair<int, int> tag);

TEST(TaggedTreeTest, TaggedTreeValueTest) {
    EXPECT_EQ( (std::pair<int, int>({0,0})), taggedTreeFind({1,1}) );
    EXPECT_EQ( (std::pair<int, int>({1,0})), taggedTreeFind({2,1}) );
    EXPECT_EQ( (std::pair<int, int>({0,1})), taggedTreeFind({1,2}) );
    EXPECT_EQ( (std::pair<int, int>({2,0})), taggedTreeFind({3,1}) );
    EXPECT_EQ( (std::pair<int, int>({1,1})), taggedTreeFind({2,3}) );
    EXPECT_EQ( (std::pair<int, int>({1,1})), taggedTreeFind({3,2}) );
    EXPECT_EQ( (std::pair<int, int>({0,2})), taggedTreeFind({1,3}) );
    EXPECT_EQ( (std::pair<int, int>({3,0})), taggedTreeFind({4,1}) );
    EXPECT_EQ( (std::pair<int, int>({2,1})), taggedTreeFind({3,4}) );
    EXPECT_EQ( (std::pair<int, int>({2,1})), taggedTreeFind({5,3}) );
    EXPECT_EQ( (std::pair<int, int>({1,2})), taggedTreeFind({2,5}) );
    EXPECT_EQ( (std::pair<int, int>({2,1})), taggedTreeFind({5,2}) );
    EXPECT_EQ( (std::pair<int, int>({1,2})), taggedTreeFind({3,5}) );
    EXPECT_EQ( (std::pair<int, int>({1,2})), taggedTreeFind({4,3}) );
    EXPECT_EQ( (std::pair<int, int>({0,3})), taggedTreeFind({1,4}) );
    EXPECT_EQ( (std::pair<int, int>({41,0})), taggedTreeFind({42,1}) );
    EXPECT_EQ( (std::pair<int, int>({-1,-1})), taggedTreeFind({4,2}) );
    EXPECT_EQ( (std::pair<int, int>({-1,-1})), taggedTreeFind({6,2}) );
    EXPECT_EQ( (std::pair<int, int>({-1,-1})), taggedTreeFind({6,3}) );
}

std::pair<int, int> taggedTreeFind(std::pair<int, int> tag) {
    int right = 0;
    int left = 0;

    if(tag.first < 1 || tag.second < 1)
        return {-1, -1};
    if(tag.first == 1 && tag.second == 1)
        return {left, right};

    do {
        if(tag.first == tag.second) {
            // this tag does not exist in the tree
            return {-1, -1};
        }

        if(tag.first > tag.second) {
            tag.first = tag.first - tag.second;
            //tag.second = tag.second;
            ++left;
        } else if(tag.first < tag.second) {
            //tag.first = tag.first;
            tag.second = tag.second - tag.first;
            ++right;
        }
    } while (!(tag.first == 1 && tag.second == 1));

    return {left, right};
}

int main(int argc, char * argv[])
{
#ifdef USE_TEST
    ::testing::InitGoogleTest(&argc, argv);
#endif

#ifndef USE_TEST
    int countNum = 0;
    std::cin >> countNum;
    for(int i = 0; i < countNum; ++i) {
        std::pair<int, int> tag;
        std::cin >> tag.first >> tag.second;
        tag = taggedTreeFind(tag);
        std::cout << tag.first << ' ' << tag.second << std::endl;
    }
#endif

#ifdef USE_TEST
    return RUN_ALL_TESTS();
#else
    return 0;
#endif
}
