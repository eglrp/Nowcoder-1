//PAT乙级, 1002 Nowcoder序列
#include <cstdio>
using namespace std;

void matrix_mul(int (&a)[2][2] , int b[2][2])
{   
    int temp[2][2];
    temp[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0])%3;
    temp[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1])%3;
    temp[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0])%3;
    temp[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1])%3;
    a[0][0] = temp[0][0]; a[0][1] = temp[0][1]; 
    a[1][0] = temp[1][0]; a[1][1] = temp[1][1]; 
}

void matrix_pow(int (&a)[2][2], int n)
{
    int res[2][2] = {{1,0},{0,1}};
    int temp[2][2] = {{1,1},{1,0}};
    while(n)
    {
        if(n&1) matrix_mul(res,temp); 
        matrix_mul(temp,temp); //不管有没有加和都要temp^2
        n = n>>1;
    }
    a[0][0] = res[0][0]; a[0][1] = res[0][1]; 
    a[1][0] = res[1][0]; a[1][1] = res[1][1]; 
}
int main()
{
    int n;

    while (scanf("%d",&n)!=EOF) //这句很重要, cin会等待超时,神仙OJ. 
    {
        if (n < 2)
        {
            printf("No\n");
            continue;
        }
        int ans = 0;
        int pattern[2][2] = {{1,1},{1,0}};
        matrix_pow(pattern,n-1);
        ans = (11*pattern[0][0] + 7*pattern[1][0]) % 3;
        if(ans ==0 ) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}