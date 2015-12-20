#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    int T,n,k,p,q,r,i,j,a[10001],min;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=0;
        p=n-k+1;
        for(i=1;i<=p;i++)
        {
            min=1000000000;
            q=i+k-1;
            if(q==0)
                printf("%d",a[i]);
            else
            {
            for(j=i;j<=q;j++)
            {
                if(a[j]<min)
                    min=a[j];
            }
                printf("%d",min);
            }
                if(i==p)
                    break;
                else
                    printf(" ");
        }
        printf("\n");
    }
    
 

return 0;
}
