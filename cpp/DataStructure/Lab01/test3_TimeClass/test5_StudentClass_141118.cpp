/*设计一个简单的学生信息管理程序,信息包括:学号、姓名、性别、年龄、班级等。
基本功能包括:可以将信息存入文件或从文件中读出,可以添加、删除、修改学生信息,可
以根据学号、姓名从文件中查找学生信息。*/
//STL
#include <iostream>
#include <string>

class Node{
    int m_idnum;
    std::string m_name;
    std::string m_sex;
    int m_age;
    int m_class;
    char *m_pointer;

};
