#include <cstdio>
#include <algorithm>

#include <stack>
#include <string>
#include <map>
#include <queue>

using namespace std;

map<char, int> mp;

struct Node
{
    double num; //浮点数才够用
    char op;
    bool flag; //判断是否是操作符
} node[100];

stack<Node> sta; //储存文字
queue<Node> que; //储存后缀表示

string str = "4+2*5-7/11";

void change()
{
    Node temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int num = str[i] - '0';
            while (i + 1 < str.length() && str[i + 1] >= '0' && str[i + 1] <= '9')
            {
                num = num * 10 + str[++i] - '0';
            }
            temp.flag = false; //不是操作符
            temp.num = num;
            que.push(temp);
        }
        else
        { //操作符
            temp.op = str[i];
            temp.flag = true;
            while (!sta.empty() && mp[str[i]] <= mp[sta.top().op])
            {
                que.push(sta.top());
                sta.pop();
            }
            sta.push(temp);
        }
    }
    while (!sta.empty())
    {
        que.push(sta.top());
        sta.pop();
    }
}

double cal()
{
    Node temp_node;
    stack<double> s;
    double temp_num1, temp_num2;
    for (int i = 0; i < que.size(); que.pop())
    {
        temp_node = que.front();
        if (temp_node.flag)
        {
            temp_num1 = s.top();
            s.pop();
            temp_num2 = s.top();
            s.pop();
            if (temp_node.op == '+')
                s.push(temp_num2 + temp_num1);
            if (temp_node.op == '-')
                s.push(temp_num2 - temp_num1);
            if (temp_node.op == '*')
                s.push(temp_num2 * temp_num1);
            if (temp_node.op == '/')
                s.push(temp_num2 / temp_num1);
        }
        else
        {
            s.push(temp_node.num);
        }
    }
    return s.top();
}

int main()
{
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;

    while (!sta.empty())
        sta.pop(); //清空stack
    change();

    double num = cal();

    printf("%.2lf", num);

    return 0;
}