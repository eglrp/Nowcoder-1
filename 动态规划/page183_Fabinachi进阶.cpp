#include <iostream>
#include <vector> //变长数组默认使用.
#define mod 1000000007 
using namespace std;

//题目是变形的斐波那契--母牛问题
void matrix_mul(long long a[3][3], long long b[3][3], long long ans[3][3])
{
    //矩阵相乘 N^3复杂度
    long long temp[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    for (int i=0;i<3;i++) //开始计算矩阵相乘
    {
        for(int j=0;j<3;j++)
        {
            for (int k=0;k<3;k++) //向量点乘
            {
                temp[i][j]=(temp[i][j] +(a[i][k]*b[k][j]) %mod) %mod;
            }
        }
    }
    //将temp 值复制到ans中
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            ans[i][j]=temp[i][j];
        }
    }
}

int main()
{
    long long  n;
    cin >> n; 
    if (n<=4)  {cout << n; return 0;}         
    long long pattern[3][3]={{1,1,0},{0,0,1},{1,0,0}}; // 定长数组可以这样来
    long long ans[3][3]={{1,0,0},{0,1,0},{0,0,1}}; //单位矩阵
    
    for(n-=3;n>0;n=n>>1)
    {
        if (n&1) matrix_mul(ans,pattern,ans);
        matrix_mul(pattern,pattern,pattern);
    }
    
    long long res = 0;
    res = (3*ans[0][0]+2*ans[1][0]+1*ans[2][0])%mod;
    cout << res <<endl;

    return 0;
}