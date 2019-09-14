#include<string>
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    string a;
    cin >> a;
    int n=a.size(),count=1;
    if(n==1){ cout << a+"_1"<<endl;return 0;}

    stringstream ss; //为避免类型转换的困扰,用输出流暂存字符.
    char pre; //a[0]是char类型, 得用substr才能得到string

    for(int i=0;i<n;i++)
    {
        if (i==0) {ss << a[0]; pre = a[0]; continue;}
        if(a[i]==pre)
        {
            count++;
        }
        else
        {
            ss << "_"<<count<<"_"<<a[i];
            count=1;
            pre = a[i];
        }
        if(i==n-1) {ss<<"_"<<count;}
    }
    string ans;
    ss>>ans;
    cout <<ans<<endl;

    return 0;
}