//信息论里面看过, 天平一次解读log2(3)bit,因为有><=, 从n中有1个噪音的最大熵为log(n)bits.
//因此需要log3(n) bits;
//比如 8=3+5,把5放上去只需两次得到结果, 9=4+5,任意情况也只要两次.
//12 = 6+6, 需额外消耗一次判断在哪个6, 然后再消耗两次从6中找出答案.
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a,b;
    bool flag = false;
    while (scanf("%d%d",&a,&b)==2) //表示得到两个数据. scanf返回值
    {
        if (a*b)//因为b=0时就是常数,常数求导=0,不必输出.
        {
            if(flag)
            {
               printf(" "); //第一次不会输出空格, 第二次就会了 
            }
            else
            {
                flag = true;
            }
            printf("%d %d",a*b,b-1);
        }
    }
    //要特别注意0 0多项式, 因为输出为空串时要输出00, 其他情况不用.
    if(!flag)  printf("0 0"); //如果从未输出,则表示答案为空串.
    return 0;
}