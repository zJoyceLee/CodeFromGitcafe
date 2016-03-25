#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include "../HelloWorld/test.hpp"

/**
@url https://code.google.com/p/googletest/wiki/Primer

Fatal assertion	                Nonfatal assertion              Verifies
---------------------------------------------------------------------------------
ASSERT_TRUE(condition);	        EXPECT_TRUE(condition);	        condition is true
ASSERT_FALSE(condition);	    EXPECT_FALSE(condition);	    condition is false

ASSERT_EQ(expected, actual);	EXPECT_EQ(expected, actual);	expected == actual
ASSERT_NE(val1, val2);	        EXPECT_NE(val1, val2);	        val1 != val2
ASSERT_LT(val1, val2);	        EXPECT_LT(val1, val2);	        val1 < val2
ASSERT_LE(val1, val2);	        EXPECT_LE(val1, val2);	        val1 <= val2
ASSERT_GT(val1, val2);	        EXPECT_GT(val1, val2);	        val1 > val2
ASSERT_GE(val1, val2);	        EXPECT_GE(val1, val2);	        val1 >= val2

String Comparison
Fatal assertion	                Nonfatal assertion              Verifies
---------------------------------------------------------------------------------
ASSERT_STREQ(str1, str2);       EXPECT_STREQ(str1, str2);       the two C strings have the same content
ASSERT_STRNE(str1, str2);       EXPECT_STRNE(str1, str2);       the two C strings have different content
ASSERT_STRCASEEQ(str1, str2);   EXPECT_STRCASEEQ(str1, str2);   the two C strings have the same content, ignoring case
ASSERT_STRCASENE(str1, str2);   EXPECT_STRCASENE(str1, str2);   the two C strings have different content, ignoring case


*/

Hello he;

TEST(TestHelloWorldClass, testMySqrtFunc) {
    EXPECT_EQ(1, 1);
    EXPECT_EQ(0, 0);
    ASSERT_EQ(3, he.mySqrt());
    //std::cout << "Hello" << std::endl;
    EXPECT_EQ(2, 2);
}

TEST(TestHelloWorldClass, testMyDoubleFunc) {
    EXPECT_EQ(9, he.myDouble());
}

TEST(TestHelloWorldClass, testString) {
    std::string s("Hello World");
    EXPECT_STREQ("Hello World", "Hello World");
    EXPECT_STREQ("Hello World", s.data());
    EXPECT_STRCASEEQ("Hello World", "hello world");
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    he.myDouble() = 9.0;

    return RUN_ALL_TESTS();
}
