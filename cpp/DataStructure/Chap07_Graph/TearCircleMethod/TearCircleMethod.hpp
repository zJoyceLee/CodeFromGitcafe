#pragma once
//Current-Project
#include "AdjMatrixUndirNetwork.hpp"

struct Edge {
	int vertex1;
	int vertex2;
	int weight;
};

template <typename T, typename WT>
AdjMatrixUndirNetwork<T, WT>  MST(const AdjMatrixUndirNetwork<T, WT> & g) {
	Edge edge[100];
	int edge_num = 0;
	AdjMatrixUndirNetwork<T, WT> g_temp = g;
	for (std::size_t v = 0; v < g_temp.GetVexNum(); ++v) {
        for (std::size_t u = g_temp.FirstAdjVex(v); u >= 0; u = g_temp.NextAdjVex(v, u)) {
			if (v < u){
                edge[edge_num].vertex1 = v;
                edge[edge_num].vertex2 = u;
                edge[edge_num].weight = g_temp.GetWeight(v,u);
                ++edge_num;
			}
        }
	} //construct Edge

	for(int i = edge_num; i >= 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(edge[j].weight < edge[j+1].weight) {
				Edge t = edge[j];
				edge[j] = edge[j+1];
				edge[j+1] = t;
			}
        }
    } //sort all edges from max to min

	for (int i = 0; i < edge_num; ++i) {
		g_temp.DeleteArc(edge[i].vertex1,edge[i].vertex2);
        if(!g_temp.concludeCircle()) {
                //template <typename T, typename WT>
                //bool AdjMatrixUndirNetwork<T, WT>::concludeCircle() {
                //  	for(int i = 0; i < vexNum; ++i)
                //  		tag[i] = UNVISITED;
                //  	Visit(0);
                //	for(int i = 0; i < vexNum; ++i)
                //  		if(tag[i] != VISITED)
                //  			return false;
                //  	return true;
                //}
                //template <typename T, typename WT>
                //void AdjMatrixUndirNetwork<T, WT>::Visit(int v) {
                //	if(tag[v] == VISITED)
                //		return;
                //	tag[v] = VISITED;
                //	for(int i_v = FirstAdjVex(v); i_v != -1; i_v = NextAdjVex(v,i_v))
                ///		Visit(i_v); -->  Recursion
                //}
            g_temp.InsertArc(edge[i].vertex1,edge[i].vertex2,edge[i].weight);
        }
	}
	return g_temp;
}
