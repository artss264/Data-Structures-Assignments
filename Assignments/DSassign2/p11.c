#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{

    int arr[100000],p,q,i,j,k,n;
    long long int max;
    scanf("%d",&n);
    
    while(n!=0)
    {
        max=0;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        for(i=0;i<n;i++)
        { 
            p=0;q=0;
            for(j=i+1;j<n;j++)
            {
                if(arr[i]<=arr[j])
                    p++;
                else
                    break;
            }
            for(j=i;j>=0;j--)
            {
                if(arr[i]<=arr[j])
                    q++;
                else
                    break;
            }
            if((p+q)*arr[i]>=max)
                max=(p+q)*arr[i];
        }
        printf("%lld\n",max);
        scanf("%d",&n);
    }


    return 0;
}
