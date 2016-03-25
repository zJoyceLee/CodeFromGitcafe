// STL
#include <iostream>
#include <algorithm>
#include <vector>
// C-Standard
#include <cstring>

template <typename T, typename UnaryFunc>
std::vector<T> map(const std::vector<T> & vec, UnaryFunc f) {
    std::vector<T> ret;
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        ret.push_back(f(*it));
    }
    return ret;
}

template <typename T, typename UnaryFunc>
std::vector<T> filter(const std::vector<T> & vec, UnaryFunc f) {
    std::vector<T> ret;
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        if(f(*it) == true)
            ret.push_back(*it);
    }
    return ret;
}

template <typename T, typename BinaryFunc>
T reduce(const std::vector<T> & vec, BinaryFunc f) {
    //f(x, y)
    T ret = vec[0];
    for(std::size_t i = 1; i < vec.size(); ++i) {
        ret = f(ret, vec[i]);
    }
    return ret;
}

template <typename T, typename U, typename BinaryFunc>
U reduce(const std::vector<T> & vec, const U & initValue, BinaryFunc f) {
    U ret = initValue;
    for(std::size_t i = 0; i < vec.size(); ++i) {
        ret = f(ret, vec[i]);
        //f(U, T)
    }
    return ret;
}

template <typename T>
void printVector(const std::vector<T> & vec) {
    for(auto it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v1 {1,2,3,4,5};

    auto v2 = map(v1, [](int i){ return i * 2; });
    v2 = filter(v1, [](int i){ return (i % 2 == 0); });

    int sum = reduce(v1, 0, [](int a, int b){ return a + b; });
    std::cout << sum << std::endl;

    const char * pstr = "Hello World For Joyce!";
    std::vector<char> v3(pstr, pstr + strlen(pstr));
    int spaceNum = reduce(v3, 0, [](int a, char b){
        if(b == ' ')
            return (a+1);
        return a;
    });
    std::cout << spaceNum << std::endl;

    printVector(v2);

    return 0;
}
