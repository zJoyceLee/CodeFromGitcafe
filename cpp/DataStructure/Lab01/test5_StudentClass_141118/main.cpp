/*设计一个简单的学生信息管理程序,信息包括:学号、姓名、性别、年龄、班级等。
基本功能包括:可以将信息存入文件或从文件中读出,可以添加、删除、修改学生信息,可
以根据学号、姓名从文件中查找学生信息。*/
//STL
#include <iostream>
//C-Standard
#include <cstdlib>
#include <cstdio>
//Current Project
#include "student.hpp"

int main()
{
	ShowOperateInfo();
	std::cout << std::endl;
	int i;

	//curInfo is lasted node，used to add new node
	StudentInfo* curInfo = new StudentInfo;
	StudentInfo* pHead = NULL;
	LoadStudentInfoFromFile("test5_Student.txt",pHead);
	char ID[10]={0};
	//curInfo point to the last node
	if (pHead != NULL)
		curInfo = GetLastStudentInfo(pHead);
	while (true)
	{
		std::cout << "Please input your operated number:" << std::endl;
		std::cin >> i;
		switch (i)
		{
			//exit
		case 0:
			exit(0);
			//add
		case 1:
			if (pHead == NULL)
			{
				pHead = new StudentInfo;
				curInfo = pHead = AddInfo(NULL,pHead);
			}
			else
			{
				StudentInfo* newInfo = new StudentInfo;
				curInfo = AddInfo(curInfo,newInfo);
			}
			break;
			//delete
		case 2:
			std::cout << "Please input the studentID which you want to delete:" << std::endl;
			std::cin >> ID ;
			DelStudentInfo(ID,pHead);
			curInfo = GetLastStudentInfo(pHead);
			break;
			//find
		case 3:
			std::cout <<"Please input the studentID which you want to find:" << std::endl;
			std::cin >> ID ;
			{
				StudentInfo* p = FindStudentInfoByCode(ID,pHead);
				if (p == NULL)
					std::cout << "the studentID" << ID << "is not existent." << std::endl;
				else
				{
					std::cout << "stddentID:" << p->ID << std::endl;
					std::cout << "Name:" << p->name << std::endl;
					std::cout << "Sex:" << p->sex << std::endl;
					std::cout << "Age:" << p->age << std::endl;
					std::cout << "Class:" << p->Class <<std::endl;
				}
			}
			break;
			//modification
		case 4:
			std::cout << "Please input the studentID which you want to modified:" << std::endl;
			std::cin >> ID ;
			{
				StudentInfo* p = FindStudentInfoByCode(ID,pHead);
				if (p == NULL)
					std::cout << "studentID " << ID << "is inexistent." << std::endl;
				else
				{
					ModifyStudentInfo(p);
				}
			}
			break;
		case 5:
			SaveStudentInfoToFile("test5_Student.txt",pHead);
			break;
			//print
		case 6:
			PrintStudentInfo(pHead);
			break;
		default:
			exit(0);
		}
	}
}
