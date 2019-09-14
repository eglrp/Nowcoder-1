#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

//原理, 先从小到大排序. dp[0...aim]=0或1,dp[a[i]]=1,其他为0. 然后遍历即可
//dp[i-a[j]] =min(dp[i-a[j]]) +1 /遍历j即可
//复杂度有两个一开始得快排O(NlogN), 然后是遍历O(N*aim); 

int main()
{

    int n,aim;
    scanf("%d%d",&n,&aim);
    if (aim == 0) {printf("0"); return 0;}

    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end()); 
    vector<int> dp(aim+1);
    for (int i = 0;i<n;i++)
    {
        dp[a[i]]=1; //初始化, 1张, dp的index表示目标.
    }
    for(int i = 0;i <=aim;i++)
    {
        int temp = 1<<31-1; //先设成最大值
        if (dp[i]==1) continue;
        for (int j = 0;j<n;j++)
        {
            if ((i-a[j]>0) && (dp[i-a[j]]!=0)) //不等于0才有加的可能
            {
                temp = min(temp,dp[i-a[j]]);  
            }
        }

        dp[i] = (temp == 1<<31-1)?0:(temp+1);
    }
    if (dp[aim]==0) 
    {
        printf("-1");
    }
    else
    {
        printf("%d",dp[aim]);  
    }
    
    return 0;
}