//STL
#include <iostream>
//Current Project
#include "SeqStack.hpp"
#include "CarInfo.hpp"

//void

int main()
{
    std::cout << "TestCase1:" << std::endl;
    SeqStack<CarInfo>(2) stk1;
    LinkedQueue<CarInfo> lqu1;
    CarInfo c11 {"A", 1, 5};
    CarInfo c12 {"A", 2, 10};
    CarInfo c13 {"D", 1, 15};
    CarInfo c14 {"A", 3, 20};
    CarInfo c15 {"A", 4, 25};
    CarInfo c16 {"A", 5, 30};
    CarInfo c17 {"A", 2, 5};
    CarInfo c18 {"A", 4, 10};



    return 0;
}
