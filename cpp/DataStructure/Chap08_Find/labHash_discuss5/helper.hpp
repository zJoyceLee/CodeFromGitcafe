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
std::string to_string(const std::vector<T> & vec);

template <typename T>
void assert_eq_pair(const std::pair<T, bool> & expectPair, const std::pair<T, bool> & mypair);


#include "helper.tcc"




