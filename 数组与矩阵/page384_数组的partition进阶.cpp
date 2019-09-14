#include <vector>
#include <cstdio>
using namespace std;

void swap(vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    int left = -1, right = n;

    for (int i = 0; i < right;)
    {
        if (v[i] == 0)
        {
            swap(v,i++,++left); //保证前面换过来的数是1, 因此可以i++.
        }
        else if( v[i]==2)
        {
            swap(v,i,--right); //这里不要i++, 因为交换过来的数还是未知,因此还需进一步判断
        }
        else
        {
            i++; //
        }
    }
    printf("%d", v[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", v[i]);
    return 0;
}