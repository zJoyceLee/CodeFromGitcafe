#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <vector>
#include <stdexcept>
#include <algorithm>

#define N 100
using namespace std;
string p;
void menu();

class person
{
public:
    string num,name,sex,native;
	string age;
	string address,tel;
	person(){}
	void show();
	friend ostream &operator << (ostream & out, const person &t)
	{}
	friend istream &operator >> (istream & in, const person &t)
	{
//		in >> t.num >> t.name >> t.sex >> t.native >> t.age >> t.address >> t.tel;
		return in;
	}
	~person(){}
};
class PersonList:public person
{
private:
	person p[N];
	int NUM;
    int count;
public:
	void readFile();
	void add();
    void modify();
    void dele();
	void search();
	void save();
	PersonList(){
		NUM=0;
		count=0;
		//size_t getCount() { return count; };
	}
	void showperson();
};


void printVec(const vector<person> & myvec) {
    for(size_t i = 0; i < myvec.size(); ++i) {
        cout << myvec[i].num << ". " << myvec[i].name << ". " <<  myvec[i].sex << ". " <<
                myvec[i].native << ". " << myvec[i].age << ". " << myvec[i].address << ". "
                                << myvec[i].tel << endl;
    }
}

void menu()
{
	cout<<endl;
	cout<<"***********************************************"<<endl;
	cout<<"**        外来人员身份信息查询系统主菜单                  **"<<endl;
	cout<<"**  1.人员信息批量输入       2.单个人员信息添加           **"<<endl;
	cout<<"**  3.单个人员信息删除       4.根据证号修改信息           **"<<endl;
	cout<<"**  5.外来人员信息查询       6.外来人员信息保存           **"<<endl;
	cout<<"**  0.退出                                                **"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<endl;
}

void domain()
{

	PersonList pl;
	while(1)
	{
menu();
	cout<<"请选择数字编号~6"<<endl;
	int i1;
	cin>>i1;
	while(!(i1>=0&&i1<=6))
	{
		cout<<"输入有误，请重新输入："<<endl;
		cin>>i1;
	}
	switch(i1)
	{
	case 1:
		pl.readFile();break;
	case 2:
		pl.add();break;
	case 3:
		pl.dele();break;
	case 4:
		pl.modify();break;
	case 5:
		pl.search();break;
	case 6:
		pl.save();break;
	case 0:
		cout<<"系统退出！！"<<endl;
		exit(0);
	default:
		break;
	}
	cout<<"是否返回主菜单?  Y/N"<<endl;
	cin>>p;

		if(p=="n"||p=="N")
		{	cout<<"系统退出！！"<<endl;
			exit(0);
		}
	}
}

vector<person> readAllInLines(const string & path) {
    vector<string> ret;
    vector<person> myvec;

    // open file to read
    ifstream ifs(path);
    if(!ifs)
        throw runtime_error("cannot open file: " + path);

    string line;
    while(true) {
        getline(ifs, line);
        if(!ifs)
            break;
        size_t pos = line.find("\r");
        if(pos != string::npos)
            line = line.erase(pos);
        ret.push_back(line);
    }
    person myPerson;
    //return ret;
    for(size_t i = 0; i < ret.size() / 7; ++i) {
        myPerson.num = ret[i * 7 + 0];
        myPerson.name = ret[i * 7 + 1];
        myPerson.sex = ret[i * 7 + 2];
        myPerson.native = ret[i * 7 + 3];
        myPerson.age = ret[i * 7 + 4];
        myPerson.address = ret[i * 7 + 5];
        myPerson.tel = ret[i * 7 + 6];
        myvec.push_back(myPerson);
    }
//	string str;
//	for(size_t i =0; i < ret.size(); ++i) {
//		str += ret[i];
//	}
	return myvec;
}

void PersonList::readFile() {
    fstream out;
    out.open("people.txt",ios::in);
    cout<<"people.txt"<<" 的内容如下:"<<endl;
	vector<person> pFile = readAllInLines("people.txt");
    for(size_t i = 0; i < pFile.size(); ++i) {
        p[count + i] = pFile[i];
    }
    count += int(pFile.size());
    printVec(pFile);
}

