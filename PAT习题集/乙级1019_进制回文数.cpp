//16以内的数都是回文数,因为16进制时就仅有1位了
//构造两个函数, 一个是进制转化, 一个是判断回文. 挺简单的,建议练手.
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
int trans_base(int n,int base, int (&a)[32])
{
    int len = 0;
    while (n)
    {
        a[len++] = n%base;
        n = n/base;
    }
    return len; //返回长度
}

bool is_palin(int val[32],int len)
{
    int i=0;
    len--;
    int flag = true;
    while (i<len)
    {
        if (val[i++] != val[len--]) 
        {
            flag = false;
            break;
        }
    }
    return flag;    
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int val[32] = {0};
        bool flag = false;
        for(int i =2;i<=16;i++)
        {
            int len = trans_base(n,i,val);
            if(is_palin(val,len)) 
            {
                flag = true;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else  printf("No\n");
    }

    return 0;
}