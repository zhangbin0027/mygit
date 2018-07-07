 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 16:24:32
 ///
 

#include <iostream>
#include <functional>
using std::cout;
using std::endl;
int func(int x, int y)
{
	return x + y;
}

class A
{
public:
	int func(int x, int y)
	{
		return x + y;
	}

	int data = 10;
};


void f(int n1, int n2, int n3, const int & n4, int n5)
{
	cout << "(" << n1
		 << "," << n2
		 << "," << n3
		 << "," << n4
		 << "," << n5
		 << ")" << endl;
}

int main(void)
{
	using namespace std::placeholders;//占位符
	auto f1 = std::bind(func, 10, 20);
	cout << f1() << endl;

	//std::bind1st(func, 10);
	auto f2 = std::bind(func, 10, _1);
	cout << f2(20) << endl;

	A a;
	//bind函数模板是能够改变函数标签
	auto f3 = std::bind(&A::func, &a, _1, _2);
	cout << f3(10, 20) << endl;

	int n = 7;
	//1. bind传递参数时采用的是值传递
	//2. 占位符本身所在的位置是形参所在的位置
	//3. 占位符本身的数字代表的是实参传递时的位置 	
	auto f4 = std::bind(f, _3, _5, 42, std::cref(n), n);
	n = 10;

	f4(1, 2, 1001, 1004, 100, 101, 10,19, 20);

	auto f5 = std::bind(&A::data, &a);
	cout << f5() << endl;
	

	return 0;
}

