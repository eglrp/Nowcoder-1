#include <iostream>
#include <vector> //变长数组默认使用.
#define mod 1000000007 
using namespace std;


void matrix_mul(long long a[2][2], long long b[2][2], long long ans[2][2])
{
    //矩阵相乘 N^3复杂度
    long long temp[2][2] = {{0,0},{0,0}};
    for (int k=0;k<2;k++) //开始计算矩阵相乘
    {
        for (int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++) //向量点乘
            {
                temp[i][j]=(temp[i][j] +(a[i][k]*b[k][j]) %mod) %mod;
            }
        }
    }
    //将temp 值复制到ans中
    for (int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            ans[i][j]=temp[i][j];
        }
    }
}

int main()
{
    long long  n ;
    cin >> n;         
    long long pattern[2][2]={{1,1},{1,0}}; // 定长数组可以这样来
    long long ans[2][2]={{1,0},{0,1}}; //单位矩阵
    
    for(n-=2;n>0;n=n>>1)
    {
        if (n&1) matrix_mul(ans,pattern,ans);
        matrix_mul(pattern,pattern,pattern);
    }
    
    long long res = 0;
    res = (ans[0][0]+ans[1][0])%mod;
    cout << res <<endl;

    return 0;
}