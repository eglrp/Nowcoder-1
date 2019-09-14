#include <cstdio>
#include <vector>

using namespace std;
 // 原理很简单, 因为升序且, 相同成分只需遇一次打印一次即可. 
int main()
{
    int n, m, temp;
    vector<int> l1, l2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        l1.push_back(temp);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        l2.push_back(temp);
    }

    int pos1 = 0, pos2 = 0;
    bool flag = true; //表示第一次遇到
    while (pos1 != n && pos2 != m)
    {
        if (l1[pos1] < l2[pos2])
        {
            pos1++;
        }
        else if (l1[pos1] > l2[pos2])
        {
            pos2++;
        }
        else
        {
            if (flag)
            {
                flag = false;
                printf("%d", l1[pos1]);
            }
            else
            {
                printf(" %d", l1[pos1]);
            }
            pos1++;
            pos2++;
        }
    }
    return 0;
}