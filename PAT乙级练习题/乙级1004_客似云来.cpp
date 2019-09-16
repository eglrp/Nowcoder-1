//原理还是斐波那契数组, 重点就是边界条件了
#include <cstdio>
using namespace std;
int main()
{
    int from,to;
    while(scanf("%d%d",&from,&to)!=EOF)
    {

        long long pre = 1;
        long long ans = 1 ;
        long long total = 0;
        int pos = 3; 
        for(int i=1; i<=to && i<3;i++) //数1 1 2 3 5的前两个1是否有参与from to的范围
        {
            if (i>=from) total += 1;
        }
        while (pos<=to) //从正常的3开始计数.直到pos到达to.
        {
            long long temp = ans;
            ans = ans + pre;
            pre = temp;
            if (pos>=from) total += ans;
            pos++;
        }
        printf("%lld\n",total);
    }

    return 0;
}