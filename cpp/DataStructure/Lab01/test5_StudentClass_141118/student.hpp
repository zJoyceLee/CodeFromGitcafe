//学号、姓名、性别、年龄、班级
class StudentInfo
{
public:
    std::string ID;
    std::string name;
    std::string sex;//M;W
    int age;
    int Class;
    StudentInfo* next;
    StudentInfo* prior;
};

//Add student's information ,if prior == NULL,newinfo = header
StudentInfo* AddInfo(StudentInfo* prior,StudentInfo* newinfo);
//Delete
bool DelStudentInfo(char* code,StudentInfo*& pHead);
//Find
StudentInfo* FindStudentInfoByCode(char* code,StudentInfo* pHead);
//Modify
void ModifyStudentInfo(StudentInfo* p);
//Print
void PrintStudentInfo(StudentInfo* pHead);
//Input
void InputInfo(StudentInfo* pInfo);
//Get the last node
StudentInfo* GetLastStudentInfo(StudentInfo* pHead);
//Save the linked list in file
void SaveStudentInfoToFile(char* filename,StudentInfo* pHead);
//Load from file
void LoadStudentInfoFromFile(char* filename,StudentInfo*& pHead);
//Operate prompt
void ShowOperateInfo(void);
