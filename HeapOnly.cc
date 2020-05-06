#include <iostream>
#include<stdlib.h>
#include<string.h>
//只能生成堆对象，不能生成栈对象，将析构函数放入private区域
//将operator new 放入public区域,因为生成栈对象同时需要能够自动调用构造和析构
using std::cout;
using std::endl;

class HeapOnly
{
public:
    HeapOnly(int HWNo)
        :_HWNo(HWNo)
    {
        cout<<"build HeapOnly"<<endl;
    }
    void print()
    {
        cout<<"Homework's No is "<<_HWNo<<endl;
    }
    void destroy()
    {
        this->~HeapOnly();
    }
    static void *operator new(size_t sz);
    static void operator delete(void *p);
private:
    int _HWNo=2;
    ~HeapOnly()
    {
        cout<<"clear HeapOnly"<<endl;
    }
};
void *HeapOnly::operator new(size_t sz)
    
{
    cout<<"void *operator new(size_t)"<<endl;
    return malloc(sz);
}
void HeapOnly::operator delete(void *p)
{
    cout<<"void *operator delete(void *)"<<endl;
    free(p);
    p=nullptr;
}
int main()
{
    HeapOnly *HO=new HeapOnly(2);
    HO->print();
    HO->destroy();
    return 0;
}

