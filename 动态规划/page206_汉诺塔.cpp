#include <vector>
#include<string>
#include<iostream>
using namespace std;
//原理很简单,递归处理,复杂度(2^N), 起点,停靠点,终点,之间trade off.
class Hanoi {
public:
    vector<string> getSolution(int n) {
        vector<string> ans;
        get(n,"left","mid","right",ans);//从起始点到中转站, &表示引用, 不是局部变量.
        return ans;
    }
    void get(int n, string left, string mid, string right, vector<string> &ans)
    {
        if(n==1)
        {
            // cout << "move from "<<left<<" to "<<right<<endl;
            ans.push_back("move from "+left+" to "+right);
        }
        else
        {
            get(n-1,left,right,mid,ans); //第三个参数为终点
            get(1,left,mid,right,ans);
            get(n-1,mid,left,right,ans); //"中间为中转站,空闲桩"
        }
    }
};

int main()
{

    int n=2;
    Hanoi a;
    a.getSolution(n);
    return 0;
}