//PAT乙级, 1001 采花生
//这题有bug, 返回样例都是错的, 另外边界条件很神仙,要小心.
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Point
{
    int i;
    int j;
    int val;
};

bool cmp(Point a, Point b)
{
    return a.val < b.val; //升序排列.
}
bool home(int i, int j, int k) // 判断能否回路边
{
    return k >= j + 1; //仅需回到第一行+1即可
}
int count(int x, int y, int aim_x, int aim_y) //两位置之间消耗的能量
{
    return abs(x - aim_x) + abs(y - aim_y) + 1; //1表示采摘
}

int main()
{
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) != EOF) //这句很重要, cin会等待超时,神仙OJ.
    {
        vector<vector<int> > v(n);
        vector<Point> points;
        for (int i = 0; i < n; i++)
        {
            v[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &v[i][j]);
                if (v[i][j] > 0)
                {
                    Point temp = {i, j, v[i][j]}; //可以在定义时就初始化.
                    points.push_back(temp);
                }
            }
        }
        //存好数据后,开始排序.
        sort(points.begin(), points.end(), cmp);
        //有了目标之后开始按照指示行动.

        int ans = 0;
        int x, y = 0;
        int num = points.size() - 1; //表示有几个目标, 最大值在n-1处,,
        //神仙情况是0000, 没有目标,则n-1会溢出
        if (num<0) //神仙边界
        {
            printf("0\n");
            continue;
        }
        x = points[num].i;
        k--;             // 先跳到路边, 损失一个能量.
        while (num >= 0) //home表示有能量回家, nums表示采摘是否完毕.
        {
            int aim_x = points[num].i;
            int aim_y = points[num].j;
            k = k - count(x, y, aim_x, aim_y);
            if (home(aim_x, aim_y, k)) //目标点处能不能回家.
            {
                ans += points[num].val;
                x = aim_x;
                y = aim_y;
            }
            else
                break;
            num--;
        }
        // printf("%d",k);
        printf("%d\n", ans);
    }
    return 0;
}