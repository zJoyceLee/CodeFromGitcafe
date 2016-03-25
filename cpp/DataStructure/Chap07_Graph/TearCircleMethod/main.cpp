//STL
#include <iostream>
#include <limits>
//Current-Project
#include "Assistant.hpp"
#include "TearCircleMethod.hpp"
#include "helper.hpp"
#include "AdjMatrixUndirNetwork.hpp"
//g-test
#include <gtest/gtest.h>

TEST(TearCircleMethodTest, testMST) {
    int MaxInt = std::numeric_limits<int>::max();
//    std::vector<char> vertex = {'a', 'b', 'c', 'd'};
    char vertex[4] = {'a', 'b', 'c', 'd'};
//    std::vector<std::vector<int>> graphMatrix = {
    int graphMatrix[4][4] = {
        {MaxInt,       5,       5,      6},
        {     6,  MaxInt,       2,      4},
        {     5,       2,  MaxInt,      5},
        {     6,       4,       4,  MaxInt}
//        a--6--b      MST: a     b      a     b      a     b
//        |\   /|           |\   /|       \   /|       \   /|
//        | \ / |           | \ / |        \ / |        \ / |
//        6  /  2           6  /  2   ->    /  2   ->    /  2
//        | 4 5 |           | 4 5 |        4 5 |        4 5 |
//        |/   \|           |/   \|       /   \|       /   \|
//        d--5--c           d--5--c      d--5--c      d     c
    };
    int n = 4;
    AdjMatrixUndirNetwork<char, int> net(vertex, n);
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v){
            if (graphMatrix[u][v] != MaxInt) {
                net.InsertArc(u, v, graphMatrix[u][v]);
            }
        }
    }
    std::vector<std::vector<int>> expectGraphMatrix = {
        {MaxInt,  MaxInt,       5,  MaxInt},
        {MaxInt,  MaxInt,       2,       4},
        {     5,       2,  MaxInt,  MaxInt},
        {MaxInt,       4,  MaxInt,  MaxInt}
    };
    assert_eq_vector_vector(expectGraphMatrix, MST(net).toVectorOfVector());

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
