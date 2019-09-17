//这题不错, 考验基本功
#include <cstdio>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
    return !b ? a : gcd(b,a%b); //默认是a>b才行, 其实小于也可以, 只是多计算一次.
}
void change(int a, int b)
{
    if (a*b==0) 
    {
        if (b==0) printf("Inf"); //不存在 
        else printf("0"); //0
        return;
    }
    bool neg = (b*a) >0  ? false: true; //判断总体正负性
    a = abs(a); b = abs(b); 
    int comm = gcd(a,b);
    a = a/comm; b = b/comm; //除去公约数
    if(b==1) printf(neg==false?"%d":"(-%d)",a/b,a%b,b); //表示a/b整除
    else if (a>b) printf(neg==false?"%d %d/%d":"(-%d %d/%d)",a/b,a%b,b);
    else  printf(neg==false?"%d/%d":"(-%d/%d)",a,b); 
}
int main()
{
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    change(a1,b1); printf(" + "); change(a2,b2); printf(" = "); change(a1*b2+a2*b1, b1*b2); printf("\n"); 
    change(a1,b1); printf(" - "); change(a2,b2); printf(" = "); change(a1*b2-a2*b1, b1*b2); printf("\n"); 
    change(a1,b1); printf(" * "); change(a2,b2); printf(" = "); change(a1*a2, b1*b2);  printf("\n"); 
    change(a1,b1); printf(" / "); change(a2,b2); printf(" = "); change(a1*b2,a2*b1);  printf("\n"); 

    return 0;
}