#include <iostream>
#include <vector>
//Current Project
#include "MinHeap.hpp"
#include "MaxHeap.hpp"

template <typename T>
void printVec(const std::vector<T> & vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void printMinHeapTest(MinHeap<T> heap, std::vector<T> myvec) {
    std::cout << "original sequence     : ";
    printVec(myvec);
    std::cout << "min heap sequence     : ";
    printVec(heap.data());
    std::cout << "min heap pop sequence : ";
    while(not heap.data().empty()) {
        auto top = heap.top();
        std::cout << top << ' ';
        heap.pop();
    }
    std::cout << std::endl << std::endl;
}

template <typename T>
void printMaxHeapTest(MaxHeap<T> heap, std::vector<T> myvec) {
    std::cout << "max heap sequence     : ";
    printVec(heap.data());
    std::cout << "max heap pop sequence : ";
    while(not heap.data().empty()) {
        auto top = heap.top();
        std::cout << top << ' ';
        heap.pop();
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    std::vector<int> vec1{80, 57, 99, 35, 23, 11, 74, 29, 62, 16};
    MinHeap<int> heap1(vec1);
    printMinHeapTest(heap1, vec1);

    MaxHeap<int> heap11(vec1);
    printMaxHeapTest(heap11, vec1);

    std::vector<int> vec2{1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    MinHeap<int> heap2(vec2);
    printMinHeapTest(heap2, vec2);

    MaxHeap<int> heap21(vec2);
    printMaxHeapTest(heap21, vec2);

    std::vector<int> vec3{9, 8, 7, 6, 5, 4, 3, 2, 1};
    MinHeap<int> heap3(vec3);
    printMinHeapTest(heap3, vec3);

    MaxHeap<int> heap31(vec3);
    printMaxHeapTest(heap31, vec3);

    std::vector<int> vec4{1, 2, 3, 4, 5, 6, 7, 8, 9};
    MinHeap<int> heap4(vec4);
    printMinHeapTest(heap4, vec4);

    MaxHeap<int> heap41(vec4);
    printMaxHeapTest(heap41, vec4);

    std::vector<int> vec5{66};
    MinHeap<int> heap5(vec5);
    printMinHeapTest(heap5, vec5);

    MaxHeap<int> heap51(vec5);
    printMaxHeapTest(heap51, vec5);

    std::vector<int> vec6{};
    MinHeap<int> heap6(vec6);
    printMinHeapTest(heap6, vec6);

    MaxHeap<int> heap61(vec6);
    printMaxHeapTest(heap61, vec6);

    return 0;
}
