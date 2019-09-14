#include <iostream>
#include <string>
#include <stack> 
#include <cmath>
using namespace std;

int main()
{

    int n;
    cin >> n;
    string order;
    stack<int> s1,s2;
    int num, minNum=1<<31-1;
    for (int i = 0; i < n; i++)
    {
        cin >> order;
        if (order == (string) "pop")
        {
            s1.pop();
            s2.pop();
        }
        if (order == (string) "push")
        {
            cin >> num;
            minNum = s2.empty()?num:(num<s2.top()?num:s2.top());

            s1.push(num);
            s2.push(minNum);
        }
        if (order == (string) "getMin")
        {
            cout << s2.top()<<endl;
        }
    }

    return 0;
}