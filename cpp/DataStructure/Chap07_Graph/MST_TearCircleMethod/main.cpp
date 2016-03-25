//STL
#include <vector>
//Current Project
#include "TCM.h"
#include "helper.hpp"
//g-test
#include "gtest/gtest.h"

//#ifdef _No_gtest
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
		AdjMatrixUndirGraph<char> net(vexs, n);
		for (int u = 0; u < n; ++u)
			for (int v = u + 1; v < n; ++v)
				if (m[u][v] != infity)
                    net.InsertArc(u, v, m);

		std::cout << "graph_matrix: " << std::endl;
		net.Display();
		std::cout << std::endl;
		Is_it_all_in_circle(net);

		std::cout << "MST: " << std::endl;
		//MST(net);
		MST(net).Display();
		std::cout << std::endl;

		std::cout << "-------------------------------------------------" << std::endl;

        int MaxInt = DEFAULT_INFINITY;
        char vertex[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
        int graphMatrix[6][6] = {
            {MaxInt,       5,       5,       6,  MaxInt,  MaxInt},
            {     6,  MaxInt,       2,       4,  MaxInt,  MaxInt},
            {     5,       2,  MaxInt,       5,  MaxInt,  MaxInt},
            {     6,       4,       4,  MaxInt,  MaxInt,  MaxInt},
            {MaxInt,  MaxInt,  MaxInt,  MaxInt,  MaxInt,  MaxInt},
            {MaxInt,  MaxInt,  MaxInt,  MaxInt,  MaxInt,  MaxInt}
        };
//        a--6--b      MST: a     b      a     b      a     b
//        |\   /|           |\   /|       \   /|       \   /|
//        | \ / |           | \ / |        \ / |        \ / |
//        6  /  2           6  /  2   ->    /  2   ->    /  2
//        | 4 5 |           | 4 5 |        4 5 |        4 5 |
//        |/   \|           |/   \|       /   \|       /   \|
//        d--5--c           d--5--c      d--5--c      d     c

        int x = 6;
        AdjMatrixUndirGraph<char> graph(vertex, x);

		for (int u = 0; u < x; ++u)
			for (int v = u + 1; v < x; ++v)
				if (graphMatrix[u][v] != MaxInt)
                    graph.InsertArc(u, v, graphMatrix);
        std::cout << "graph_matrix: " << std::endl;
		graph.Display();
		std::cout << std::endl;
		Is_it_all_in_circle(graph);

		std::cout << "MST: " << std::endl;
		MST(graph).Display();
		std::cout << std::endl;
    }
	catch (Error err) {
		err.Show();
	}

	return 0;
}
//#endif // _No_gtest

#ifdef _gtest
TEST(TearCircleMethodTest, testMST) {
    //int MaxInt = std::numeric_limits<int>::max();
    int MaxInt = DEFAULT_INFINITY;
    char vertexs[4] = {'a', 'b', 'c', 'd'};
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
    AdjMatrixUndirGraph<char> net(vertexs, n);
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
