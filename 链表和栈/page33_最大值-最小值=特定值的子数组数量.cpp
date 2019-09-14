//这题比较难, 得先做完滑动窗口最大值的问题, 用到双端序列.
//qmin双端序列的原理,当前点一定是最小值,遍历过的点[i...j]最小值
//前头pop有两种情况--过期,或是后者来了一个更小的.
//尾部更新机制--强候选人淘汰弱候选人,弱候选人不会主动淘汰
#include <deque>
#include <cstdio>
#include <vector>
using namespace std;
// 答案的计算也挺巧妙, 假设a[i,..j]不满足条件,则任意包含a[i,...j]的序列也不满足
// 假设a[i,..j]不满足条件,则任意a[i,...j]内的序列也满足
//因此计算就是等差序列, n,n-1,n-2,,,.但由于下次i还会动,因此先算i-j,i-(j-1),i-(j-2)的以i为开头的子串.
//ij的更新规则是i每次都i++, j则是有机会就++;
int main()
{
    int n, k, ans = 0;
    scanf("%d%d",&n,&k);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    deque<int> qmin, qmax;
    int start = 0, end = 0;

    while (start < n) //start每次必然++
    {
        while (end < n) //end则是尽可能尝试++; 因为end的目标就是越远越好.
        {
            while (!qmin.empty() && a[qmin.back()] >= a[end]) //表示新入元素太强,要淘汰弱候选项
            {
                qmin.pop_back();
            }
            qmin.push_back(end); //存的是index,这样才能判断是否过期

            while ((!qmax.empty() && a[qmax.back()] <= a[end])) //这个等号很重要,因为j有可能没改变,会导致重复输入
            {
                qmax.pop_back();
            }
            qmax.push_back(end);

            if (a[qmax.front()] - a[qmin.front()] > k)
                break; //现在是判断end能否更近一步
            end++;     //表示可以更远一步
        }
        if (qmax.front() == start) //表示该丢了
            qmax.pop_front();
        if (qmin.front() == start) //表示该丢了
            qmin.pop_front();
        ans += end - start; //end是错误点, 因此是end-start
        start++;
    }
    printf("%d", ans);
    return 0;
}
