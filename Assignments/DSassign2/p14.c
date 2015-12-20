#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int post[1000000]={0};
int z=0;
int zz;
void pretopost(int pre[],int l,int m)
{
    int j;
    if(l==m)
    {  
        post[zz]=pre[l];
        zz--;
        return;
    }
    if(l>m||  m<0 )
        return;

    //m--;
post[zz]=pre[l];
zz--;
   // post[m]=pre[l];
    
    for(j=l+1;j<=m;j++)
    {
        if(pre[j]>pre[l])
        {
            break;
        }
    }
  //  if(l+1<=j-1)
   // if(m>0)
    pretopost(pre,j,m); 

    pretopost(pre,l+1,j-1);
    return;
}


int main()
{
    int T,n,pre[1000000],i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        zz=n-1;
        for(i=0;i<n;i++)
            scanf("%d",&pre[i]);


        pretopost(pre,0,n-1);
        for(i=0;i<n;i++)
            printf("%d\n",post[i]);
        printf("\n");
    }

    return 0;
}
