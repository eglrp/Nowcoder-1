
#include <cstdio>
int a[10]={3,4,6,2,5,9,7,9};

void insert_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i;
        int temp=a[j];
        while (j>0 && temp>a[j-1])
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
}


int main()
{
    int n=10;
    insert_sort(a,n);
    for (int i=0;i<10;i++) printf("%d ",a[i]);
    return 0;
}