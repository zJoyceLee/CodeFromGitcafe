//STL
#include <iostream>
#include <string>
#include <fstream>
//C-Standard
#include <cstdio>
#include <cstring>
//Current Project
#include "student.hpp"

//Add student's information ,if prior == NULL,newinfo = header
StudentInfo* AddInfo(StudentInfo* prior,StudentInfo* newinfo)
{
    if (!prior)
    {
        newinfo->next = NULL;
        newinfo->prior = NULL;
    }
    else
    {
        prior->next = newinfo;
        newinfo->prior = prior;
        newinfo->next = NULL;
    }
    //memset(newinfo->ID,0,sizeof(newinfo->ID));
    InputInfo(newinfo);
    return newinfo;
}

//Delete
bool DelStudentInfo(char* code,StudentInfo*& pHead)
{
    StudentInfo* pDel = FindStudentInfoByCode(code,pHead);
    if (pDel == NULL)
        return false;
    else
    {
        if (pDel == pHead)
            pHead = pDel->next;
        else
        {
            pDel->prior->next = pDel->next;
            if (pDel->next != NULL)
                pDel->next->prior = pDel->prior;
        }
        delete pDel;
        pDel = NULL;
        return true;
    }
}

//Find
StudentInfo* FindStudentInfoByCode(char* ID,StudentInfo* pHead)
{
    StudentInfo* p = pHead;
    while (p != NULL)
    {
        if (p->ID == ID)
        {
            return p;
            PrintStudentInfo(p);
        }
        p = p->next;
    }
    return NULL;
}
//Modify
void ModifyStudentInfo(StudentInfo* p)
{
    std::cout << "The information of student:" << std::endl;
    std::cout << "stddentID:" << p->ID << std::endl;
    std::cout << "Name:" << p->name << std::endl;
    std::cout << "Sex:" << p->sex << std::endl;
    std::cout << "Age:" << p->age << std::endl;
    std::cout << "Class:" << p->Class <<std::endl;

    std::cout << "input the modified information:" << std::endl;
    std::cout << "studentID:";
    std::cin >> p->ID;
    std::cout <<std::endl <<"Name:";
    std::cin >> p->name;
    std::cout << std::endl << "Sex:";
    std::cin >> p->sex;
    std::cout << std::endl << "Age:";
    std::cin >> p->age;
    std::cout << std::endl << "Class:";
    std::cin >> p->Class;
    std::cout << std::endl;

}

//Print
void PrintStudentInfo(StudentInfo* pHead)
{
    StudentInfo* p = pHead;
    if(p ==NULL){
        std::cout << "No Information." << std::endl;
    }

    while (p!=NULL)
    {
        std::cout << "The information of student:" << std::endl;
        std::cout << "stddentID:" << p->ID << std::endl;
        std::cout << "Name:" << p->name << std::endl;
        std::cout << "Sex:" << p->sex << std::endl;
        std::cout << "Age:" << p->age << std::endl;
        std::cout << "Class:" << p->Class <<std::endl;
        p = p->next;
    }
}

//Input
void InputInfo(StudentInfo* pInfo)
{
    StudentInfo* p = pInfo;
    std::cout << "studentID:";
    std::cin >> p->ID;
    std::cout <<std::endl <<"Name:";
    std::cin >> p->name;
    std::cout << std::endl << "Sex:";
    std::cin >> p->sex;
    std::cout << std::endl << "Age:";
    std::cin >> p->age;
    std::cout << std::endl << "Class:";
    std::cin >> p->Class;
    std::cout << std::endl;
}
//Get the last node
StudentInfo* GetLastStudentInfo(StudentInfo* pHead)
{
    if (pHead == NULL)
        return NULL;
    StudentInfo* p = pHead;
    while (p)
    {
        if (p->next == NULL)
            return p;
        p = p->next;
    }
}

//save in the file
void SaveStudentInfoToFile(char* filename,StudentInfo* pHead)
{
    std::ofstream ofs;
    //ofs.open("test5_Student.txt",std::ofstream::app);//:/tmp/test5_Student.txt
    StudentInfo* p = pHead;

    ofs.open("test5_Student.txt",std::ofstream::app);
    std::cin >> p->ID;
    ofs << p->ID << std::endl;
    std::cin >> p->name;
    ofs << p->name << std::endl;
    std::cin >> p->sex;
    ofs << p->sex << std::endl;
    std::cin >> p->age;
    ofs << p->age << std::endl;
    std::cin >> p->Class;
    ofs << p->Class << std::endl;
    // ... all that have been wrote
    ofs.close();
}
//Loading from file
void LoadStudentInfoFromFile(char* filename,StudentInfo*& pHead)
{
    std::ifstream ifs;
    ifs.open(filename, std::ofstream::app);
    while (true)
    {
        pHead = new StudentInfo;
        pHead->next = NULL;
        pHead->prior = NULL;
        ifs >> pHead->ID;
        ifs >> pHead->name;
        ifs >> pHead->sex;
        ifs >> pHead->age;
        ifs >> pHead->Class;
        if(ifs.eof())
            break;
        std::cout << pHead->ID << std::endl;
        std::cout << pHead->name << std::endl;
        std::cout << pHead->sex << std::endl;
        std::cout << pHead->age << std::endl;
        std::cout << pHead->Class <<std::endl;
    }
    ifs.close();
}

//Operate prompt
void ShowOperateInfo(void)
{
	std::cout << "1.add" << std::endl;
	std::cout << "2.delete" << std::endl;
    std::cout << "3.find" << std::endl;
    std::cout << "4.modification" << std::endl;
    std::cout << "5.save the information in files" << std::endl;

    std::cout << "6.print" << std::endl;
    std::cout << "0.exit" << std::endl;
}
