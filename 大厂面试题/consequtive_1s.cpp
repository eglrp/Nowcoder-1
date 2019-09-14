#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nums1[10] = {0}, nums2[10] = {0};

void func1(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int  temp=i;
        while (temp)
        {
            nums1[temp%10]+=1;
            temp/=10;
        }
    }
}
void func2(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int temp = s[i] - '0';
        nums2[temp] += 1;
    }
}

int main()
{
    int n;
    string s;
    vector<int> ans[2];
    cin >> n;
    cin >> s;
    func1(n);
    func2(s);
    for (int i=0;i<10;i++)
    {
        if(nums1[i]!=nums2[i])
        {
            ans[0].push_back(i);
            ans[1].push_back(abs(nums1[i]-nums2[i]));
        }
    }
    if (ans[0].size()==2)
    {
        if (ans[0][0]*10+ans[0][1]<41)
        {
            cout << ans[0][0]*10+ans[0][1];
        }
        else
        {
            cout << ans[0][1]*10+ans[0][0];
        }
    }
    else if (ans[1][0]==2)
    {
        cout << ans[0][0]*10+ans[0][0];
    }
    else
    {
        cout << ans[0][0];
    }
       
    return 0;
}
