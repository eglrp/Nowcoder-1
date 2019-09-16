#include <map>
#include<string>
#include <iostream>
using namespace std;
int main()
{
    string a,b;
    cin >> a>>b;
    map<char,int> mp;
    for(int i=0;i<b.size();i++) //先存目标
    {
        mp[b[i]]++;
    }
    for(int i=0;i<a.size();i++) //先存目标
    {
        mp[a[i]]--;
    }
    int more = 0, less = 0;
    map<char,int>::iterator it;
    for(it = mp.begin(); it!=mp.end();it++)
    {
        if (it->second > 0)
        {
            more += it->second;
        }
        else
        {
            less -= it->second;
        }
        
    }
    if (more > 0) cout <<"No "<<more;
    else cout <<"Yes "<<less;
    
    return 0;
}