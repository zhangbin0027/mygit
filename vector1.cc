#include<algorithm>
#include<iostream>
#include<assert.h>

using namespace std;

template<typename T>
class Vector
{
private:
	#define LENGTH 64;//Vector每次增加64的长度
public:
	//默认构造函数
	Vector():array(0),theSize(0),theCapacity(0)
	{
		
	}
	Vector(const T& t,unsigned int n):array(0),theSize(0),theCapacity()
	{
		while(n--)
		{
			push_back(t);
		}
	}
	//复制构造函数
	Vector(const Vector<T> & other):array(0),theSize(0),theCapacity(0)
	{
		*this=other;
	}
	//运算符重载
	Vector<T>& operator =(Vector<T>& other)
	{
		if(this==&other)
		return *this;
		clear();
		theSize=other.size();
		theCapacity=other.capacity();
		array =new T[theCapacity];
		for(unsigned int i=0;i<theSize;++i)
		{
			array[i]=other[i];
		}
		return *this;
	}
	//销毁	

	~Vector()
	{
		clear();
	}
	//pos必须小于Vector的长度
	T& operator[](unsigned int pos){  
        assert(pos<theSize);  
        return array[pos];  
    }  
 
    
    unsigned int size(){  
        return theSize;  
    }  
 
 
    unsigned int capacity(){  
        return theCapacity;  
    }  
 
     
    bool empty(){  
        return theSize == 0;  
    }  
 
    void clear(){  
        deallocator(array);  
        array = 0;  
        theSize = 0;  
        theCapacity = 0;  
    }  
 
    void push_back(const T& t){  
        insert_after(theSize-1,t);  
    }  
 
   
    void push_front(const T& t){  
        insert_before(0,t);  
    }  
 
    
    void insert_after(int pos,const T& t){  
        insert_before(pos+1,t);  
    }  
 
  
    void insert_before(int pos,const T& t){  
        if(theSize==theCapacity){  
            T* oldArray = array;  
            theCapacity += LENGTH;  
            array = allocator(theCapacity);  
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
 
void printfVector(Vector<int>& vector1){  
    for(unsigned int i = 0 ; i < vector1.size();++i){  
        cout<<vector1[i]<<",";  
    }  
    cout<<"alloc size = "<<vector1.capacity()<<",size = "<<vector1.size()<<endl;  
}  
 
int main(){  
    Vector<int> Vector1;  
    Vector<int> Vector2(0,10);  
    Vector2.push_front(1);  
    Vector2.erase(11);  
    printfVector(Vector2);  
    Vector1.push_back(2);  
    Vector1.push_front(1);  
    printfVector(Vector1);  
    Vector1.insert_after(1,3);  
    printfVector(Vector1);  
 
    Vector2 = Vector1;  
    Vector2.insert_before(0,0);  
    Vector2.insert_before(1,-1);  
    printfVector(Vector2);  
    return 0;  
} 
