#pragma once
//STL
#include <vector>
//Current-Project
#include "Assistant.hpp"

template <typename T, typename WT>
class AdjMatrixUndirNetwork {
protected:
	int vexNum, vexMaxNum, edgeNum;
	int **arcs;
	T *vertexes;
	Status *tag;
	WT infinity;
public:
	AdjMatrixUndirNetwork(T es[], int vertexNum, int vertexMaxNum = std::numeric_limits<int>::max(),
							WT infinit = (WT)DEFAULT_INFINITY);
	AdjMatrixUndirNetwork(int vertexMaxNum = DEFAULT_SIZE, WT infinit = (WT)DEFAULT_INFINITY);
	~AdjMatrixUndirNetwork();

	void Clear();
	bool IsEmpty();
	int GetOrder(T & e) const;
	Status GetElem(int v, T & e) const;
	Status SetElem(int v, const T & e);
	WT GetInfinity() const;
	int GetVexNum() const;
	int GetEdgeNum() const;
	int FirstAdjVex(int v) const;
	int NextAdjVex(int v1, int v2) const;
	void InsertVex(const T & e);
	void DeleteVex(const T & e);
	void InsertArc(int v1, int v2, WT w);
	void DeleteArc(int v1, int v2);
	WT GetWeight(int v1, int v2) const;
	Status GetTag(int v) const;
	void SetTag(int v, Status val) const;
	AdjMatrixUndirNetwork(const AdjMatrixUndirNetwork<T, WT> & g);
	AdjMatrixUndirNetwork<T, WT> & operator =(const AdjMatrixUndirNetwork<T, WT> & g);

    void Display();
    std::vector<std::vector<WT>> toVectorOfVector();

public:
	bool concludeCircle();
protected:
  	void Visit(int v);
};

#include "AdjMatrixUndirNetwork.tcc"
