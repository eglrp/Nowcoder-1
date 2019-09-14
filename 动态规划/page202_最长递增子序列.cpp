#include<vector> 
#include<cstdio>
#include<algorithm>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);

    vector<int> a(n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);

    vector<int> dp(n);
    dp[0]=1;
    //此复杂度为O(N^2), 要实现Nlog(N)的复杂度,需要额外的ends[]数组辅助,
    //因为重点是长度,因此end合并长度, index+1表示长度,end[index]表示长度为index+1的末尾最小节点的值.
    // for(int i=0;i<n;i++) 
    // {
    //     int temp = 1<<31;//先设为最小值
    //     for (int j=0;j<i;j++)
    //     {
    //         if (a[j]<a[i])
    //         {
    //             temp = max(temp,dp[j]);   
    //         }
    //     }
    //     dp[i] = (temp==1<<31)?1:(temp+1);
    // }
    // 这个方法为Nlog(N)的方法,由于递增序列,保证ends的值有序,因此能用二分法.
    vector<int> ends(n);
    ends[0]=a[0];
    int count=0,mid,right,left; //二分法做准备
    for (int i=1;i<n;i++)
    {
        //为每一个a[i]更新ends数组
        if (a[i]>ends[count]) //大于最右边直接加一
        {
            count++;
            ends[count]=a[i];
            dp[i]=count+1;
            continue;
        }
        //小于最右边, 则二分法查找
        left = 0;
        right = count;
        while(left<=right) //二分法
        {
            mid = left+(right-left)/2;
            if(a[i]>ends[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        right = max(right,left);//这个点就是该替换的点
        ends[right] = a[i];
        dp[i] = right+1;
    }

    //下面开始输出可能的序列. 原理是dp[i]=dp[j]-1,且a[i]>a[j]
    //则序列a[i],a[j]必然可行, 因此ij是最长序列的一部分
    //由于要求递增,因此如果dp[i对=dp[i-1]则对a[i],a[j]哪个小.只能是右边较小,因为如果左边小,右边保证能加入.有矛盾
    int pos = n-1;
    while ((pos-1>=0)&&(dp[pos]<dp[pos-1])) pos--; //找到最大的那个index
    int index = dp[pos]; //存储下长度
    vector<int> ans(index,-1);
    index--;

    while(ans[0]==-1)
    {
        if (pos==0)
        {
            ans[index--]=a[0];
            break;
        }
        while ((pos-1>=0) && (dp[pos]==dp[pos-1])) //如果出现重复序列, 则找到重复序列a[pos]最小值
        {
            a[pos-1]=(a[pos]<a[pos-1])?a[pos]:a[pos-1];
            pos--; //找到最小值
        }
        ans[index--]=a[pos]; //如果没有双序列,直接push最大的那个节点.
      
        for (int j=pos;j>=0;j--) //开始找下一个节点
        {
            if (dp[pos]==dp[j]+1)
            {
                pos = j; //找到了下一个起始节点,开始下一轮更新.
                break;
            }
        }   
    }
    //开始输出序列
    printf("%d",*(ans.begin()));
    for (int i=1;i<ans.size();i++)
    {
        printf(" %d",ans[i]);
    }
    return 0;
}