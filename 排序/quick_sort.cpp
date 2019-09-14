#include <cstdio>
#include <algorithm>
using namespace std;

int partion(int array[], int left, int right)
{
    int val = array[right];
    while (left < right)
    { //最右边都是大于temp的,遇到小于则停下,此时right位置就是该交换的数的index.
        while (right > left && array[left] < val)
            left++;
        array[right] = array[left];
        while (left < right && array[right] >= val)
            right--;
        array[left] = array[right];
        array[right] = val;
    }
    return right;
}
void quick_sort(int array[], int left, int right)
{
    //递归写法
    if (left < right)
    {
        int pos = partion(array, left, right);
        quick_sort(array, left, pos - 1);
        quick_sort(array, pos + 1, right);
    }
}

int main()
{
    int n = 5;
    int array[5] = {3, 1, 4, 2, 5};

    quick_sort(array, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    return 0;
}