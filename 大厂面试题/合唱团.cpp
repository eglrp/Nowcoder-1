#include <cstdio>

long long fm[51][11] = {{1}}; //表示n个取k个的最大值
long long fn[51][11];         //最小值

long long max(long long a, long long b) { return (a > b) ? a : b; }
long long min(long long a, long long b) { return (a > b) ? b : a; }

long long INF = 1000000000;

int main()
{
    int N, stu[51], K, D;
    long long ans = -INF;
    while (scanf("%d", &N) != EOF)
    {
        for (int i = 1; i <= N;scanf("%d", &stu[i++]));
        scanf("%d %d", &K, &D);

        for (int i = 1; i <= N; i++) //附初值
        {
            for (int j = 1; j <= K; fn[i][j] = INF,fm[i][j++] = -INF)
                ;
        }

        for (int n = 1; n <= N; n++)
        {
            fn[n][1] = stu[n]; fm[n][1] = stu[n]; //设定初值,因为fm的定义就是a[n]必选!!
            for (int k = 2; k <= K && k<=n; k++)
            {
                for (int j = n - 1; j >0 && j >= n - D && j>=k-1 ; j--)
                { //为了这样写就必须设定初值
                    fm[n][k] = max(fm[n][k], max(fm[j][k - 1] * stu[n], fn[j][k - 1] * stu[n]));
                    fn[n][k] = min(fn[n][k], min(fm[j][k - 1] * stu[n], fn[j][k - 1] * stu[n]));
                }
            }
            ans = max(ans, fm[n][K]);
        }
        printf("%lld",ans);
    }

    return 0;
}

