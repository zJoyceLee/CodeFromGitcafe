//STL
#include <iostream>
//Current Project
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Student.hpp"

void printInt(const int & i) {
    std::cout << i << ',';
}

void printStudent(const Student & s) {
    std::cout << "StudentNum: " << s.m_studentNum <<std::endl;
    std::cout << "Name: " << s.m_name << std::endl;
    std::cout << "Gender: " << s.m_gender << std::endl;
    std::cout << "Age: " << s.m_age << std::endl;
    std::cout << "TelNum: " << s.m_telNum << std::endl;
    std::cout << "----------------------------" << std::endl;
}

bool comparatorLessStudent(const Student & lhs, const Student & rhs) {
    return lhs.m_telNum < rhs.m_telNum;
}

int main()
{
    std::vector<int> v {1, 2, 3, 4, 5};
    LinkedList<int> lstInt(v);
    lstInt.traverse(printInt);
    std::cout << std::endl;
    lstInt.reversal();
    lstInt.traverse(printInt);
    std::cout << std::endl;

    std::cout << std::endl << "Student Test:" << std::endl << std::endl;

    LinkedList<Student> lst;

    Student s1 {"13122550", "Li Yuzhe", "female", 19, "18717897080"};
    Student s2 {"11122057", "Yang Yang", "male", 22, "13761283909"};
    Student s3 {"13122222", "Joyce Lee", "female", 20, "18721007080"};
    Student s4 {"12122325", "Mary Chen", "female", 20, "13353190088"};

    lst.insertSorted(s1, comparatorLessStudent);
    lst.insertSorted(s2, comparatorLessStudent);
    lst.insertSorted(s3, comparatorLessStudent);
    lst.insertSorted(s4, comparatorLessStudent);
    lst.reversal();
    lst.traverse(printStudent);
    std::cout << std::endl;

    return 0;
}
