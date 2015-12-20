#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char arr[10000][100],p,q;
    int i,j,k,m,l,first,last,N,n,z;
    int appendpointr,count=0;
    scanf("%d",&N);
    scanf("%c",&p);
    appendpointr=0;
    int noelinb=0;
    while(p!='Q')
    {
        if(p=='A')
        {
            scanf("%d",&n);
            count=count+n;
            if(count>N)
                count=N;
            for(i=appendpointr;i<appendpointr+n;i++)
            {
                if(i==N)
                    i=0;
                scanf("%s",arr[i]);
            }
            if(i>N-1)
                i=0;
            appendpointr=i;
            noelinb=noelinb+appendpointr;
            if(noelinb>N)
                noelinb=N;
        }

        else if(p=='R')
        {
            scanf("%d",&n);
           // k=appendpointr-n;
            count=count-n;
           // if(k<0)
             //   k= noelinb+k;
            int as=0;
            while(1)
            {
                if(as>=n)
                    break;
                k--;
                if(k<0)
                    k=N-1;
                as++;
            }
printf("k:%d,ptr:%d\n",k,appendpointr);


        }
        else if(p=='L')
        {
            if(count<N)
            {
                for(i=k;i<appendpointr;i++)
                {
                    if(i==N)
                        i=0;
                    printf("%s",arr[i]);
                }
            }
            else
            {
                int r=k;int w=0; 
                while(1)
                {
                    if(w>=N)
                        break;
                    printf("%s",arr[r]);
                    w++;
                    r++;
                    if(r>N-1)
                        r=0;
                }
            }
        }
        scanf("%c",&p);
    }
    return 0;
}
