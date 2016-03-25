#pragma once
// STL
#include <vector>
#include <stdexcept>

template <typename T>
T head(const std::vector<T> & xs);

template <typename T>
std::vector<T> tail(const std::vector<T> & xs);

template <typename T>
std::vector<T> concat(const std::vector<T> & xs, const std::vector<T> & ys);

template <typename T>
std::vector<T> addFront(const T & x, const std::vector<T> & xs);

#include "util.tcc"
