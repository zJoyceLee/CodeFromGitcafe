#include <iostream>
#include <cstring>
class COMMU
{
	char *pName; //姓名，数据成员为私有的
	char *pSchool; //单位
	char *pNum; //电话号码
	char Box[10]; //邮编
public:
	void Print(void) //输出数据成员
	{
		std::cout<<"姓名 :"<<pName<<'\t';
		std::cout<<"单位:"<<pSchool<<'\t';
		std::cout<<"电话号码:"<<pNum<<'\t';
		std::cout<<"邮编:"<<Box<<'\n';
	}
	void Init(char *,char *,char *,char *);
	void FreeSpace(void); //释放数据成员占用的空间
	void SetName(char *name)
	{
		if(pName )
			delete [ ] pName; //释放存储空间
		pName = new char[strlen(name)+1]; //申请存储空间
		strcpy(pName,name);
	}
	void SetScool(char *unit) //置学校名称
	{
		if( pSchool )
			delete [] pSchool;
		pSchool = new char[strlen(unit)+1];
		strcpy(pSchool,unit);
	}
	void SetNum(char *num) //置电话号码
	{
		if( pNum )
			delete [ ] pNum;
		pNum = new char[strlen(num)+1];
		strcpy(pNum,num);
	}
	void SetBox(char *mailnum) //置邮编
	{
		strcpy(Box,mailnum);
	}
	char *GetName(void) //取姓名
	{
		return pName;
	}
	char *GetScool(void ) //取学校
	{
		return pSchool;
	}
	char *GetNum(void) //取电话号码
	{
		return pNum;
	}
	char *GetBox(void) //取邮编
	{
		return Box;
	}
};
void COMMU::Init(char *name,char *unit,char *num,char *b)
{ //完成初始化
	pName = new char [strlen(name)+1];
	strcpy(pName,name);
	pSchool = new char [strlen(unit)+1];
	strcpy(pSchool,unit);
	pNum = new char [strlen(num)+1];
	strcpy(pNum,num);
	strcpy(Box,b);
}
void COMMU::FreeSpace()
{
	if(pName) delete [] pName;
	if(pSchool) delete [] pSchool;
	if(pNum) delete [] pNum;
}
int main()
{
	COMMU c1,c2;
	c1.Init("于元","上海大学","021-66138861","200444");
	c2.Init("王海","上海大学","021-66138862","200444");
	c1.Print();
	c2.Print();
	c1.SetName("王国安");
	std::cout<<c1.GetName()<<'\n';
	c1.SetScool("复旦大学");
	std::cout<<c1.GetScool()<<'\n';
	c1.SetNum("021 -66138960");
	std::cout<<c1.GetNum()<<"\n";
	c1.SetBox("200201");
	std::cout<<c1.GetBox()<<"\n";
	c1.Print();
	c1.FreeSpace();
	c2.FreeSpace();
	return 0;
}