void PersonList::add()
{
	cout<<"请输入人员信息:"<<endl;
    cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
	string num;
	cin>>num;
	for(int i=0;i<NUM;i++)
	while(num==p[i].num)
	{
		cout<<"此人员身份证号已存在，请重新输入："<<endl;
		cin>>num;
	}
    p[NUM].num=num;
	cin>>p[NUM].name>>p[NUM].sex>>p[NUM].native>>p[NUM].age>>p[NUM].address>>p[NUM].tel;
	++NUM;
	count=NUM;
for(int k=0;k<N;k++)
	{
	  cout<<"是否继续输入？Y/N"<<endl ;
		char c;
      cin>>c;
       if(c=='n'||c=='N')
		{
		    break;
		}
     else if(c=='y'||c=='Y')
	 {
		string num;
      	cin>>num;
	    for(int i=0;i<NUM;i++)
	    while(num==p[i].num)
		{
		cout<<"此人员身份证号已存在，请重新输入："<<endl;
		cin>>num;
		}
	   p[NUM].num=num;
	   cin>>p[NUM].name>>p[NUM].sex>>p[NUM].native>>p[NUM].age>>p[NUM].address>>p[NUM].tel;
	   ++NUM;
	   count=NUM;
	 }
        else
		{
			cout<<"输入有误，请重新输入：";
			cin>>p[NUM];
		}
	}

}
void PersonList::modify()
{
	if(NUM<=0)
	{
		cout<<"没有人员信息存入，系统将返回主菜单"<<endl;
		menu();
	}
	else
	{	cout<<"人员信息如下："<<endl;
		cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
		for(int i=0;i<count;i++)
	cout<<p[i].num<<'\t'<<p[i].name<<'\t'<<p[i].sex<<'\t'<<p[i].native<<'\t'<<p[i].age<<'\t'<<p[i].address<<'\t'<<p[i].tel<<endl;
	}
	cout<<"请输入需要修改信息人员的身份证号："<<endl;
	string num1;
	cin>>num1;
	int j=0,k;
	int flag=1;
	while(flag)
	{
		for(;j<count;j++)
		{
			if(num1==p[j].num)
			{
				flag=0;
				k=j;
				break;
			}
		}
		if(flag)
		{
			cout<<"不存在此人员，请重新输入："<<endl;
			j=0;
			cin>>num1;
		}
	}
	cout<<"你选择的人员的信息为："<<endl;
	cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
	cout<<p[k].num<<'\t'<<p[k].name<<'\t'<<p[k].sex<<'\t'<<p[k].native<<'\t'<<p[k].age<<'\t'<<p[k].address<<'\t'<<p[k].tel<<endl;
	cout<<endl;
	cout<<"**********************************"<<endl;
	cout<<"**  1.修改姓名           2.修改性别          **"<<endl;
	cout<<"**  3.修改籍贯           4.修改年龄          **"<<endl;
	cout<<"**  5.修改地址           6.修改电话          **"<<endl;
	cout<<"**                0.返回主菜单                      **"<<endl;
	cout<<"***********************************"<<endl;
	cout<<endl;
	cout<<"请选择数字编号~6"<<endl;
	int i2;
	cin>>i2;
	while(i2<0||i2>6)
	{
		cout<<"输入有误，请重新输入："<<endl;
		cin>>i2;
	}
	switch(i2)
	{
	case 1:
		cout<<"请输入新的姓名:";
			cin>>p[k].name;
			cout<<"修改信息已保存"<<endl;

		break;
	case 2:
		cout<<"请输入新的性别:";
			cin>>p[k].sex;
			cout<<"修改信息已保存"<<endl;

		break;
	case 3:
		cout<<"请输入新的籍贯:";
			cin>>p[k].native;
			cout<<"修改信息已保存"<<endl;

		break;
	case 4:
		cout<<"请输入新的年龄:";
			cin>>p[k].age;
			cout<<"修改信息已保存"<<endl;

		break;
	case 5:
		cout<<"请输入新的地址:";
			cin>>p[k].address;
			cout<<"修改信息已保存"<<endl;

		break;
	case 6:
		cout<<"请输入新的电话:";
     		cin>>p[k].tel;
			cout<<"修改信息已保存"<<endl;

		break;
	case 0:
		menu();
	default:
		break;
	}
}
void PersonList::dele()
{
	if(NUM<=0)
	{
		cout<<"没有人员信息存入，系统将返回主菜单"<<endl;
		menu();
	}
	else
		cout<<"人员信息如下："<<endl;
		cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
		for(int i=0;i<count;i++)
			cout<<p[i].num<<'\t'<<p[i].name<<'\t'<<p[i].sex<<'\t'<<p[i].native<<'\t'<<p[i].age<<'\t'<<p[i].address<<'\t'<<p[i].tel<<endl;
		cout<<"请输入需要删除信息人员的身份证号："<<endl;
	string num3;
	cin>>num3;
	int j=0,k;
	int flag=1;
	while(flag)
	{
		for(;j<count;j++)
		{
			if(num3==p[j].num)
			{
				flag=0;
				k=j;
				break;
			}
		}
		if(flag)
		{
			cout<<"不存在此人员，请重新输入："<<endl;
			j=0;
			cin>>num3;
		}
	}
	cout<<"你选择的人员的信息为："<<endl;
	cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
	cout<<p[k].num<<'\t'<<p[k].name<<'\t'<<p[k].sex<<'\t'<<p[k].native<<'\t'<<p[k].age<<'\t'<<p[k].address<<'\t'<<p[k].tel<<endl;
	cout<<"确认请输入Y\t返回主菜单请输入N "<<endl;
	string pp;
	cin>>pp;
	while(1)
	{
		if(pp=="y"||pp=="Y")
		{
			cout<<"人员信息已删除！"<<endl;
			for(int i=0;i<count;i++)
				if(p[i].num==num3)
					int j=i;
				for(;j<=count-1;j++)
				p[j].num=p[j+1].num;
					count--;
			break;

		}
		else if(pp=="n"||pp=="N")
		{
			menu();
		}
		else
		{
			cout<<"输入有误，请重新输入：";
			//cin>>p;
		}
	}
}

