#include <string>
#include<iostream>
using namespace std;
int multi(string a)
{
    int ans =0;
    int nums[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    for(int i=0;i<17;i++)
    {
        ans += (a[i]-'0')*nums[i];
    }
    return ans%11;
}
int main()
{
    int n;
    cin >> n;
    char check[11] = {'1','0','X','9','8','7','6','5','4','3','2'}; //'x'是char 类型
    bool flag = true;
    while (n--)
    {
        string s;
        cin >>s;
        int n = multi(s);
        if (check[n] != s[17])
        {
            flag = false;
            cout << s <<endl;
        }

    }
    if (flag) cout <<"All passed" <<endl;

    return 0;
}