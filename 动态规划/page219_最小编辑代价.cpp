#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        vector<vector<int> > dp(n+1);//因为考虑到空串
        for (int i=0;i<n+1;i++) dp[i].resize(m+1);
        //初始化第一行
        for(int i=0;i<m+1;i++) dp[0][i]=i*c0; //无脑插入
        //初始化第一列
        for(int i=0;i<n+1;i++) dp[i][0]=i*c1; //不断删除
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]; //因为下标比正常的大1
                //三种操作的比拼. 
                else
                {
                    dp[i][j] = min(min(dp[i][j-1]+c0,dp[i-1][j]+c1), dp[i-1][j-1]+c2);
                }
            }
        }
        return dp[n][m];
    }
};

int main()
{
    string a="abc",b="adc";
    // cin >> a>>b;
    MinCost ans;
    cout << ans.findMinCost(a,a.size(),b,b.size(),5,3,100)<<endl;
    return 0;
}