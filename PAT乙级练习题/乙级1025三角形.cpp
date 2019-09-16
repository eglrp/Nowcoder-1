//加法器而已. 大数加法. string没有+=符号,但是有a= a+'s';的功能, 要记住.
#include <string>
#include <iostream>
using namespace std;
string add(string a, string b)
{
    string ans = ""; //string 是可以追加char字符的
    int i = a.size() - 1, j = b.size() - 1;
    int c0 = 0; //表示进位
    while (i >= 0 && j >= 0)
    {
        char temp = (a[i] - '0' + b[j] - '0' + c0);
        c0 = temp >= 10 ? 1:0;
        ans = (char)(temp % 10+'0') + ans;
        i--;j--;
    }
     //清空后面的s[j]或是s[i]
    while (i>=0)
    {
        char temp = (a[i] - '0' + c0);
        c0 = temp >= 10 ? 1:0;
        ans = (char)(temp % 10+'0') + ans;
        i--;
    }
    while (j>=0)
    {
        char temp = (b[j] - '0' + c0);
        c0 = temp >= 10 ? 1:0;
        ans = (char)(temp % 10+'0') + ans;
        j--;
    }
    if (c0) ans = "1" + ans; 
    return ans;
}
bool bigger(string a,string b)
{
    if (a.size()>b.size()) return true;
    if (a.size()<b.size()) return false;
    return a>b; //等长就比字典序.
}
int main()
{
    string a,b,c;
    while (cin >> a>>b>>c)
    {
        if (bigger(add(a,b),c)&&bigger(add(a,c),b)&&bigger(add(c,b),a)) cout << "Yes"<<endl;
        else cout <<"No"<<endl;
    }

    return 0;
}