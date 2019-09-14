#include<string>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string order;
    stack<int> s1,s2;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> order;
        if(order[0]=='a') 
        {
            int temp;
            cin >> temp;
            s1.push(temp);
        }
        else if(order[1]=='e') 
        {
            if(s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout << s2.top()<<endl;           
        }
        else
        {
            if(s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();  
        }
    }
    return 0;
}