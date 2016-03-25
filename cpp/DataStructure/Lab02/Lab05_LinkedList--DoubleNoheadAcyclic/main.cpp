// STL
#include <iostream>
#include <vector>
#include <algorithm>
// Current Project
#include "LinkedList.hpp"

void printFloat(const float & i) {
    std::cout << i << ' ';
}

int main(int argc, char * argv[])
{
    LinkedList<float> lst({1, 2, 3, 4, 5});

    auto p = lst.find(lst.begin(), [](const float & i) { return i == 3; });
    if(p == nullptr) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "insert 3.1415926 before " << p->data() << std::endl;
        lst.insertBefore(p, 3.1415926);

        std::cout << "trying to remove: " << p->data() << std::endl;
        lst.remove(p);
    }//if-else

    lst.swapMinMax(std::less<float>());

    lst.traverse(printFloat);
    std::cout << std::endl;

    return 0;
}
