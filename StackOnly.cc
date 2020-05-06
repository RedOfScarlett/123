#include <iostream>
#include<stdlib.h>
#include<string.h>
//只能生成栈对象，不能生成堆对象，将operator new放入private区域
//这样在类外调用new就无效了
using std::cout;
using std::endl;

class StackOnly
{
public:
    StackOnly(int HWNo)
        :_HWNo(HWNo)
    {
        cout<<"build StackOnly"<<endl;
    }
    ~StackOnly()
    {
        cout<<"clear StackOnly"<<endl;
    }
    void print()
    {
        cout<<"Homework's No is "<<_HWNo<<endl;
    }
private:
    static void *operator new(size_t sz);
    static void operator delete(void *p);
    int _HWNo=1;
};
void *StackOnly::operator new(size_t sz)//其实没必要实现，因为我们不希望去调用
    //operator new来在堆空间上创建对象
{
    cout<<"void *operator new(size_t)"<<endl;
    return malloc(sz);
}
void StackOnly::operator delete(void *p)
{
    cout<<"void *operator delete(void *)"<<endl;
    free(p);
    p=nullptr;
}
int main()
{
    StackOnly SO(1);
    SO.print();
    return 0;
}

