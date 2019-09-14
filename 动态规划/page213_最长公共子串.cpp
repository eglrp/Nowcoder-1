#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
//比起最长公共子序列简单多了, 下面是时间O(n*m),空间O(n*m)的方法
//可以简单的遍历做到时间O(n*m),空间O(1)的方法,遍历++的方法.
int main() 
{
    char s1[1001],s2[1001];
    gets(s1);
    gets(s2); //gets只有回车才算结束.
    int n=strlen(s1), m=strlen(s2); //n为行,m为列
    vector<vector<int> > dp(n);
    for(int i =0;i<n;i++)
    {
        dp[i].resize(m);
    }
    int max = 1<<31;// 先设成最小的值
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i][j] = ((i>0)&&(j>0))?(dp[i-1][j-1]+1):1;
                max = (max>dp[i][j])?max:dp[i][j];
            }
        }
    }
    printf("%d",max);

    return 0;
}