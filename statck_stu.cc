#include<stdlib.h>
#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
//只能生成栈对象
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
private:
	void * operator new(size_t size);
	void operator delete(void *p);
private:
	int _no;
	char * _name;
};
int main(void)
{
#if 0
	Student * s1=new Student(100,"lili");//不能通过编译
	s1->print();
	delete s1;
#endif
    Student s2(101,"lele");//对于栈对象而言，他需要构造函数和析构函数
	s2.print();
	return 0;
}
