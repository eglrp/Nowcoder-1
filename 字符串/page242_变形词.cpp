#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    bool flag = true;
    scanf("%d%d",&n,&m);
    if (n != m)
    {
        flag = false;
    }
    else
    {
        char a[n+1],b[m+1];
        scanf("%s",a);
        scanf("%s",b);
        int mp1[260]={0};
        for (int i = 0; i < n; i++)
        {
            mp1[a[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mp1[b[i]] == 0)
            {
                flag = false;
                break;
            }
            mp1[b[i]]--;
        }
    }
    if (flag)
    {
        printf("true\n");
    }
    else
    {
        printf("flase\n");
    }

    return 0;
}