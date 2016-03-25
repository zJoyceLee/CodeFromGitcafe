//STL
#include <vector>
#include <iostream>
//Current-Project
#include "UFSetsNode.hpp"
#include "UFSets.hpp"
// Current-Test
#include "helper.hpp"
//g-test
#include <gtest/gtest.h>

TEST(TestUFSetsClass, testUnionSet) {
    UFSets<int> s1({1}), s2({2}),   s3({3}),   s4({4}),   s5({5}),   s6({6}),   s7({7}),   s8({8});
    UFSets<int> s9({9}), s10({10}), s11({11}), s12({12}), s13({13}), s14({14}), s15({15}), s16({16});

    std::vector<UFSets<int>> allSets = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8},
        {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}
    };


    UFSets<int> * lhs = nullptr;
    UFSets<int> * rhs = nullptr;
    UFSets<int> * act = nullptr;

    lhs = findAll(1, allSets);
    rhs = findAll(2, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{1,-2} , {2,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(4, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-2},{4,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(5, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-3},{4,0},{5,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(7, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{1,-3},{2,0},{7,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(6, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-4},{4,0},{5,0},{6,0}}, *act);

    lhs = findAll(8, allSets);
    rhs = findAll(9, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{8,-2},{9,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(8, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{1,-5},{2,0},{7,0},{8,0},{9,3}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(10, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-5},{4,0},{5,0},{6,0},{10,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(11, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-6},{4,0},{5,0},{6,0},{10,0},{11,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(12, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-7},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(13, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{3,-8},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0}}, *act);

    lhs = findAll(14, allSets);
    rhs = findAll(15, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{14,-2},{15,0}}, *act);

    lhs = findAll(16, allSets);
    rhs = findAll(0, allSets);
    act = lhs;
    ASSERT_EQ(nullptr, rhs);

    lhs = findAll(14, allSets);
    rhs = findAll(16, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{14,-3},{15,0},{16,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(3, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{1,-13},{2,0},{7,0},{8,0},{9,3},{3,0},
                             {4,5},{5,5},{6,5},{10,5},{11,5},{12,5},{13,5}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(14, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    assert_eq_UFSets_vector({{1,-16},{2,0},{7,0},{8,0},{9,3},
                            {3,0},{4,5},{5,5},{6,5},{10,5},{11,5},{12,5},{13,5},
                            {14,0},{15,13},{16,13}}, *act);

    assert_eq_vector(std::vector<UFSetsNode<int>>({{1,-2}, {2,0}}), *(UFSets<int>({1, 2}).data()));
    assert_eq_UFSets_vector({{1,-2} , {2,0}} , UFSets<int>({1 , 2 }));
}

TEST(TestUFSetsClass, testHeight) {
    std::vector<UFSets<int>> allSets = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8},
        {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}
    };
    UFSets<int> * lhs = nullptr;
    UFSets<int> * rhs = nullptr;
    UFSets<int> * act = nullptr;

    EXPECT_EQ(1, allSets[0].height());

    lhs = findAll(1, allSets);
    rhs = findAll(2, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    EXPECT_EQ(2, (*act).height());

    lhs = findAll(3, allSets);
    rhs = findAll(4, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    EXPECT_EQ(2, (*act).height());

    lhs = findAll(5, allSets);
    rhs = findAll(6, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    EXPECT_EQ(2, (*act).height());

    lhs = findAll(3, allSets);
    rhs = findAll(5, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    EXPECT_EQ(3, (*act).height());

    lhs = findAll(1, allSets);
    rhs = findAll(5, allSets);
    act = lhs;
    lhs->unionSet(*rhs);
    EXPECT_EQ(4, (*act).height());
}

TEST(TestUFSetsClass, testUnionSetByHeight) {
std::vector<UFSets<int>> allSets = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8},
        {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}
    };


    UFSets<int> * lhs = nullptr;
    UFSets<int> * rhs = nullptr;
    UFSets<int> * act = nullptr;

    lhs = findAll(1, allSets);
    rhs = findAll(2, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{1,-2} , {2,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(4, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-2},{4,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(5, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-3},{4,0},{5,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(7, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{1,-3},{2,0},{7,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(6, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-4},{4,0},{5,0},{6,0}}, *act);

    lhs = findAll(8, allSets);
    rhs = findAll(9, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{8,-2},{9,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(8, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{1,-5},{2,0},{7,0},{8,0},{9,3}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(10, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-5},{4,0},{5,0},{6,0},{10,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(11, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-6},{4,0},{5,0},{6,0},{10,0},{11,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(12, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-7},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(13, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{3,-8},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0}}, *act);

    lhs = findAll(14, allSets);
    rhs = findAll(15, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{14,-2},{15,0}}, *act);

    lhs = findAll(16, allSets);
    rhs = findAll(0, allSets);
    act = lhs;
    ASSERT_EQ(nullptr, rhs);

    lhs = findAll(14, allSets);
    rhs = findAll(16, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{14,-3},{15,0},{16,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(3, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{1,-13},{2,0},{7,0},{8,0},{9,3},{3,0},
                             {4,5},{5,5},{6,5},{10,5},{11,5},{12,5},{13,5}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(14, allSets);
    act = lhs;
    lhs->unionSetByHeight(*rhs);
    assert_eq_UFSets_vector({{1,-16},{2,0},{7,0},{8,0},{9,3},
                            {3,0},{4,5},{5,5},{6,5},{10,5},{11,5},{12,5},{13,5},
                            {14,0},{15,13},{16,13}}, *act);

    assert_eq_vector(std::vector<UFSetsNode<int>>({{1,-2}, {2,0}}), *(UFSets<int>({1, 2}).data()));
    assert_eq_UFSets_vector({{1,-2} , {2,0}} , UFSets<int>({1 , 2 }));
}

TEST(TestUFSetsClass, testUnionSetByNodeNum) {
std::vector<UFSets<int>> allSets = {
        {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8},
        {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}
    };

    UFSets<int> * lhs = nullptr;
    UFSets<int> * rhs = nullptr;
    UFSets<int> * act = nullptr;

    lhs = findAll(1, allSets);
    rhs = findAll(2, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{1,-2} , {2,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(4, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-2},{4,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(5, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-3},{4,0},{5,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(7, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{1,-3},{2,0},{7,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(6, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-4},{4,0},{5,0},{6,0}}, *act);

    lhs = findAll(8, allSets);
    rhs = findAll(9, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{8,-2},{9,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(8, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{1,-5},{2,0},{7,0},{8,0},{9,3}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(10, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-5},{4,0},{5,0},{6,0},{10,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(11, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-6},{4,0},{5,0},{6,0},{10,0},{11,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(12, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-7},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0}}, *act);

    lhs = findAll(3, allSets);
    rhs = findAll(13, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-8},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0}}, *act);

    lhs = findAll(14, allSets);
    rhs = findAll(15, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{14,-2},{15,0}}, *act);

    lhs = findAll(16, allSets);
    rhs = findAll(0, allSets);
    act = lhs;
    ASSERT_EQ(nullptr, rhs);

    lhs = findAll(14, allSets);
    rhs = findAll(16, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{14,-3},{15,0},{16,0}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(3, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-13},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0},
                             {1,-0},{2,8},{7,8},{8,8},{9,11}}, *act);

    lhs = findAll(1, allSets);
    rhs = findAll(14, allSets);
    act = lhs;
    lhs->unionSetByNodeNum(*rhs);
    assert_eq_UFSets_vector({{3,-16},{4,0},{5,0},{6,0},{10,0},{11,0},{12,0},{13,0},
                             {1,-0},{2,8},{7,8},{8,8},{9,11},
                            {14,0},{15,13},{16,13}}, *act);

    assert_eq_vector(std::vector<UFSetsNode<int>>({{1,-2}, {2,0}}), *(UFSets<int>({1, 2}).data()));
    assert_eq_UFSets_vector({{1,-2} , {2,0}} , UFSets<int>({1 , 2 }));
}


int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
