#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "util.hpp"

using vec = std::vector<int>;
using namespace std;

TEST(RecursionExample, Basics) {
    EXPECT_EQ    ( head(vec{1,2,3}),              1               );
    EXPECT_EQ    ( head(vec{1}),                  1               );
    EXPECT_THROW ( head(vec{}),                   runtime_error   );

    EXPECT_EQ    ( tail(vec{1,2,3}),              (vec{2,3})      );
    EXPECT_EQ    ( tail(vec{1}),                  (vec{})         );
    EXPECT_THROW ( tail(vec{}),                   runtime_error   );

    EXPECT_EQ    ( concat(vec{1}, vec{2,3}),      (vec{1,2,3})    );
    EXPECT_EQ    ( concat(vec{}, vec{1,2}),       (vec{1,2})      );
    EXPECT_EQ    ( concat(vec{}, vec{}),          (vec{})         );

    EXPECT_EQ    ( addFront(1, vec{2,3}),         (vec{1,2,3})    );
    EXPECT_EQ    ( addFront(1, vec{}),            (vec{1})        );
}

int factorial(int n) {
    if(n == 0)
        return 1;
    return n * factorial(n-1);
}

TEST(RecursionExample, factorialTest) {
    EXPECT_EQ    ( factorial(0),                  1               );
    EXPECT_EQ    ( factorial(1),                  1*1             );
    EXPECT_EQ    ( factorial(2),                  2*1*1           );
    EXPECT_EQ    ( factorial(3),                  3*2*1*1         );
}

int product(vec v) {
    if(v == vec{})
        return 1;
    return head(v) * product(tail(v));
}

TEST(RecursionExample, productTest) {
    EXPECT_EQ    ( product(vec{}),                1               );
    EXPECT_EQ    ( product(vec{3,4}),             3*4*1           );
    EXPECT_EQ    ( product(vec{5,4,3}),           5*4*3*1         );
    EXPECT_EQ    ( product(vec{8,2,3,4}),         8*2*3*4*1       );
}

int length(vec v) {
    if(v == vec{})
        return 0;
    return 1 + length(tail(v));
}

TEST(RecursionExample, lengthTest) {
    EXPECT_EQ    ( length(vec{}),                 0               );
    EXPECT_EQ    ( length(vec{3,4}),              1+1+0           );
    EXPECT_EQ    ( length(vec{5,4,3}),            1+1+1+0         );
    EXPECT_EQ    ( length(vec{8,2,3,4}),          1+1+1+1+0       );
}

vec reverse(vec v) {
    if(v == vec{})
        return vec{};
    return concat(reverse(tail(v)), vec{head(v)});
}

TEST(RecursionExample, reverseTest) {
    EXPECT_EQ    ( reverse(vec{}),                (vec{})         );
    EXPECT_EQ    ( reverse(vec{3,4}),             (vec{4,3})      );
    EXPECT_EQ    ( reverse(vec{5,4,3}),           (vec{3,4,5})    );
    EXPECT_EQ    ( reverse(vec{8,2,3,4}),         (vec{4,3,2,8})  );
}

vec drop(int n, vec v) {
    if(n == 0)
        return v;
    if(v == vec{})
        return vec{};
    return drop(n-1, tail(v));
}

TEST(RecursionExample, dropTest) {
    EXPECT_EQ    ( drop(3, vec{}),                (vec{})         );
    EXPECT_EQ    ( drop(5, vec{3,4}),             (vec{})         );
    EXPECT_EQ    ( drop(2, vec{5,4,3}),           (vec{3})        );
    EXPECT_EQ    ( drop(2, vec{8,2,3,4}),         (vec{3,4})      );
    EXPECT_EQ    ( drop(0, vec{8,2,3,4}),         (vec{8,2,3,4})  );
}

vec take(int n, vec v) {
    if(n == 0)
        return vec{};
    if(v == vec{})
        return vec{};
    return addFront(head(v), take(n-1, tail(v)));
}

TEST(RecursionExample, takeTest) {
    EXPECT_EQ    ( take(3, vec{}),                (vec{})         );
    EXPECT_EQ    ( take(5, vec{3,4}),             (vec{3,4})      );
    EXPECT_EQ    ( take(2, vec{5,4,3}),           (vec{5,4})      );
    EXPECT_EQ    ( take(2, vec{8,2,3,4}),         (vec{8,2})      );
    EXPECT_EQ    ( take(0, vec{8,2,3,4}),         (vec{})         );
}

vec replicate(int n, int value) {
    if(n == 0)
        return vec{};
    return addFront(value, replicate(n-1, value));
}

TEST(RecursionExample, replicateTest) {
    EXPECT_EQ    ( replicate(0, 1),               (vec{})         );
    EXPECT_EQ    ( replicate(2, 1),               (vec{1,1})      );
    EXPECT_EQ    ( replicate(5, 7),               (vec{7,7,7,7,7}));
}

vec concat2(vec v1, vec v2) {
    if(v1 == vec{})
        return v2;
    return addFront(head(v1), concat2(tail(v1), v2));
}

TEST(RecursionExample, concat2Test) {
    EXPECT_EQ    ( concat2(vec{1}, vec{2,3}),     (vec{1,2,3})    );
    EXPECT_EQ    ( concat2(vec{}, vec{1,2}),      (vec{1,2})      );
    EXPECT_EQ    ( concat2(vec{}, vec{}),         (vec{})         );
}

vec getSmallerEq(int i, vec v) {
    if(v == vec{})
        return vec{};
    
    if(head(v) <= i)
        return addFront(head(v), getSmallerEq(i, tail(v)));
    else
        return getSmallerEq(i, tail(v));
}

vec getLarger(int i, vec v) {
    if(v == vec{})
        return vec{};

    if(head(v) > i)
        return addFront(head(v), getLarger(i, tail(v)));
    else
        return getLarger(i, tail(v));
}

TEST(RecursionExample, smallerLargerTest) {
    EXPECT_EQ    ( getSmallerEq(3, vec{4,3,2,3}),       (vec{3,2,3})        );
    EXPECT_EQ    ( getSmallerEq(3, vec{1,4,2,3,2,3,4}), (vec{1,2,3,2,3})    );
    EXPECT_EQ    ( getSmallerEq(3, vec{4}),             (vec{})             );

    EXPECT_EQ    ( getLarger   (3, vec{4,3,2,3}),       (vec{4})            );
    EXPECT_EQ    ( getLarger   (3, vec{1,4,2,3,5,1,7}), (vec{4,5,7})        );
    EXPECT_EQ    ( getLarger   (3, vec{2}),             (vec{})             );
}

vec concat3vecs(vec v1, vec v2, vec v3) {
    return concat(concat(v1, v2), v3);
}

vec quicksort(vec v) {
    if(v == vec{})
        return vec{};

    vec smallerEq = quicksort(getSmallerEq(head(v), tail(v)));
    vec larger    = quicksort(getLarger   (head(v), tail(v)));

    return concat3vecs(smallerEq, vec{head(v)}, larger);
}

TEST(RecursionExample, quicksortTest) {
    EXPECT_EQ    ( quicksort(vec{1,8,7,9,2,6,4,3}),     (vec{1,2,3,4,6,7,8,9}) );
    EXPECT_EQ    ( quicksort(vec{1,8,7,2,2,2,4,3}),     (vec{1,2,2,2,3,4,7,8}) );
    EXPECT_EQ    ( quicksort(vec{}),                    (vec{}) );
}

int main(int argc, char * argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

