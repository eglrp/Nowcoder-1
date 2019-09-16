#include <cstdio>
using namespace std;
int main()
{
    char temp;
    int p = 0, pa=0, ans=0; 
    while (scanf("%c", &temp) && temp !=' ' && temp!='\n')
    {
        if (temp == 'P')
        {
            p++; //不会超过500000, 不用怕
        }
        else if (temp=='A')
        {
            pa = (pa + p)%1000000007;
        }
        else
        {
            ans = (ans + pa)%1000000007;
        }        
    }
    printf("%d\n", ans);

    return 0;
}