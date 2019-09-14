#include <cstdio>
#include <algorithm>
using namespace std;

void to_array(int n, int nums[])
{
    int i = 0;
    while (i<4)
    {
        nums[i] = n % 10;
        i++;
        n /= 10;
    }
}

int to_number(int nums[])
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        ans = ans * 10 + nums[i];
    }
    return ans;
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, Max, Min;
    int nums[4];
    scanf("%d", &n);

    while (n)
    {
        to_array(n, nums);
        sort(nums, nums + 4);
        Min = to_number(nums);
        sort(nums, nums + 4, cmp);
        Max = to_number(nums);

        n = Max - Min;
        printf("%04d - %04d = %04d\n", Max, Min, n);
        if (n==0 || n==6174) break;
    }

    return 0;
}