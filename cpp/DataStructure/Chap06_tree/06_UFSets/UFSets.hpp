#pragma once

//STL
#include <vector>
//Current-Project
#include "UFSetsNode.hpp"

template <typename T>
class UFSets {
private:
    std::vector<UFSetsNode<T>> m_vec;
private:
    //std::size_t getElementHeight(std::size_t index);
public:
    UFSets(const std::vector<T> & myvec);

    UFSets(const std::initializer_list<T> & init);

    UFSets(const UFSets & rhs) :
        m_vec(rhs.m_vec)
    {}
    ~UFSets() {}

    std::vector<UFSetsNode<T>> * data() { return &(m_vec); }
    const std::vector<UFSetsNode<T>> * data() const { return &(m_vec); }

    void unionSet(const UFSets<T> & rhs);
    void unionSetByHeight(const UFSets<T> & rhs);
    void unionSetByNodeNum(const UFSets<T> & rhs);

    std::size_t height();

    bool find(const T & value) const;

    void swap(UFSets<T> & rhs);
};

template <typename T>
UFSets<T> * findAll(const T & value, std::vector<UFSets<T>> & vec);

#include "UFSets.tcc"
