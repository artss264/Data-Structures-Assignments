#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct bag
{
    int n;
    int arr[1000000];
    int sum;
    struct bag *next;
}bag;
int main()
{
    int N,i;
    bag *p1,*p2, *head;
    while(N--)
    {
        
        head->next=new_node;
        bag* new_node = (struct bag*) malloc(sizeof(struct bag));
        sum=0;
        scanf("%d",&m);
        new_node->n=m;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            sum=sum+arr[i];
            sum=sum%MOD;
        }
        new_node->sum=sum;
        new_node->next=NULL;
        p1->next=new_node;
        p1->next->next=p2;
        if(p1->sum<=new_node->sum && new_node->sum<p2->sum)
        {
            p1->next->next=new_node;
            new_node->next=p2;
        }

    }
    t1=head;    
    while(t1->next!=NULL)
    {
        printf("%d\n",t1->n);
        for(i=0;i<t1->n;i++)
            printf("%d\n",arr[i]);
        t1=t1->next;;
    }

    return 0;
}
