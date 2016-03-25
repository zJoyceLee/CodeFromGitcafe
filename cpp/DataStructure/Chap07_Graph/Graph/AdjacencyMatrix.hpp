#pragma once
//STL
#include <vector>

template <typename T>
class AdjacencyMatrix {
private:
    std::vector<T> m_vertex;
    std::vector<std::vector<std::size_t>> m_adjacencyMatrix;
public:
    AdjacencyMatrix() :
        m_vertex(),
        m_adjacencyMatrix()
    {}

    ~AdjacencyMatrix();
};

#include "AdjacencyMatrix.tcc"
