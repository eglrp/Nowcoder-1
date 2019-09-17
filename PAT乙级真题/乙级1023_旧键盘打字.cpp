#include <string>
#include<iostream>
#include<map>
using namespace std;


int main()
{
    map<char, int> mp;
    string no, target; 
    cin >> no;
    bool  upshift = true;
    for(int i=0;i<no.size();i++)
    {
        mp[no[i]] = 1; //存入小写
        if (no[i] == '+') upshift = false;
    }
    cin >> target; 
    for(int i=0;i<target.size();i++)
    {
        if ('a' <= target[i] && target[i]<='z' ) 
        {
            if (mp[(char)(target[i]-32)]!=1) cout<<target[i]; //如果可行则输出
        }  
        else if('A' <= target[i] && target[i] <='Z')
        {
            if (upshift && mp[target[i]]!=1) cout << target[i]; 
        }
        else
        {
            if (mp[target[i]]!=1) cout << target[i];
        }     
    }
    cout << endl;
    return 0;
}