#pragma once

template <typename T>
MaxHeap<T>::MaxHeap(const std::vector<T> & vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        this->push(*it);
    }
}

template <typename T>
void MaxHeap<T>::push(const T & val) {
    m_data.push_back(val);
    std::size_t index = m_data.size() - 1;
    std::size_t parentIndex = 0;
    while(index != 0){
        parentIndex = (index - 1) / 2;
        if(m_data[parentIndex] < m_data[index]) {
            std::swap(m_data[parentIndex], m_data[index]);
        }
        index = parentIndex;
    }
}

template <typename T>
void MaxHeap<T>::pop() {
    std::swap(m_data[0], m_data[m_data.size() - 1]);
    m_data.pop_back();
    std::size_t index = 0;
    while(index < m_data.size()) {
        std::size_t left = index * 2 + 1;
        std::size_t right = index * 2 + 2;

        if(left < m_data.size() && right < m_data.size()) {
            // has both children
            std::size_t bigChild = 0;
            if(m_data[left] > m_data[right]) {
                bigChild = left;
            } else {
                bigChild = right;
            }
            if(m_data[index] < m_data[bigChild]) {
                std::swap(m_data[index], m_data[bigChild]);
                index = bigChild;
            } else {
                break;
            }
        } else if(left < m_data.size() && right >= m_data.size()) {
            // has only left child
            if(m_data[index] < m_data[left]) {
                std::swap(m_data[index], m_data[left]);
                index = left;
            } else {
                break;
            }
        } else {
            // no child
            break;
        }
    }
}



