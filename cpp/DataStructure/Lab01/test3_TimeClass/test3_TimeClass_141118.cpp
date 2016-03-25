/*定义一个时间类 Time，能提供和设置由时、分、秒组成的时间，
并编出应用程序，定义时间对象，设置时间，输出该对象提供的时间。*/

//STL
#include <iostream>
#include <iomanip>

class Time {
private:
	int m_hour;
	int m_minute;
	int m_second;

public:
	//set
	void set(int h,int m,int s);
	//output
	void print();
};

void Time::set(int h,int m,int s) {
	m_hour=h;
	m_minute=m;
	m_second=s;
}

void Time::print() {
	std::cout << m_hour << "h " << m_minute << "m " << m_second << "s " << std::endl;
}

int main()
{
	Time t;
	int H,M,S;
	std::cin >> H >> M >> S;//input time setting
	t.set(H,M,S);//test data
	t.print();

	return 0;
}
