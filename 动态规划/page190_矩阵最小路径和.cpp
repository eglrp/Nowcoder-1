#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > a(n);
    for (int i=0;i<n;i++) 
    {
        a[i].resize(m);
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    //动态规划, O(m) 空间度复杂度更小, 先求出dp行
    vector<int> dp(m); //初始化第一行
    for (int i=0;i<m;i++)
    {
        dp[i] = i==0?a[0][0]:(dp[i-1]+a[0][i]); 
    }

    for (int i = 1; i<n;i++) //从第二行开始
    {
        for( int j=0;j<m;j++)
        {
            dp[j] = j==0?(dp[0]+a[i][j]):(min(dp[j-1],dp[j])+a[i][j]);
        }
    }
    printf("%d",dp[m-1]);

    return 0;
}