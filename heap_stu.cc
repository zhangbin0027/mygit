#include<stdlib.h>
#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
//只能生成堆对象
class Student
{
public:
	Student(int no,const char * name)
	: _no(no)
	, _name(new char[strlen(name)+1])
	{
		strcpy(_name,name);
	}
	void print()
	{
		cout<<"学号:"<<_no<<endl;
		cout<<"姓名:"<<_name<<endl;
	}
	void destroy()
	{
		delete this;
	}
private:
	~Student()
	{
		cout<<"~student()"<<endl;
		delete [] _name;
	}
private:
	int _no;
	char * _name;
};
int main(void)
{

	Student * s1=new Student(100,"lili");
	s1->print();
//	delete s1;//对于堆对象而言，执行delete表达式无法通过编译
	s1->destroy();//在public区域定义一个destroy()
//  Student s2(101,"lele");//不能通过编译
	return 0;
}
