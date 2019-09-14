//这题也也有用, 子问题是保证有底部的最大矩形面积.
//1 0 1 0
//1 1 1 0
//1 1 1 1 求此图形的最大矩形面积.
//如果解决了上面的子问题, 则原问题只需遍历原矩形的行,造出子问题即可即可

//子问题最重要的是得到''最近''的小于当前点的值. 用stack配合一定规则可以做到.(类似滑动窗口)
//比如大于stack.top的直接加入,小于stack.top则一直对stack进行pop操作,直到stack.top比新元素小
//这样一来stack.top保证是当前节点a[i]的左边最近且小于的a[i]节点.
//仅当stackpop时进行面积计算,这样做有个好处保证pop值的''左右边界''已知.
//stack.top+1是左边界,加入的新节点i-1是右边界, 因此面积为height[pop]*(i-top-1)
//清理完之后, stack剩下的就是单调递增序列, 有个优点是右边界必然为height.
//面积表达式为height[pop]*(height-top-1)
//重复pop操作,计算面积,直到stack为空.

#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
int sub_func(vector<int> h)
{
    stack<int> s;
    int ans = 0, curarea;
    int left, right, cur_index;
    for (int i=0;i<h.size();i++)
    {
        while (!s.empty() && h[i]<=h[s.top()] )//等号不用怕,高度相等的连续元素只需其中一个返回正确值即可
        {
            cur_index = s.top(); 
            s.pop();
            //计算temp元素最大的扩展面积, 最左为
            left = s.empty()?-1:s.top();
            right = i;
            curarea = h[cur_index] * (right-left-1);  
            ans = ans > curarea ? ans : curarea;   
        }
        s.push(i);   
    }
    //剩下的stack保证是升序的, 对各个元素最右扩展到m,最左到s.top()
    while(!s.empty())
    {
        cur_index = s.top(); 
        s.pop();
        left = s.empty()?-1:s.top();
        right = h.size();
        curarea = h[cur_index] * (right-left-1);  
        ans = ans > curarea ? ans : curarea;  
    }
    return ans;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > dp(n);
    for (int i = 0; i < n; i++) //存入数据
    {
        dp[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &dp[i][j]);
        }
    }
    //造出height子序列, 
    vector<int> height(m);
    int ans = 0; //先设成最小值
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            height[j] = (dp[i][j]==0)? 0: (height[j]+1);
        }
        int temp = sub_func(height);
        ans = ans > temp ? ans: temp; 
    }
    printf("%d",ans);
    return 0;
}
