#include <string>
#include<iostream>
using namespace std;
//原题可在牛客网找到, 大意从左到右将字符是aabb转化为aab. 将aaa转化为aa
//样例 hellloo-->hello, wooooow-->woow, 
//解题思路比较简单,分两步,一步是解决ooo, 第二步是解决aabb.
int main()
{
    int n;
    cin >> n;
    string s;
    while ((n--)&&(cin>>s))
    {
        //先去除3个重复数字
        int length =s.size(); 
        int count = 1;
        string ans="";
        for (int i = 0; i < length;i++)
        {
            if(i==0){ans += s[0]; continue;}
            if(s[i]==s[i-1]) count++;
            else count = 1;
            if(count == 3) //表示当前s[i]不能加进去
            {
                while (i<length && (s[i]==s[i-1]))
                {
                    i++;
                }
                count = 1;
            }
            if(i<length) ans +=s[i];// 因为有可能woooooo的情况
        }
        //然后开始去除第二部分的aabb部分.
        s = ans;
        ans="";
        count = 2;
        length = s.size();
        for (int i = 0; i < length;i++)
        {
            if(i==0){ans += s[0]; continue;}
            if(s[i]==s[i-1])
            {
                if (count==1) i++; //跳过此数,count==1表示bb紧跟在aa后面
                count = 0;
            }
            else
            {
                count++;
            } 
            ans +=s[i];// 因为有可能woooooo的情况
        }
        cout << ans << endl;
    }
    return 0;
}