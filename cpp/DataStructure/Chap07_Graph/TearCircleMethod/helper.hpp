#pragma once
// gtest
#include <gtest/gtest.h>
// STL
#include <sstream>
#include <vector>
#include <string>

template <typename T>
void assert_eq_vector(const std::vector<T> & expectVec, const std::vector<T> & vec);

template <typename T>
void assert_eq_vector_vector(const std::vector<std::vector<T>> & expect, const std::vector<std::vector<T>> & actual);

template <typename T>
std::string to_string(const std::vector<T> & vec);

#include "helper.tcc"

