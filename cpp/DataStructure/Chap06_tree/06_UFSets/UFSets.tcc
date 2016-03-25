#pragma once

//template <typename T>
//std::size_t UFSets<T>::getElementHeight(const std::size_t & index) const {
//    std::size_t i = index;
//    std::size_t elementHeight = 1;
//
//}

template <typename T>
UFSets<T>::UFSets(const std::vector<T> & myvec) {
    if (myvec.size() == 0)
        return;

    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        m_vec.push_back(UFSetsNode<T> {*it, 0});
    }
    m_vec[0].parentIndex = -myvec.size();
}

template <typename T>
UFSets<T>::UFSets(const std::initializer_list<T> & init) {
    if (init.size() == 0)
        return;

    for(auto it = init.begin(); it != init.end(); ++it) {
        m_vec.push_back(UFSetsNode<T> {*it, 0});
    }
    m_vec[0].parentIndex = -init.size();
}

template <typename T>
void UFSets<T>::unionSet(const UFSets<T> & rhs) {
    if(rhs.data()->size() == 0)
        return;

    std::vector<UFSetsNode<T>> rhsVec = *(rhs.data());
    rhsVec[0].parentIndex = 0;
    for(std::size_t i = 1; i < rhsVec.size(); ++i) {
        rhsVec[i].parentIndex += m_vec.size();
    }
    for(auto it = rhsVec.begin(); it != rhsVec.end(); ++it) {
        m_vec.push_back(*it);
    }
    m_vec[0].parentIndex = -m_vec.size();
}

template <typename T>
void UFSets<T>::unionSetByHeight(const UFSets<T> & rhs) {
    UFSets<T> rhsCopy(rhs);
    if(this->height() < rhsCopy.height())
        this->swap(rhsCopy);
    this->unionSet(rhsCopy);
}

template <typename T>
void UFSets<T>::unionSetByNodeNum(const UFSets<T> & rhs) {
    UFSets<T> rhsCopy(rhs);
    if(m_vec.size() < rhsCopy.m_vec.size())
        this->swap(rhsCopy);
    this->unionSet(rhsCopy);
}

template <typename T>
std::size_t UFSets<T>::height() {
    std::size_t finalHeight = 0;
    //std::vector<UFSetsNode<T>> vec = *(lhs.data());
    for(std::size_t i = 0; i < m_vec.size(); ++i) {
        std::size_t height = 1;
        std::size_t index = i;
        while(m_vec[index].parentIndex >= 0) {
            index = m_vec[index].parentIndex;
            ++height;
        }
        if(finalHeight < height) {
            finalHeight = height;
        }
    }
    return finalHeight;
}


template <typename T>
bool UFSets<T>::find(const T & value) const {
    for(std::size_t i = 0; i < m_vec.size(); ++i) {
        if(m_vec[i].data == value)
            return true;
    }
    return false;
}

template <typename T>
void UFSets<T>::swap(UFSets<T> & rhs) {
    rhs.data()->swap(*(this->data()));
}

template <typename T>
UFSets<T> * findAll(const T & value, std::vector<UFSets<T>> & vec) {
    for(std::size_t i = 0; i < vec.size(); ++i) {
        if(vec[i].find(value) == true) {
            return &(vec[i]);
        }
    }
    return nullptr;
}
