//经典题型, 涉及到新旧坐标的转换, 先换成0...n-1的坐标,
//然后对0...n-1 进行淘汰, 并从淘汰的下一个开始012..n-2. 
//一直重复下去, 得到最后一个数, 必然为0.
//然后将0往回代, 得到旧坐标的表达式.

#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int new_num = 0; //最后一轮的新编号
        for(int i=1;i<n;i++)
        {
            new_num = (new_num+m)%(i+1);
        }
        printf("%d\n",new_num+1);
    }
    
    return 0;
}