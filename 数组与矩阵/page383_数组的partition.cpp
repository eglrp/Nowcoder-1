#include <vector>
#include <cstdio>
using namespace std;

void swap(vector<int> &a, int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    int left=0;
    for(int i=1;i<n;)
    {
        if(v[left]==v[i]) i++;
        else
        {
            swap(v,++left,i++); //left+1,i+1 往后延伸.
        }   
    }
    printf("%d",v[0]);
    for(int i=1;i<n;i++) printf(" %d",v[i]);
    return 0;
}