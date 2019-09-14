#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int> > dp(m);
    for (int i = 0; i < m; i++)
    {
        dp[i].resize(n); //扩充成二维数组
    }

    for (int i = 0; i < m; i++) //开始计算动态规划表
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0] = s1[0] == s2[0] ? 1 : 0;
                continue;
            }
            if (s2[i] == s1[j])
            {
                dp[i][j] = ((i > 0) && (j > 0)) ? (dp[i - 1][j - 1] + 1) : 1; //相等增加1位
            }
            else
            {
                if ((i > 0) && (j > 0))
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //不相等只能继承
                else if (i > 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    //得到了dp数组, 开始返回序列
    int length = dp[m - 1][n - 1];
    string ans;
    int col = n - 1, row = m - 1;
    while (length > 0)
    {
        if (s1[col] == s2[row])
        {
            ans += s1[col];
            length--;
            col--;
            row--;
        }
        else if ((row > 0) && (dp[row][col] == dp[row - 1][col]))
        {
            row--;
        }
        else
        {
            col--;
        }
    }

    for(int i= dp[m-1][n-1];i>=0;i--)
    {
        cout<<ans[i];
    }

    return 0;
}