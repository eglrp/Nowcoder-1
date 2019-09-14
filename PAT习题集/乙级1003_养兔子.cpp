//就是普通的斐波那契数组. 非递归模式, 很方便.
#include <cstdio>
using namespace std;
int main()
{
    int n;

    while(scanf("%d",&n)!=EOF)
    {
        if(n<3)
        {
            printf("%d\n",n);
            continue;
        }
        long long pre = 1;
        long long ans = 2; 
        n -=2;
        while (n--)
        {
            long long temp = ans;
            ans = ans + pre;
            pre = temp;
        }
        printf("%lld\n",ans);
    }

    return 0;
}