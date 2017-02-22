#include<iostream>
#include<vector>//容器之一
using std::cout;
using std::endl;
using std::vector;
//int arr[10];
//string str[10];
void printCapacity(vector<int>&vec)
{
	cout<<"vec's size ="<<vec.size()<<endl;
	cout<<"vec's capacity="<<vec.capacity()<<endl;
}
int main()
{
	//vector是一个动态数组,可以进行动态扩容
	//策略:1. 假设当前容量是x, 先申请2x的容量
	//	   2. 再将原来的数据拷贝到新申请的空间中去,
	//		  并且释放原来的数据所占用的空间
	//	   3. 最后再添加新的数据
	vector<int> vecInt;
	vecInt.reserve(5);//先给定空间，再扩容翻倍
	printCapacity(vecInt);
	cout<<endl;
	vecInt.push_back(1);
	printCapacity(vecInt);
	vecInt.push_back(3);
	printCapacity(vecInt);
	vecInt.push_back(5);
	printCapacity(vecInt);
	vecInt.push_back(6);
	printCapacity(vecInt);
	
	for(size_t idx=0;idx!=vecInt.size();++idx)//获取字符串的长度
	{
		cout<<vecInt[idx]<<"";
	}
	cout<<endl;
	vector<int>::iterator it;//广义的指针，迭代器法
	for(it=vecInt.begin();it!=vecInt.end();++it)
	{
		cout<<*it<<"";
	}
	cout<<endl;
	//c++11
	for(auto & elem : vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}
