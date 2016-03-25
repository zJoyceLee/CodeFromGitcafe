#pragma once

template <typename T>
T head(const std::vector<T> & xs) {
    if(xs.size() < 1)
        throw std::runtime_error("head: vector size is 0");
    return xs.front();
}

template <typename T>
std::vector<T> tail(const std::vector<T> & xs) {
    if(xs.size() < 1)
        throw std::runtime_error("tail: vector size is 0");
    return std::vector<T>(xs.begin()+1, xs.end());
}

template <typename T>
std::vector<T> concat(const std::vector<T> & xs, const std::vector<T> & ys) {
    std::vector<T> ret(xs);
    ret.insert(ret.end(), ys.begin(), ys.end());
    return ret;
}

template <typename T>
std::vector<T> addFront(const T & x, const std::vector<T> & xs) {
    std::vector<T> ret(xs);
    ret.insert(ret.begin(), x);
    return ret;
}
