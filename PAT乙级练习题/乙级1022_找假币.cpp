//信息论里面看过, 天平一次解读log2(3)bit,因为有><=, 从n中有1个噪音的最大熵为log(n)bits.
//因此需要log3(n) bits;
//比如 8=3+5,把5放上去只需两次得到结果, 9=4+5,任意情况也只要两次.
//12 = 6+6, 需额外消耗一次判断在哪个6, 然后再消耗两次从6中找出答案.
#include <cstdio>
#include <cmath> //难点还有log的转换, cpp没有log2,仅有loge
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d",&n)&&n) //先执行前面一句
    {
        cout << ceil(log(n)/log(3)) <<endl;
    }
    return 0;
}