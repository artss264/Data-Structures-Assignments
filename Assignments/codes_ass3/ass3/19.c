#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main()
{
    long long int T,i,j,k,m,n,num,f,p;
    char str[100000][11],a,b,c,swap[11];
    scanf("%lld",&T);
    while(T--)
    {
        p=0;
        scanf("%lld",&num);
        for(i=0;i<num;i++)
        {
            scanf("%s",str[i]);
        }
        for(i=0;i<(num-1);i++)
        {
            for(j=0;j<num-i-1;j++)
            {
                if(strcmp(str[j],str[j+1])>0) 
                {
                    strcpy(swap,str[j]);
                    strcpy(str[j],str[j+1]);
                    strcpy(str[j+1],swap);
                }
            }
        }
        for(i=0;i<num-1;i++)
        {
            f=0;
            k=strlen(str[i]);
            /*            for(j=0;j<k;j++)
                          {
                          if(str[i][j]!=str[i+1][j])
                          {

                          f=1;
                          break;
                          }
                          }
                          if(f!=1)
                          {
                          printf("NO\n");
                          p=1;
                          break;
                          }*/
            if(strncmp(str[i],str[i+1],k)==0)
            {
                printf("NO\n");
                p=1;
                break;
            }

        }
        if(p!=1)
            printf("YES\n");
        //        for(i=0;i<num;i++)
        //            printf("%s\n",str[i]);
    }

    return 0;
}
