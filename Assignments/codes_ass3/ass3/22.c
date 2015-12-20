#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int f[200001];
int cmpfunc (const void * m, const void * n)
{
       return ( *(int*)m - *(int*)n );
}

long long int median(long long int i)
{
    qsort(f,i+1,sizeof(long long int),cmpfunc);
    return f[(i/2)+1];
}
    

int main()
{
    long long int T,a,b,c,sum,n,m[200001],i,j,k,l;
    scanf("%lld",&T);
    while(T--)
    {
        f[0]=0;
        f[1]=1;
        sum=f[1];
        scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
        for(i=2;i<=n;i++)
        {
            m[i]=median(i-1);
            f[i]=(a*m[i]+b*i+c)%1000000007;
            sum=sum+f[i];
        }
        printf("%lld\n",sum);
    }
return 0;
}
