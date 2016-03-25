//STL
#include <iostream>
#include <limits>
#include <vector>
//Current-Project
#include "Assistant.hpp"
#include "TearCircle.hpp"
#include "helper.hpp"
#include "AdjMatrixUndirNetwork.hpp"
//g-test
#include <gtest/gtest.h>

#ifdef USE_INPUT
TEST(TearCircleMethodTest, testMST) {
    //int MaxInt = std::numeric_limits<int>::max();
    int MaxInt = INFINITY;
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
#endif


//#ifdef UN_USED_g-test
int main(int argc, char * argv[])
{
    try
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
			{infity,      12,      46,  infity,  infity,      33},
			{    12,  infity,  infity,  infity,      12,  infity},
			{    46,  infity,  infity,      17,  infity,      23},
			{infity,  infity,      17,  infity,      38,      23},
			{infity,      12,  infity,      38,  infity,      46},
			{    33,  infity,      23,      23,      46,  infity}
		};
		int n = 6;

		AdjMatrixUndirNetwork<char, int> net(vexs, n);

		for (int u = 0; u < n; ++u)
			for (int v = u + 1; v < n; ++v)
				if (m[u][v] != infity) net.InsertArc(u, v, m[u][v]);

		std::cout << "graph_matrix: " << std::endl;
		net.Display();
		std::cout << std::endl;
		net.concludeCircle();

		std::cout << "MST: " << std::endl;
		MST(net);
		std::cout << std::endl;
	}
	catch (Error err) {
		err.Show();
	}
    return 0;
}
//#endif