void PersonList::search()
{
	if(NUM<=0)
	{
		cout<<"没有人员信息存入，系统将返回主菜单"<<endl;
		menu();
	}
	else
		cout<<"请选择查询方式："<<endl;
	cout<<"***********************************************"<<endl;
	cout<<"**            1.按身份证号查询              **"<<endl;
	cout<<"**            2.按姓名查询                  **"<<endl;
	cout<<"**            3.按性别查询                  **"<<endl;
	cout<<"**            4.按年龄查询                  **"<<endl;
	cout<<"**            5.按手机号查询                **"<<endl;
	cout<<"**            6.按地址查询                  **"<<endl;
	cout<<"**            7.按籍贯查询                  **"<<endl;
	cout<<"**            0.返回主菜单                  **"<<endl;
	cout<<"***********************************************"<<endl;
	cout<<endl;
	cout<<"请选择数字编号~7"<<endl;
	int i3;
	cin>>i3;
	while(i3<0||i3>7)
	{
		cout<<"输入有误，请重新输入："<<endl;
		cin>>i3;
	}
	if(i3==1)
	{
		string num2;
		cout<<"请输入要查询的人员的身份证号："<<endl;
		cin>>num2;
		int j=0,k;
		for(;j<count;j++)
		{
		if(num2==p[j].num)
		   {
		k=j;
cout<<"查询的人员信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k].num<<'\t'<<p[k].name<<'\t'<<p[k].sex<<'\t'<<p[k].native<<'\t'<<p[k].age<<'\t'<<p[k].address<<'\t'<<p[k].tel<<endl;
			break;
			}
	    }
	    //cout<<"不存在此人员!!\n返回主菜单"<<endl;
	}
	else if(i3==2)
	{
		string name2;
		cout<<"请输入要查询的人员的姓名："<<endl;
		cin>>name2;
		int j2=0,k2;
		for(;j2<count;j2++)
		{
			if(name2==p[j2].name)
			{
			k2=j2;
cout<<"查询的人员信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k2].num<<'\t'<<p[k2].name<<'\t'<<p[k2].sex<<'\t'<<p[k2].native<<'\t'<<p[k2].age<<'\t'<<p[k2].address<<'\t'<<p[k2].tel<<endl;
			break;
				}
			}
			//cout<<"不存在此人员!!\n返回主菜单"<<endl;
	}
	else if(i3==3)
    {
		string sex2;
        cout<<"请输入要查询的人员的性别："<<endl;
        cin>>sex2;
        int j3=0,k3;
		for(;j3<count;j3++)
	    {
			if(sex2==p[j3].sex)
		    {
		    k3=j3;
cout<<"查询的人员信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k3].num<<'\t'<<p[k3].name<<'\t'<<p[k3].sex<<'\t'<<p[k3].native<<'\t'<<p[k3].age<<'\t'<<p[k3].address<<'\t'<<p[k3].tel<<endl;
		    break;
				}
	        }
	        //cout<<"不存在此人员!!\n返回主菜单"<<endl;

    }
	else if(i3==4)
	{
		string age2;
        cout<<"请输入要查询的人员的年龄："<<endl;
        cin>>age2;
        int j4=0,k4;
        for(;j4<count;j4++)
	    {
			if(age2==p[j4].age)
	        {
		    k4=j4;
cout<<"查询的人员的信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k4].num<<'\t'<<p[k4].name<<'\t'<<p[k4].sex<<'\t'<<p[k4].native<<'\t'<<p[k4].age<<'\t'<<p[k4].address<<'\t'<<p[k4].tel<<endl;
            break;
				}
	        }
	        //cout<<"不存在此人员!!\n返回主菜单"<<endl;
	}
    else if(i3==5)
    {
			string tel2;
            cout<<"请输入要查询的人员的手机号："<<endl;
            cin>>tel2;
            int j5=0,k5;
            for(;j5<count;j5++) {
				if(tel2==p[j5].tel) {
                    k5=j5;
                    cout<<"查询的人员的信息如下："<<endl;
                    cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
                    cout<<p[k5].num<<'\t'<<p[k5].name<<'\t'<<p[k5].sex<<'\t'<<p[k5].native<<'\t'<<p[k5].age<<'\t'<<p[k5].address<<'\t'<<p[k5].tel<<endl;
                    break;
				}
	        }
	        //cout<<"不存在此人员!!\n返回主菜单"<<endl;
    }
    else if(i3==6)
    {
            string address2;
            cout<<"请输入要查询的人员的地址："<<endl;
            cin>>address2;
            int j6=0,k6;
            for(;j6<count;j6++)
		    {
				if(address2==p[j6].address)
	            {
				k6=j6;
cout<<"查询的人员的信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k6].num<<'\t'<<p[k6].name<<'\t'<<p[k6].sex<<'\t'<<p[k6].native<<'\t'<<p[k6].age<<'\t'<<p[k6].address<<'\t'<<p[k6].tel<<endl;
			break;
	        }
	    }
	    //cout<<"不存在此人员!!\n返回主菜单"<<endl;
    }
    else if(i3==7)
    {
			string native2;
            cout<<"请输入要查询的人员的籍贯："<<endl;
            cin>>native2;
            int j7=0,k7;
            for(;j7<count;j7++)
	        {
				if(native2==p[j7].native)
	            {
				k7=j7;
cout<<"查询的人员的信息如下："<<endl;
cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
cout<<p[k7].num<<'\t'<<p[k7].name<<'\t'<<p[k7].sex<<'\t'<<p[k7].native<<'\t'<<p[k7].age<<'\t'<<p[k7].address<<'\t'<<p[k7].tel<<endl;
            break;
			}
	    }
	    //cout<<"不存在此人员!!\n返回主菜单"<<endl;
    }
    else if(i3==0)
	menu();
}

