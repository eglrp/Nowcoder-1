#include <cstdio>

#include <algorithm>
using namespace std;

void merge1(int array[],int l1,int r1,int l2,int r2)
{
    int temp[6],index=0,x=l1;
    while (l1<=r1 && l2<=r2)
    {
        if (array[l1]>array[l2])
        {
            temp[index++]=array[l2++];
        }
        else
        {
            temp[index++]=array[l1++];
        }
    }

    while (l1<=r1) temp[index++]=array[l1++];
    while (l2<=r2) temp[index++]=array[l2++]; //清空库存

    for (int i=0;i<index;i++) array[x+i]=temp[i]; //搬移数据
}   

void merge_sort(int array[],int left,int right)
{
    if (right > left )
    {
        int mid=(left+right)/2;
        merge_sort(array,left,mid);
        merge_sort(array,mid+1,right);
        merge1(array,left,mid,mid+1,right);
    }
}


int main()
{

    int array[6]={5,6,3,2,4,1};
    merge_sort(array,0,5);
    for (int i=0;i<6;i++) printf("%d ",array[i]);

    return 0;
}