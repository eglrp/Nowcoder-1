#include <cstdio>
#include <vector>
#include<algorithm>
using namespace std;

//虽然不像是常见的动态规划, 但隐含有状态方程.
//当前max不够用了, 则更新max 
int main()
{

    int n;
    scanf("%d",&n);
    vector<int> nums(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }

    int ans = 0; //跳跃次数
    int now_max = 0; //表示能到达的最远距离
    int next_max = 0;
    for(int i=0;i<n;i++)
    {
        if (now_max<i)
        {
            ans++;
            now_max=next_max;
        }
        next_max = max(next_max,i+nums[i]);
    }
    printf("%d",ans);
    return 0;
}
