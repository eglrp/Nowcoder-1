#include <cstdio>

using namespace std;

void F1(int* a, int* b) //使用指针
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void F2(int &a,int &b)//引用的意思
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=10,b=9;
    F2(a,b);
    printf("%d",a);
    return 0;
}