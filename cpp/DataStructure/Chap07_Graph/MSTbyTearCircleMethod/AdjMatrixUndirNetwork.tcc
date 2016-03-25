#pragma once

template <class T, class WT>
bool AdjMatrixUndirNetwork<T, WT>::concludeCircle() {
  	for(int i = 0; i < vexNum; ++i)
  		tag[i] = UNVISITED;
  	Visit(0);
	for(int i = 0; i < vexNum; ++i)
  		if(tag[i] != VISITED)
  			return false;
  	return true;
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::Visit(int v) {
	if(tag[v] == VISITED)
		return;
	tag[v] = VISITED;
	for(int i_v = FirstAdjVex(v); i_v != -1; i_v = NextAdjVex(v,i_v))
		Visit(i_v);
}

template <class T, class WT>
AdjMatrixUndirNetwork<T, WT>::AdjMatrixUndirNetwork(T es[], int vertexNum, int vertexMaxNum, WT infinit) {
	if (vertexMaxNum < 0)
    	throw Error("1.The number of vertex can't be minus!");
	if (vertexMaxNum < vertexNum)
    	throw Error("2.The number of vertex can't be over the max num!");

	vexNum = vertexNum;
	vexMaxNum = vertexMaxNum;
	edgeNum = 0;
	infinity = infinit;

	vertexes = new T[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = (int **)new int *[vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];

	for (int v = 0; v < vexNum; ++v) {
		vertexes[v] = es[v];
		tag[v] = UNVISITED;
		for (int u = 0; u < vexNum; ++u)
			arcs[v][u] = infinity;
		arcs[v][v] = 0;
	}
}

template <class T, class WT>
AdjMatrixUndirNetwork<T, WT>::AdjMatrixUndirNetwork(int vertexMaxNum, WT infinit) {
	if (vertexMaxNum < 0)
    	throw Error("3.The number of vertex can't be minus!!");

	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	edgeNum = 0;
	infinity = infinit;

	vertexes = new T[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = (int **)new int *[vexMaxNum];
	for (int v = 0; v < vexMaxNum; ++v)
		arcs[v] = new int[vexMaxNum];
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::Clear() {
    vexNum = 0;
	edgeNum = 0;
}

template <class T, class WT>
bool AdjMatrixUndirNetwork<T, WT>::IsEmpty() {
	return vexNum == 0;
}

template <class T, class WT>
AdjMatrixUndirNetwork<T, WT>::~AdjMatrixUndirNetwork() {
	delete []vertexes;
	delete []tag;

	for (int v = 0; v < vexMaxNum; ++v)
		delete []arcs[v];
	delete []arcs;
}

template <class T, class WT>
int AdjMatrixUndirNetwork<T, WT>::GetOrder(T &e) const {
    for (int v = 0; v < vexNum; v++)
        if (vertexes[v] == e)
		   return v;
	return -1;
}

template <class T, class WT>
Status AdjMatrixUndirNetwork<T, WT>::GetElem(int v, T &e) const {
	if (v < 0 || v >= vexNum) {
        return NOT_PRESENT;
	} else {
		e = vertexes[v];
		return ENTRY_FOUND;
	}
}

template <class T, class WT>
Status AdjMatrixUndirNetwork<T, WT>::SetElem(int v, const T &e) {
	if (v < 0 || v >= vexNum) {
		return RANGE_ERROR;
	} else {
		vertexes[v] = e;
		return SUCCESS;
	}
}

template <class T, class WT>
WT AdjMatrixUndirNetwork<T, WT>::GetInfinity() const {
	return infinity;
}

template <class T, class WT>
int AdjMatrixUndirNetwork<T, WT>::GetVexNum() const {
	return vexNum;
}

template <class T, class WT>
int AdjMatrixUndirNetwork<T, WT>::GetEdgeNum() const {
	return edgeNum;
}

template <class T, class WT>
int AdjMatrixUndirNetwork<T, WT>::FirstAdjVex(int v) const {
	if (v < 0 || v >= vexNum)
       throw Error("4.v is illegal!");

	for (int u = 0; u < vexNum; ++u) {
		if (arcs[v][u] != 0 && arcs[v][u] != infinity) {
       		return u;
        } else {
            return -1;
        }
    }
	return -1;
}

template <class T, class WT>
int AdjMatrixUndirNetwork<T, WT>::NextAdjVex(int v1, int v2) const {
	if (v1 < 0 || v1 >= vexNum)
       throw Error("5.v1 is illegal!");
	if (v2 < 0 || v2 >= vexNum)
       throw Error("6.v2 is illegal!");
	if (v1 == v2) throw
       Error("7.v1 can't be equal to v2!");

	for (int u = v2 + 1; u < vexNum; ++u) {
		if (arcs[v1][u] != 0 && arcs[v1][u] != infinity)
       		return u;
    }
	return -1;
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::InsertVex(const T &e) {
	if (vexNum == vexMaxNum)
    throw Error("8.The vertex need to be deleted isn't in the graph!");

	vertexes[vexNum] = e;
	tag[vexNum] = UNVISITED;

	for (int v = 0; v < vexNum; ++v) {
		arcs[vexNum][v] = infinity;
		arcs[v][vexNum] = infinity;
  	}
  	arcs[vexNum][vexNum] = 0;
  	++vexNum;
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::InsertArc(int v1, int v2, WT w) {
	if (v1 < 0 || v1 >= vexNum)
    throw Error("9.v1 is illegal!");
	if (v2 < 0 || v2 >= vexNum)
    throw Error("10.v2 is illegal!");
	if (v1 == v2)
    throw Error("11.v1 can't be equal to v2!");

	if (arcs[v1][v2] == infinity)	{
	   ++edgeNum;
	   arcs[v1][v2] = w;
       arcs[v2][v1] = w;
    }
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::DeleteVex(const T &e) {
   int v;
   for (v = 0; v < vexNum; ++v)
     if	(vertexes[v] == e)
        break;
   if (v == vexNum)
      throw Error("12.The vertex need to be deleted isn't in the graph!");

   for (int u = 0; u < vexNum; ++u)
	  if (u != v && arcs[v][u] != infinity) {
		--edgeNum;
	    arcs[v][u] = infinity;
        arcs[u][v] = infinity;
    }

   --vexNum;
   if (v < vexNum) {
      vertexes[v] = vertexes[vexNum];
	  tag[v] = tag[vexNum];
	  for (int u = 0; u <= vexNum; u++)
		 arcs[v][u] = arcs[vexNum][u];
	  for (int u = 0; u <= vexNum; u++)
         arcs[u][v] = arcs[u][vexNum];
   }
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::DeleteArc(int v1, int v2) {
	if (v1 < 0 || v1 >= vexNum)
    throw Error("13.v1 is illegal!");
	if (v2 < 0 || v2 >= vexNum)
    throw Error("14.v2 is illegal!");
	if (v1 == v2)
    throw Error("15.v1 can't be equal to v2!");

	if (arcs[v1][v2] != infinity)	{
		edgeNum--;
	    arcs[v1][v2] = infinity;
        arcs[v2][v1] = infinity;
    }
}

template <class T, class WT>
WT AdjMatrixUndirNetwork<T, WT>::GetWeight(int v1, int v2) const {
	if (v1 < 0 || v1 >= vexNum) throw Error("16.v1 is illegal!");
	if (v2 < 0 || v2 >= vexNum) throw Error("17.v2 is illegal!");

	return arcs[v1][v2];
}

template <class T, class WT>
Status AdjMatrixUndirNetwork<T, WT>::GetTag(int v) const {
	if (v < 0 || v >= vexNum)
    throw Error("18.v is illegal!");

	return tag[v];
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::SetTag(int v, Status val) const {
	if (v < 0 || v >= vexNum)
    throw Error("19.v is illegal!");

	tag[v] = val;
}

template <class T, class WT>
AdjMatrixUndirNetwork<T, WT>::AdjMatrixUndirNetwork(const AdjMatrixUndirNetwork<T, WT> &g) {
	vexNum = g.vexNum;
	vexMaxNum = g.vexMaxNum;
	edgeNum = g.edgeNum;
	infinity = g.infinity;

	vertexes = new T[vexMaxNum];
	tag = new Status[vexMaxNum];
	arcs = (int **)new int *[vexMaxNum];
	for (int v = 0; v < vexMaxNum; ++v)
		arcs[v] = new int[vexMaxNum];

	for (int v = 0; v < vexNum; ++v) {
		vertexes[v] = g.vertexes[v];
		tag[v] = g.tag[v];
		for (int u = 0; u < vexNum; ++u)
			arcs[v][u] = g.arcs[v][u];
	}
}

template <class T, class WT>
AdjMatrixUndirNetwork<T, WT> &AdjMatrixUndirNetwork<T, WT>::operator =(const AdjMatrixUndirNetwork<T, WT> &g) {
	if (&g != this)	{
		delete []vertexes;
		delete []tag;

	  	for (int v = 0; v < vexMaxNum; v++)
	 		delete []arcs[v];
    	delete []arcs;
		vexNum = g.vexNum;
    	vexMaxNum = g.vexMaxNum;
		edgeNum = g.edgeNum;
		infinity = g.infinity;

		vertexes = new T[vexMaxNum];
		tag = new Status[vexMaxNum];
		arcs = (int **)new int *[vexMaxNum];
		for (int v = 0; v < vexMaxNum; v++)
			arcs[v] = new int[vexMaxNum];

		for (int v = 0; v < vexNum; v++) {
			vertexes[v] = g.vertexes[v];
			tag[v] = g.tag[v];
			for (int u = 0; u < vexNum; u++)
	    		arcs[v][u] = g.arcs[v][u];
		}
	}
	return *this;
}

template <class T, class WT>
void AdjMatrixUndirNetwork<T, WT>::Display() {

	for (int v = 0; v < vexNum; ++v)
 		std::cout << "\t" << vertexes[v];
	std::cout << std::endl;

	for (int v = 0; v < vexNum; ++v)	{
		std::cout << vertexes[v];
		for (int u = 0; u < vexNum; ++u)
			if (arcs[v][u] == infinity)
				std::cout << "\t" << "∞";
			else
				std::cout << "\t" << arcs[v][u];
		std::cout << std::endl;
	}
}

//template <typename T, typename WT>
//std::vector<std::vector<WT>> AdjMatrixUndirNetwork<T, WT>::toVectorOfVector() {
//    std::vector<std::vector<WT>> matrix;
//    for(int i = 0; i < vexNum; ++i) {
//        for (int j = 0; j < vexNum; ++j) {
//            matrix[i].push_back(arcs[i][j]);
//        }
//        matrix.push_back(matrix[i]);
//	}
//	return matrix;
//}