void PersonList::showperson()
{
	if(NUM<=0)
	{
		cout<<"没有人员信息存入，系统将返回主菜单"<<endl;
		menu();
	}
	else
		cout<<"已保存的人员信息如下："<<endl;
	cout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
	for(int i=0;i<count;i++)
		cout<<p[i].num<<'\t'<<p[i].name<<'\t'<<p[i].sex<<'\t'<<p[i].native<<'\t'<<p[i].age<<'\t'<<p[i].address<<'\t'<<p[i].tel<<endl;

}

void PersonList::save()
{
	if(NUM<=0)
	{
		cout<<"没有人员信息存入，系统将返回主菜单"<<endl;
		menu();
	}
	else
	{
		ofstream fout;
		fout.open("person.txt",ios::out);
		cout<<"文件正在保存......请稍候！！"<<endl;
		cout<<"数据保存成功！！！"<<endl;
		fout<<"已保存员工信息如下："<<endl;
		fout<<"身份证号\t姓名\t性别\t籍贯\t年龄\t地址\t电话"<<endl;
		for(int i=0;i<count;i++)
fout<<p[i].num<<'\t'<<p[i].name<<'\t'<<p[i].sex<<'\t'<<p[i].native<<'\t'<<p[i].age<<'\t'<<p[i].address<<'\t'<<p[i].tel<<endl;
		cout<<"系统返回主菜单："<<endl;
		menu();
		fout.close();
	}
}
int main()
{
	domain();
	return 0;
}
