#pragma once
// gtest
#include <gtest/gtest.h>
// STL
#include <sstream>
#include <vector>
#include <string>

template <typename T>
void assert_eq_LinkedList_vector(const LinkedList<T> & lst, const std::vector<T> & vec);

template <typename T>
void assert_eq_LinkedList_LinkedList(const LinkedList<T> & lhs, const LinkedList<T> & rhs);

template <typename T>
std::string to_string(const LinkedList<T> & lst);

template <typename T>
std::string to_string(const std::vector<T> & vec);

#include "helper.tcc"
