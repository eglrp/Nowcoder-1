#include <cstdio>
#include <algorithm>

int n = 5, P[5];
bool occupied[5] = {false}; //默认可用

void generate(int index)
{
    if (index == n)
    { //index超出范围表示终止,输出有效结果.
        for (int i = 0; i < n; i++)
            printf("%d", P[i]);
        printf("\n");
        return;
    }

    for (int x = 0; x < n; x++)
    {                             //循环遍历,
        if (occupied[x] == false) //表示没有被占用
        {
            bool flag = true;
            for (int pre = 0; pre < index; pre++)
            {                                         //判断是否对角线
                if ((index - pre) == abs(P[pre] - x)) //对角线用x,y的差来求.
                {
                    flag = false;
                    break; //直接不用往下走了,跳过一个x
                }
            }

            if (flag)
            {
                P[index] = x; //没被占用则填入当前值,index为当前index;
                occupied[x] = true;
                generate(index + 1); //继续填写下一个信息
                occupied[x] = false; //上一轮填好之后记得释放x.
            }
        }
    }
}
int main(int argc, const char **argv)
{

    generate(0);
    return 0;
}