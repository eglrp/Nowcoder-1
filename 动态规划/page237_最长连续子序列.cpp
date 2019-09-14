#include<map>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    map<int,int> mp;
    int temp;
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&temp);
        mp[temp] = 1;
    }
    map<int,int>::iterator it = mp.begin();//iter 默认为指针,因此才需要*结构
    int start = (it++)->first;
    int count = 1;
    int max = 1;
    while (it!=mp.end())
    {
        if(it->first==start+count)
        {
            count++;
            max = max > count ? max :count;
        }
        else
        {
            count = 1; 
            start = it->first;
        }
        it++;
    }
    printf("%d",max);
    return 0;
}