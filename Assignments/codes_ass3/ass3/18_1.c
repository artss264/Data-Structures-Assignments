#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
int visited[1010],count;
node *arr[1010];
void adjlist(int i,int j)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->next=NULL;

    if(arr[i]->next==NULL)
    {
        arr[i]->next=new_node;
    }
    else
    {
        temp=arr[i]->next;
        arr[i]->next=new_node;
        new_node->next=temp;
    }
}
void dfs(int vertex)
{
    count++;
    visited[vertex]=1;
    node *temp;//=(node*)malloc(sizeof(node));
    temp=arr[vertex];
    printf("%d ",temp->data);
    while(temp!=NULL)
    {
        if(visited[temp->data]!=1)
        {
            dfs(temp->data);
        }
        temp=temp->next;
    }
    return ;
}


int main()
{
    int T,n,nofwar,a,b,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        int p=0;
        count=0;
        node *temp=(node*)malloc(sizeof(node));
        temp->next=NULL;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            visited[i]=0;
            arr[i]=malloc(sizeof(node));
            arr[i]->data=i;
            arr[i]->next=NULL;
        }
       // for(i=0;i<=n;i++)
         //   arr[i]=NULL;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&nofwar);
            for(j=0;j<nofwar;j++)
            {
                scanf("%d",&a);
                adjlist(i,a);
            }
        }
        for(i=1;i<=n;i++)
        {
            count=0;
            dfs(i);
            if(count==n)
                p++;
        }
/*        for(i=1;i<=n;i++)    //printing the adjacency list
        {
            temp->next=arr[i];
//            printf("%d-->",i);
            while(temp->next!=NULL)
            {
                printf("%d ",temp->next->data);
                temp=temp->next;
            }
            printf("\n");
        }*/
        printf("%d\n",p);
    }
    return 0;
}
