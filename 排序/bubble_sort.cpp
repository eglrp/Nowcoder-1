#include <cstdio>

using namespace std;

int main()
{

    int a[5]={3,1,4,5,2};
    for (int i=0;i<4;i++) //肯定要冒泡n-1次
    {
        for(int pointer=1;pointer<5-i;pointer++)
        {
            if (a[pointer-1] > a[pointer]) 
            {
               int temp=a[pointer-1];
                a[pointer-1]=a[pointer];
                a[pointer]=temp;
            }
        }
    }

    for (int j=0;j<5;j++) printf("%d ",a[j]);

    return 0;
}
