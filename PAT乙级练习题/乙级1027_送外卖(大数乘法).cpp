//这题就比较巧妙, 遍历矩阵的最短路径,实际上可以把矩阵的各个节点
//当成一串,这样从头到尾需要m*n-1, 由于首尾相连,因此n*m; 这肯定是最快的方法
//仅有n*m其中之一为偶数才可以做到, 如果都为奇数, 则有一个节点需要sqrt(2)-1.
//因此答案为n*m+sqrt(2)-1. 
//本题的另一个难点在于大数乘法, 2^128  Longlong也装不下,因此利用非进位乘法来
//处理大数乘法的相关问题.
#include<iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> vector_mul(vector<int> a, vector<int> b)//pos表示a是第几位的
{
    vector<int> ans(a.size()+b.size());//按乘法最多的位数考虑.
    for(int i=0;i<b.size();i++)
    {
        for(int j=0;j<a.size();j++)
        {
            int pos = i+j;
            ans[pos] = ans[pos]+a[j]*b[i];
            while (ans[pos]>=10) //一直消除进位
            {
                ans[pos+1] += ans[pos]/10;
                ans[pos] = ans[pos]%10;
                pos++;
            }
        }
    }
    //消减ans的位数. 因为前面考虑太多位了
    for(int i=ans.size()-1;ans[i]==0;i--) ans.pop_back();
    return ans;
}

int main()
{
    string n,m;
    while (cin >> n>>m)
    {
        vector<int> a; vector<int> b; 
        for(int i=n.size()-1;i>=0;i--) a.push_back(n[i]-'0'); //表示低位在前.
        for(int i=m.size()-1;i>=0;i--) b.push_back(m[i]-'0');
        vector<int> ans = vector_mul(a,b);
        if ((a[0]%2==0)||(b[0]%2==0)) 
        {
            for(int i =ans.size()-1;i>=0;i--) cout << ans[i] ;
            cout << ".00"<<endl;
        }
        else
        {
            for(int i =ans.size()-1;i>=0;i--) cout << ans[i] ;
            cout << ".41"<<endl;
        }
    }
    
}