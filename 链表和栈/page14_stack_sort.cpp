#include <stack>
#include <cstdio>
//原理是让help stack有序, 大的在下,小的在上,
//s1 top小于help top则装入help, 大于则s1 top先装入cur, 然后help top装入s1, 
//直到cur找到合适的help位置
using namespace std;

int main()
{
    stack<int> s1; 
    stack<int> s2;//help
    int n,temp,cur;
    scanf("%d",&n);
    for (int i=0;i<n;i++){scanf("%d",&temp); s1.push(temp);}

    while (!s1.empty())
    {
        cur = s1.top();s1.pop();
        while (!s2.empty() && cur > s2.top())
        {
           temp = s2.top(); 
           s2.pop();
           s1.push(temp);
        }
        s2.push(cur);
    }
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    
    printf("%d",s1.top()); s1.pop(); //这一步是为了满足输出格式要求
    while(!s1.empty())
    {
        printf(" %d",s1.top());
        s1.pop(); //pop 返回void
    }

    return 0;
}
