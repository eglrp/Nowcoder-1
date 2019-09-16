//简答的热身题
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[101];
    while (scanf("%s",s)!=EOF)
    {
        map<char,int> mp;
        int max = 0;
        for(int i=0;i<strlen(s);i++)
        {
            max = (max > ++mp[s[i]])? max: mp[s[i]];
        }
        char temp[11]={'0','1','2','3','4','5','6','7','8','9'};
        while (max)
        {   
            for(int i=0;i<10;i++)
            {
                if (mp[temp[i]] == max)
                { 
                    printf("*");
                    mp[temp[i]]--;
                }
                else printf(" ");   
            }
            max--;
            printf("\n");
        }
        printf("0123456789\n");
    }
    



    return 0;
}