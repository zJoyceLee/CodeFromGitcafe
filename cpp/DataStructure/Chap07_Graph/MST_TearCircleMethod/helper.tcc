#pragma once

template <typename T>
void assert_eq_vector(const std::vector<T> & expectVec, const std::vector<T> & actualVec) {
    // 1. Check size
    ASSERT_EQ(expectVec.size(), actualVec.size())
        << "Expect: " << to_string(expectVec) << std::endl
        << "Actual: " << to_string(actualVec);

    // 2. Check element by element
    typename std::vector<T>::const_iterator actualVecIter = actualVec.begin();
    typename std::vector<T>::const_iterator expectVecIter = expectVec.begin();
    while(expectVecIter != expectVec.end()) {
        ASSERT_EQ(*expectVecIter, *actualVecIter)
            << "Expect: " << to_string(expectVec) << std::endl
            << "Actual: " << to_string(actualVec);

        ++expectVecIter;
        ++actualVecIter;
    }//while
}

template <typename T>
void assert_eq_vector_vector(const std::vector<std::vector<T>> & expect, const std::vector<std::vector<T>> & actual) {
    for(std::size_t i = 0; i < expect.size(); ++i) {
        assert_eq_vector(expect[i], actual[i]);
    }
}


template <typename T>
std::string to_string(const std::vector<T> & vec) {
    std::ostringstream oss;
    oss << "[";
    for(auto i : vec)
        oss << i << ",";
    oss << "\b]";
    return oss.str();
}
