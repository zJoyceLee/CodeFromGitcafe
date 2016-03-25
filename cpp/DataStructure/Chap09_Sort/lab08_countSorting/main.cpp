//STL
#include <vector>
#include <iostream>
//Current Test
//#include "gtest/gtest.h"

template <typename T>
void printVec(const std::vector<T> & myvec) {
    for(auto it = myvec.begin(); it != myvec.end(); ++it) {
        std::cout << *it << ". ";
    }std::cout << std::endl;
}

template <typename T>
std::vector<T> countSort(std::vector<T> & myvec) {
    std::vector<T> ret = myvec;
    for(std::size_t i = 0; i < myvec.size(); ++i) {
        T itself = myvec[i];
        std::size_t countLessThanItself = 0;
        for(std::size_t j = 0;j < myvec.size(); ++j) {
            if(myvec[j] < itself) {
                ++countLessThanItself;
            }
        }
        ret[countLessThanItself] = itself;
    }
    return ret;
}

int main(int argc, char * argv[]) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
    std::vector<int> myvec1 = {5,4,7,2,3,1,6};
    printVec(countSort(myvec1));
    std::cout <<"---------------------"<< std::endl;
    std::vector<int> myvec2 = {99, 82, 33, 101, 120, 77};
    printVec(countSort(myvec2));

    return 0;
}
