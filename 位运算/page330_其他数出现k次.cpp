#include<cstdio>
using namespace std;
//原理很6, k进制的k次无进位加和必然为0; 其实就是上题偶次异或的扩展.确实很奇妙
//但本题还有更直观的解法, 因为其他数出现k次,因此对所有数对每个进制位上进行加和
//然后%k,则剩下的就是出现1次的数的进制位的值. 简单起见,可用2进制进行处理.
int main()
{

    int n,k,ans=0;
    int temp, count[32]={0};
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {   //不能直接通过总和%k的原因是ans有可能也是k的倍数,会得到0.因此要用数进制位的方法
        scanf("%d",&temp);
        for(int j=0;temp>0;j++)
        {
            if (temp & 1) count[j]++;
            temp = temp>>1;
        }
    }
    //得到上面求和结果后,开始对进制进行%k
    for(int i=0;i<32;i++)
    {
        count[i] = count[i]%k;
        ans = ans + (count[i]<<i); //还有顺序问题,因此要括号
    }
    printf("%d",ans);
    return 0;
} 
