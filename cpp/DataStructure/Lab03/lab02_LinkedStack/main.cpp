//STL
#include <iostream>
//Current Project
#include "Node.hpp"
#include "LinkedList.hpp"
#include "LinkedStack.hpp"
#include "CarInfo.hpp"

void printInt(const int & i) {
    std::cout << i << ' ';
}

void printStudent(const CarInfo & car) {
    std::cout << "CarNum: " << car.m_carNum <<std::endl;
    std::cout << "EnterTime: " << car.m_year << "-" << car.m_month << "-" << car.m_day;
    std::cout << " " << car.m_hour << "-" << car.m_minute << "-" << car.m_second;
    std::cout << std::endl;
    std::cout << "----------------------------" << std::endl;
}

/*bool comparatorLessStudent(const Student & lhs, const Student & rhs) {
    return lhs.m_telNum < rhs.m_telNum;
}*/

int main()
{
    std::cout << "CarInfo Test:" << std::endl << std::endl;

    LinkedList<CarInfo> lst;

    CarInfo c1 {"JA87G87", 2014, 12, 9, 19, 0, 0};
    CarInfo c2 {"JA85877", 2014, 12, 9, 19, 10, 6};
    CarInfo c3 {"JB30840", 2014, 12, 9, 19, 12, 30};
    CarInfo c4 {"JB56X56", 2014, 12, 9, 19, 30, 0};

    std::cout << "Push: " << std::endl << std::endl;

    lst.push_front(c1);
    lst.push_front(c2);
    lst.push_front(c3);
    lst.push_front(c4);

    lst.traverse(printStudent);
    std::cout << std::endl;

    return 0;
}
