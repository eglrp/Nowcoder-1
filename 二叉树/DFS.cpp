#include <cstdio>

using namespace std;

struct Node
{
   int weight;
   int value;
} node[1001];

int ans=0;
int V,N;

void DFS(int index,int weight,int value)
{
    if (weight>V) return;
    if (index==N) 
    {
        ans = (value>ans)?value:ans;      
        return;
    }
    DFS(index+1,weight,value);//无添加
    DFS(index+1,weight+node[index].weight,value+node[index].value); //有添加
}
int main()
{
    scanf("%d %d",&V,&N);
    for (int i=0;i<N;i++) scanf("%d %d",&node[i].weight,&node[i].value);

    int temp_weight=0,temp_value=0;
    for (int i=0;i<N;i++) 
    {
        temp_weight+=node[i].weight;
        temp_value+=node[i].value;
    }
    if (temp_weight<=V)
    {
        printf("%d\n",temp_value);
    }
    else
    {
        DFS(0,0,0);
        printf("%d",ans);
    }
    return 0;
}


// 版本2
// #include <cstdio>
// #include <vector>
// using namespace std;

// int n, p, k, max_fac_sum = 0;
// vector<int> factor, ans, temp;
// int power(int ans)
// {
//     int temp = 1;
//     for (int i = 0; i < p; i++)
//     {
//         temp *= ans; //自定义的幂次方函数
//     }
//     return temp;
// }

// void init()
// {
//     for (int i = 1; power(i) <= n; i++)
//     {
//         factor.push_back(power(i));
//     }
// }

// void DFS(int index, int nowk, int sum, int fac_sum)
// {
//     //边界
//     if (nowk == k && sum == n)
//     {
//         if (fac_sum > max_fac_sum)
//         {
//             max_fac_sum = fac_sum;
//             ans = temp; //这么简单粗暴!!
//             return;
//         }
//     }
//     if (index < 0 || nowk >= k || sum > n)
//         return; //超过个数了,或者重量超了

//     temp.push_back(index);                                      //添加index
//     DFS(index, nowk + 1, sum + factor[index], fac_sum + index); //同一个index还能继续添加
//     temp.pop_back();                                            //发现不行后撤销index.
//     DFS(index - 1, nowk, sum, fac_sum);                         //跳过index,其他参数不变
// }

// int main()
// {
//     scanf("%d%d%d", &n, &k, &p);
//     init();
//     DFS(factor.size() - 1, 0, 0, 0);

//     if (max_fac_sum == 0)
//     {
//         printf("Impossible\n");
//     }
//     else
//     {

//         printf("%d^%d", ans[0] + 1, p);
//         for (int i = 1; i < ans.size(); i++)
//         {
//             printf("+ %d^%d", ans[i] + 1, p);
//         }
//     }

//     return 0;
// }