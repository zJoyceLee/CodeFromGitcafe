/*
(1)定义一个结构体,描述学生信息。学生信息包括:学号、姓名、性别、班级和电
话号码等。用描述学生信息的结构体作为线性表的数据元素类型测试顺序表。
(2)在顺序表类模板中增加成员函数 max()和 min(),它们分别返回顺序表中元素值最
大的数据元素序号。
(3)修改顺序表类模板中的插入函数。顺序表中的元素从小到大存放,插入元素时根
据元素值的大小插入到顺序表的适当位置,保证顺序表的有序性。
*/
//STL
#include <iostream>
//C-Standard
#include <cstdlib>
//Current Project
#include "Student.hpp"
#include "SequentialList.hpp"

void printStudent(const Student & s) {
    std::cout << "StudentNum:" << s.m_studentNum << std::endl;
    std::cout << "Name:" << s.m_name << std::endl;
    std::cout << "Gender:" << s.m_gender << std::endl;
    std::cout << "Class:" << s.m_class << std::endl;
    std::cout << "TelNum:" << s.m_telNum << std::endl;
    std::cout << "----------" << std::endl;
}

template <std::size_t N>
void printAll(const SequentialList<Student, N> & lst) {
    for(std::size_t i = 0; i < lst.getLength(); ++i) {
        printStudent(lst[i]);
    }//for
}

template <std::size_t N>
void printAll(const SequentialList<int, N> & lst) {
    for(std::size_t i = 0; i < lst.getLength(); ++i) {
        std::cout << lst[i] << ' ';
    }
    std::cout << std::endl;
}

bool intComparator(int i1, int i2) {
    return i1 < i2;
}

int main()
{
    SequentialList<Student, 5> lst;

    Student s;
    s.m_studentNum = "13122550";
    s.m_name = "Li Yuzhe";
    s.m_gender = "female";
    s.m_class = 5;
    s.m_telNum = "18717897080";
    lst.push_back(s);

    Student s2 {"11122057", "Yang Yang", "male", 3, "13761283909"};
    lst.push_back(s2);

    lst.push_back({"13122547", "Wang Xiaofan", "female", 5, "13061980587"});
    lst.push_back({"13122543", "Zhang Xinran", "female", 7, "18721007181"});
    lst.push_back({"13120000", "Tommy Green", "male", 9, "12345678901"});

    try {
        lst.push_back({"10986625", "Alex Woodz", "male", 11, "10987654321"});
    } catch(std::runtime_error & e) {
        std::cerr << "catch error: " << e.what() << std::endl;
    }//try-catch

    std::cout << lst.getLength() << std::endl;

    //printAll(lst);

    auto index = lst.find(0, [](const Student & s) {
        return (s.m_class == 5);
    });
    printStudent(lst[index]);


    std::cout << "Students in class 5: " << std::endl;
    auto findIndices = lst.findAll([](const Student & s1) {
        return s1.m_class == 5;
    });
    for(auto i : findIndices)
        std::cout << i << ' ';
    std::cout << std::endl;

    int maxIndex = lst.maxIndex([](const Student & s1, const Student & s2) {
        return s1.m_name > s2.m_name;
    });
    std::cout << "maxIndex: " << maxIndex << std::endl;

    int minIndex = lst.minIndex([](const Student & s1, const Student & s2) {
        return s1.m_name < s2.m_name;
    });
    std::cout << "minIndex: " << minIndex << std::endl;

    SequentialList<int, 10> lst2;
    lst2.insertSorted(0, intComparator);
    printAll(lst2);
    lst2.insertSorted(1, intComparator);
    printAll(lst2);
    lst2.insertSorted(3, intComparator);
    printAll(lst2);
    lst2.insertSorted(4, intComparator);
    printAll(lst2);
    lst2.insertSorted(2, intComparator);
    printAll(lst2);

    return 0;
}
