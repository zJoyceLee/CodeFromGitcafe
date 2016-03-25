// gtest
#include <gtest/gtest.h>
// STL
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// Current Project
#include "LinkedList.hpp"
#include "SingleLinkedStack.hpp"
#include "CarInfo.hpp"

std::string to_string(const CarInfo & car) {
    std::string ret;
    ret += car.m_carNum;
    ret += ", ";
    ret += std::to_string(car.m_year) + "-" + std::to_string(car.m_month) + "-" + std::to_string(car.m_day);
    ret += ", ";
    ret += std::to_string(car.m_hour) + "-" + std::to_string(car.m_minute) + "-" + std::to_string(car.m_second);
    return ret;
}

TEST(SingleLinkedStackTest, constructor) {
    SingleLinkedStack<int> stk;
}

TEST(SingleLinkedStackTest, CarInfoToString) {
    ASSERT_STREQ("JA87G87, 2014-12-9, 19-0-0", to_string({"JA87G87", 2014, 12, 9, 19, 0, 0}).c_str());
}

TEST(SingleLinkedStackTest, capacityTest) {
    SingleLinkedStack<CarInfo> stk;

    CarInfo c1 {"JA87G87", 2014, 12, 9, 19, 0, 0};
    CarInfo c2 {"JA85877", 2014, 12, 9, 19, 10, 6};
    CarInfo c3 {"JB30840", 2014, 12, 9, 19, 12, 30};
    CarInfo c4 {"JB56X56", 2014, 12, 9, 19, 30, 0};
    CarInfo c5 {"JA88888", 2014, 12, 9, 19, 40, 30};
    CarInfo c6 {"JA88S88", 2014, 12, 9, 19, 45, 17};

    stk.push(c1);
    stk.push(c2);
    stk.push(c3);
    stk.push(c4);
    stk.push(c5);
    stk.push(c6);

        std::string expectStr(
R"(JA88S88, 2014-12-9, 19-45-17
JA88888, 2014-12-9, 19-40-30
JB56X56, 2014-12-9, 19-30-0
JB30840, 2014-12-9, 19-12-30
JA85877, 2014-12-9, 19-10-6
JA87G87, 2014-12-9, 19-0-0
)");

    std::string actualStr;
    stk.traverse([&actualStr](const CarInfo & car) { actualStr += to_string(car) + '\n'; });
    EXPECT_STREQ(expectStr.c_str(), actualStr.c_str());
}

TEST(SingleLinkedStackTest, popTest) {
    SingleLinkedStack<CarInfo> stk;

    CarInfo c1 {"JA87G87", 2014, 12, 9, 19, 0, 0};
    CarInfo c2 {"JA85877", 2014, 12, 9, 19, 10, 6};
    CarInfo c3 {"JB30840", 2014, 12, 9, 19, 12, 30};
    CarInfo c4 {"JB56X56", 2014, 12, 9, 19, 30, 0};
    CarInfo c5 {"JA88888", 2014, 12, 9, 19, 40, 30};
    CarInfo c6 {"JA88S88", 2014, 12, 9, 19, 45, 17};

    stk.push(c1);
    stk.push(c2);
    stk.push(c3);
    stk.push(c4);
    stk.push(c5);
    stk.push(c6);

    stk.pop(3);
    stk.pop(2);
    EXPECT_THROW(stk.pop(2), std::out_of_range);
}

int main(int argc, char * argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
/*
    SingleLinkedStack<CarInfo> lst;

    CarInfo c1 {"JA87G87", 2014, 12, 9, 19, 0, 0};
    CarInfo c2 {"JA85877", 2014, 12, 9, 19, 10, 6};
    CarInfo c3 {"JB30840", 2014, 12, 9, 19, 12, 30};
    CarInfo c4 {"JB56X56", 2014, 12, 9, 19, 30, 0};
    CarInfo c5 {"JA88888", 2014, 12, 9, 19, 40, 30};
    CarInfo c6 {"JA88S88", 2014, 12, 9, 19, 45, 17};

    std::cout << "Push: " << std::endl << std::endl;

    lst.push(c1);
    lst.push(c2);
    lst.push(c3);
    lst.push(c4);
    //std::cout << "max_length: " << lst.getCapacity() << std::endl;
    lst.traverse([](const CarInfo & car) { std::cout << to_string(car) << std::endl; });
    std::cout << std::endl;
    lst.push(c5);
    lst.push(c6);
    //std::cout << "max_length: " << lst.getCapacity() << std::endl;
    lst.traverse([](const CarInfo & car) { std::cout << to_string(car) << std::endl; });
    std::cout << std::endl << std::endl;


    std::cout << "Pop: " << std::endl << std::endl;

    lst.pop(3);
    lst.traverse([](const CarInfo & car) { std::cout << to_string(car) << std::endl; });
    std::cout << std::endl;
    lst.pop(2);
    lst.traverse([](const CarInfo & car) { std::cout << to_string(car) << std::endl; });
    std::cout << std::endl;
    lst.pop(2);
    lst.traverse([](const CarInfo & car) { std::cout << to_string(car) << std::endl; });
*/
    return RUN_ALL_TESTS();
}
