//老套路 f(n)=f(n-1)+f(n-2)
//斐波那契数组 但由于范围过大,因此需要用状态转移矩阵的幂求法,得到logN的解法
#include <cstdio>
using namespace std;
void matrx_mul(long long (&a)[2][2], long long b[2][2])
{
    long long temp[2][2] = {0};
    for(int i=0;i<2;i++) //矩阵乘法.
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                temp[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<2;i++) //完成之后复制temp到a
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=temp[i][j];
        }
    }
}

void matrx_pow(long long (&a)[2][2], int n)
{
    long long unit[2][2] = {{1, 0}, {0, 1}};
    long long temp[2][2] = {{1,1},{1,0}};
    while (n)
    {
        if (n & 1) matrx_mul(unit,temp);
        matrx_mul(temp,temp);
        n = n>>1;
    }

    for(int i=0;i<2;i++) //完成之后复制temp到a
    {
        for(int j=0;j<2;j++)
        {
            a[i][j]=unit[i][j];
        }
    }
}



int main()
{
    int n, a, b;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        b = b - a;
        if (b < 3)
        {
            printf("%d\n", b);
            continue;
        }
        long long pattern[2][2] = {{1, 1}, {1, 0}};
        matrx_pow(pattern, b - 2);
        long long ans = 2 * pattern[0][0] + pattern[1][0];
        printf("%lld\n", ans);
    }
    return 0;
}