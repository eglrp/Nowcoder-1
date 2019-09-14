#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > dp(n);
    for (int i=0;i<n;i++)
    {
        dp[i].resize(m);
        for (int j=0;j<m;j++)
        {
            scanf("%d",&dp[i][j]); 
        }
    }

    //从终点开始往后遍历. 为了节省空间,直接用dp来操作
    dp[n-1][m-1] = (dp[n-1][m-1]>0)?1:(-dp[n-1][m-1]+1); //如果终点不需要扣血,则到达终点只需1血量
    //先从底层一行开始
    for(int j=m-2;j>=0;j--)
    {
        dp[n-1][j] = max(1,dp[n-1][j+1]-dp[n-1][j]);//这步很妙
    }
    //最右侧一列
    for(int i=n-2;i>=0;i--)
    {
        dp[i][m-1] = max(1,dp[i+1][m-1]-dp[i][m-1]);//这步很妙
    }    
    for(int i=n-2;i>=0;i--)
    {
        for (int j=m-2;j>=0;j--)
        {
            dp[i][j] =max(1,-dp[i][j]+min(dp[i+1][j],dp[i][j+1]));//这步很妙
        }
    }
    printf("%d",dp[0][0]);
    return 0;
}