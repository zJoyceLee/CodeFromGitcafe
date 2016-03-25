#include "helper.hpp"

void assert_eq_pair(const std::pair<int, int> & expectPair, const std::pair<int, int> & mypair) {
    ASSERT_EQ(expectPair.first, mypair.first);
    ASSERT_EQ(expectPair.second, mypair.second);
}

