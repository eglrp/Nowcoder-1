#include<iostream>
#include<vector>
#define mod 1000000007
//原理,每一步分为三个阶段 f(n)=f(n-1)+1+f(n-1). 汉诺塔, 因此得到f(n)=(2^n)-1;
//根据最底层的n的位置来判断,当前处于哪个阶段. 
//如果n=from 则处于第一阶段, n=mid则错误位置,返回-1, n=to则第三阶段,至少有f(n-1)+1
using namespace std;

class Hanoi {
public:
    int chkStep(vector<int> arr, int n) {
        // 该解法适合n小的情况(空间复杂度很高), n大的情况见非递归解法.
        return func(arr,n-1,1,3,2);
    }
    int func(vector<int> arr, int n, int from,int to, int temp)
    {
        if(n==-1)  return 0; //终止条件

        //根据底层N判断目前进入哪个阶段
        if (arr[n]==from) //表示第一阶段还没完成
        {
            return func(arr,n-1,from,temp,to);
        }
        if (arr[n]==temp) //表示错误状态
        {
            return -1;
        }
        if (arr[n]==to) //表示第一和第二阶段已完成
        {
            int flag = func(arr,n-1,temp,to,from);
            return (flag == -1)?-1:((((long long)1)<<n)%mod+flag%mod)%mod;// 因为n很大,因此要longlong
        }
    }
    //非递归解法
    int chkStep2(vector<int> arr, int n) {
        // write code here
        int ans=0;
        int from = 1, to=3,mid=2;
        vector<int> help(n,1); 
        for(int i=1;i<n;i++)
        {
            //因为n很大,迭代过程需要的2^n,longlong也救不回来, 因此需要幂的求模来帮忙
            //原理很简单, 2^2 %mod = 2%mod * 2%mod. 
            help[i] = (help[i-1]<<1)%mod;
        }
        while (n--)
        {
            if(arr[n] == from) 
            {
                int temp = to; 
                from = from;
                to = mid;
                mid = temp;
            }
            else if(arr[n]==to)
            {
                ans = (ans+help[n]%mod)%mod;//累加步数, 
                int temp = from; 
                from = mid;
                to = to;
                mid = temp;
            }
            else
            {
                ans = -1;
                break;
            }
        }
        return ans;
    }
      
};



int main()
{
    int n;
    cin >> n;
    vector<int> a(n); //用数组初始化
    for(int i = 0;i<n;i++)
    {
        cin >> a[i];
    }
    Hanoi b;
    cout <<b.chkStep2(a,n)<<endl;

    return 0;
}