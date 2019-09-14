//题目最小面积子矩阵 // 本身遍历就需要O(N^4),再计算加和又要O(N^2)因此得考虑如何化简
//可以通过加和到一行的方式进行压缩, 判断一行内的加和大于k的个数. 
// 此时仍要O(N^2)的算法判断k, 但是外层遍历仅需O(N^3)
#include <cstdio>
#include <vector>
using namespace std;
int n, m, k;

int one_line(vector<int> height)
{//返回0-n-1表示需要几个加和才能大于k
    int ans = 0;
    vector<int> temp(height.size());
    for (int size=0;size<m;size++) 
    {
        for(int j=0;j<m-size;j++)
        {
            temp[j] += height[j+size];
            if(temp[j]>=k) return size+1; //表示最少需要多少元素
        }
    }

    return -1; //发现没有元素能超过k
}

int main()
{

    scanf("%d%d%d", &n, &m, &k);

    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++) //存入数据
    {
        dp[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }

    //开始遍历
    int ans = 1<<31-1;//先设成最大值
    for(int i=0;i<n;i++)
    {
        vector<int> height = dp[i]; 
        for(int size=1;i+size<m;size++)
        {
            int temp = one_line(height); //temp*size表示当前的面积
            ans =(temp != -1 && ans > (temp*size)) ? (temp*size): ans; //有解,且更小
            for(int j=0;j<m;j++) //加和, 更新height
            {
                height[j] += dp[i+size][j]; 
            }
        }
        if (ans == 1)
        {
            break;
        }
    }
    ans = ans == (1<<31-1) ? -1 : ans;
    printf("%d",ans);
    return 0;
}