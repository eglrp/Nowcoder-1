#include<cstdio>
using namespace std;
//原理, 利用偶次异或操作=0的特点即可
int main()
{
    int n,res=0,temp;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&temp);
        res = res^temp;
    }
    printf("%d",res);
    return 0;
}