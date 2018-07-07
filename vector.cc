<<<<<<< HEAD
#include<algorithm> 
#include<iostream> 
#include <assert.h> 
using namespace std;  
template<typename T> 
class myVector  
{  
private:  
    /*walk length*/  
    /*myVector each time increase space length*/  
    #define WALK_LENGTH 64;  
 
public:  
    /*default constructor*/  
    myVector():array(0),theSize(0),theCapacity(0){  }  
    myVector(const T& t,unsigned int n):array(0),theSize(0),theCapacity(0){  
        while(n--){  
            push_back(t);  
        }  
    }  
 
    /*copy constructor*/  
    myVector(const myVector<T>& other):array(0),theSize(0),theCapacity(0){  
        *this = other;  
    }  
 
    /*= operator*/  
    myVector<T>& operator =(myVector<T>& other){  
        if(this == &other)  
            return *this;  
        clear();  
        theSize = other.size();  
        theCapacity = other.capacity();  
        array = new T[theCapacity];  
        for(unsigned int i = 0 ;i<theSize;++i)  
        {  
            array[i] = other[i];  
        }  
        return *this;  
    }  
 
    /*destructor*/  
    ~myVector(){  
        clear();  
    }  
 
    /*the pos must be less than myVector.size();*/  
    T& operator[](unsigned int pos){  
        assert(pos<theSize);  
        return array[pos];  
    }  
 
    /*element theSize*/  
    unsigned int size(){  
        return theSize;  
    }  
 
    /*alloc theSize*/  
    unsigned int capacity(){  
        return theCapacity;  
    }  
 
    /*is  empty*/  
    bool empty(){  
        return theSize == 0;  
    }  
 
    /*clear myVector*/  
    void clear(){  
        deallocator(array);  
        array = 0;  
        theSize = 0;  
        theCapacity = 0;  
    }  
 
    /*adds an element in the back of myVector*/  
    void push_back(const T& t){  
        insert_after(theSize-1,t);  
    }  
 
    /*adds an element int the front of myVector*/  
    void push_front(const T& t){  
        insert_before(0,t);  
    }  
 
    /*inserts an element after the pos*/  
    /*the pos must be in [0,theSize);*/  
    void insert_after(int pos,const T& t){  
        insert_before(pos+1,t);  
    }  
 
    /*inserts an element before the pos*/  
    /*the pos must be less than the myVector.size()*/  
    void insert_before(int pos,const T& t){  
        if(theSize==theCapacity){  
            T* oldArray = array;  
            theCapacity += WALK_LENGTH;  
            array = allocator(theCapacity);  
            /*memcpy(array,oldArray,theSize*sizeof(T)):*/  
            for(unsigned int i = 0 ;i<theSize;++i){  
                array[i] = oldArray[i];  
            }  
            deallocator(oldArray);  
        }  
 
        for(int i = (int)theSize++;i>pos;--i){  
            array[i] = array[i-1];  
        }  
        array[pos] = t;  
    }  
 
    /*erases an element in the pos;*/  
    /*pos must be in [0,theSize);*/  
    void erase(unsigned int pos){  
        if(pos<theSize){  
            --theSize;  
            for(unsigned int i = pos;i<theSize;++i){  
                array[i] = array[i+1];  
            }  
        }  
    }  
 
private:  
    T*  allocator(unsigned int size){  
        return new T[size];  
    }  
 
    void deallocator(T* arr){  
        if(arr)  
            delete[] arr;  
    }  
private:  
    T*                                array;  
    unsigned int    theSize;  
    unsigned int    theCapacity;  
};  
 
void printfVector(myVector<int>& vector1){  
    for(unsigned int i = 0 ; i < vector1.size();++i){  
        cout<<vector1[i]<<",";  
    }  
    cout<<"alloc size = "<<vector1.capacity()<<",size = "<<vector1.size()<<endl;  
}  
 
int main(){  
    myVector<int> myVector1;  
    myVector<int> myVector2(0,10);  
    myVector2.push_front(1);  
    myVector2.erase(11);  
    printfVector(myVector2);  
    myVector1.push_back(2);  
    myVector1.push_front(1);  
    printfVector(myVector1);  
    myVector1.insert_after(1,3);  
    printfVector(myVector1);  
 
    myVector2 = myVector1;  
    myVector2.insert_before(0,0);  
    myVector2.insert_before(1,-1);  
    printfVector(myVector2);  
    return 0;  
} 
=======
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
>>>>>>> f134cf0c8adf6880da330d0c76adbfe13c4d5f82
