//STL
#include <iostream>
#include <vector>
#include <algorithm>
//Current Project
#include "LinkedList.hpp"

void printFloat(const float & i) {
    std::cout << i << " ";
}

int main(int argc, char * argv[]) {

    std::cout << "LinledList: ";
    LinkedList<float> lst({1, 2, 3, 4, 5});
    lst.traverse(printFloat);
    std::cout << std::endl << std::endl;

    //test Case1, insert at the middle------------------------------------------------------
    std::cout << "testCase1: insert at the middle. And remove one element." << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    LinkedList<float> lst1({1, 2, 3, 4, 5});
    auto p1 = lst1.find(lst1.begin(),[](const float & i) { return i == 3;});
    if(p1 == nullptr) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "insert 3.1415 before " << p1->data() << std::endl;
        lst1.insertBefore(p1,3.1415);
        lst1.traverse(printFloat);
        std::cout << std::endl;

        std::cout << "trying to remove: " << p1->data() << std::endl;
        lst1.remove(p1);
        lst1.traverse(printFloat);
        std::cout << std::endl;
    }
    std::cout << "Swap the max and the min : " << std::endl;
    lst1.swapMinMax(std::less<float>());
    lst1.traverse(printFloat);
    std::cout << std::endl << std::endl << std::endl;


    //test Case 2, insert at the first-------------------------------------------------------
    std::cout << "testCase2: insert at the first. And remove the first one." << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    LinkedList<float> lst2({1, 2, 3, 4, 5});
    auto p2 = lst2.find(lst2.begin(),[](const float & i) { return i == 1;});
    if(p2 == nullptr) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "insert 1.57 before " << p2->data() << std::endl;
        lst2.insertBefore(p2,1.57);
        lst2.traverse(printFloat);
        std::cout << std::endl;

        std::cout << "trying to remove the first one: " << p2->prev()->data() << std::endl;
        lst2.remove(p2->prev());
    }
    lst2.traverse(printFloat);
    std::cout << std::endl << std::endl << std::endl;


    //test Case 3, insert at the end---------------------------------------------------------
     std::cout << "testCase3: insert at the first. And remove the last one." << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;

    LinkedList<float> lst3({1, 2, 3, 4, 5});
    auto p3 = lst3.find(lst3.begin(),[](const float & i) { return i == 5 ;});
    if(p3 == nullptr) {
        std::cout << "nullptr" << std::endl;
    } else {
        std::cout << "remove the last one \"" << p3->data() << "\": " <<std::endl;
        lst3.remove(p3);
        lst3.traverse(printFloat);

        std::cout << std::endl << "insert \"100\" at the last : " << std::endl;
        lst3.insertAfter(p3->prev(), 100);
        lst3.traverse(printFloat);

    }
    std::cout << std::endl << std::endl << std::endl;



    return 0;
}
