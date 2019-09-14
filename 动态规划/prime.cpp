#include <cstdio>
using namespace std;


int prime[200];
int prime_size=0;

void init(){
   //???? 
   bool mark[1000];
   for(int i=0;i<1000;i++) mark[i]=true;
   mark[0]=false;mark[1]=false;
   for(int i=2;i<1000;i++)
   {
      if (mark[i])
      {
         prime[prime_size]=i;
         prime_size+=1;
         for(int j=2*i;j<1000;j+=i) mark[j]=false;
      }
   }
}

int myfunc(int n,int m)
{
   int ans=0;
   int k;
   while (m>=n)
   {
      k=int(m/n);
      ans+=k;
      m=k;
   }
   return ans;
}

int main()
{
   int a,m;
   scanf("%d %d",&m,&a);

   init();
   int prime_a[200][2],prime_a_size=0;
   
   for(int i=0;(i<prime_size) && (prime[i]<=a);i++)
   {  //??a????
      int count=1;
      prime_a[i][1]=0; //???0;
      while(a%prime[i]==0)
      {  
         prime_a[prime_a_size][0]=prime[i];
         prime_a[prime_a_size][1]=count; //count++,?????
         count++;
         a/=prime[i];
      }
      prime_a_size++; 
   }
   int min=1000,k; //?????
   for(int i=0;i<prime_a_size;i++)
   {  
      if (prime_a[i][1]!=0) 
      {
         k=int(myfunc(prime_a[i][0],m)/prime_a[i][1]);
         min= (min>k)?k:min;
      }
   }

   printf("%d",min);

   return 0;
}