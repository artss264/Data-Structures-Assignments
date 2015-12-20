#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<limits.h>


typedef struct node
{
    int edgeweight;
//    int totalweight;
    int data;
    struct node* next;
}node;
int visited[100010],inheap[100010],minheapend=0,totalweight[100010];
node *arr[100010],*minheap[100010];
void adjlist(int i,int j,int w)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->edgeweight=w;
 //   new_node->totalweight=INT_MAX;
    new_node->next=NULL;
    if(arr[i]==NULL)
    {
        arr[i]=new_node;
    }
    else
    {
        temp=arr[i];
        arr[i]=new_node;
        new_node->next=temp;
    }
}
void minheapins(long long int index)
{
        printf("no of insertinpin - %lld\n",index);
    long long int w;
    void *temp;
    minheapend++;
    minheap[minheapend]=arr[index];
    w=minheapend;
    while(w/2>=1)
    {
//        printf("A - %lld\n",w);
 //       printf("A=%d, B=\n",(*(minheap[w])).data);
        //minheap[w/2]->data);
        if(totalweight[minheap[w]->data]<totalweight[minheap[w/2]->data])
        {
            temp=minheap[w];
            minheap[w]=minheap[w/2];
            minheap[w/2]=temp;
            w=w/2;
        }
        else
            break;
    }
}
long long int minheapdel()
{
    long long int l;
  //  if(minheap[1]!=NULL && minheapend>=1)
    l=minheap[1]->data;
    node *temp;
    long long int min,left,right,index;
    minheap[1]=minheap[minheapend];
    minheapend--;
    long long int u=1;
    while(2*u<=minheapend)
    {
        left=2*u;
        right=left+1;
        min=totalweight[minheap[left]->data];
        index=left;
        if(right<=minheapend)
        {
            if(totalweight[minheap[right]->data]<min)
            {
                min=totalweight[minheap[right]->data];
                index=right;
            }
        }
        if(totalweight[minheap[u]->data]>totalweight[minheap[index]->data])
        {
            temp=minheap[u];
            minheap[u]=minheap[index];
            minheap[index]=temp;
            u=index;
        }
        else
            break;
    }
    return l;
}
void minheapdelany(long long int indexo)
{
    long long int tempindex,index,left,right,minim,i;
    node* temp;
    for(i=1;i<=minheapend;i++)
    {
        if(minheap[i]->data==indexo)
            tempindex=i;
    }
  //  minheap[tempindex]->totalweight=minheap[minheapend]->totalweight;
 //   minheapend--;
   // if(minheap[tempindex]->totalweight<minheap[tempindex/2]->totalweight)
//    {
      
        while(tempindex/2>=1)
        {
            if(totalweight[tempindex]<totalweight[minheap[tempindex/2]->data])
            {
                temp=minheap[tempindex];
                minheap[tempindex]=minheap[tempindex/2];
                minheap[tempindex/2]=temp;
                tempindex=tempindex/2;
            }
            else
                break;
        }
    }
 /*   else
    {
        while(2*tempindex<=minheapend)
        {
            left=2*tempindex;
            right=left+1;
            minim=minheap[left]->totalweight;
            index=left;
            if(right<=minheapend)
            {
                if(minheap[right]->totalweight<minim)
                {
                    minim=minheap[right]->totalweight;
                    index=right;
                }
            }
            if(minheap[tempindex]->totalweight>minheap[index]->totalweight)
            {
                temp=minheap[tempindex];
                minheap[tempindex]=minheap[index];
                minheap[index]=temp;
                tempindex=index;
            }
            else
                break;


        }


    }
}
*/
long long int min(long long int a,long long int b)
{
    if(a<b)
        return a;
    else
        return b;
}
long long int dijkstra(int source, int des)
{
    int currentnodeindex,current;
    if(source==des)
        return totalweight[source];
    // visited[source]=1;
    node *temp;
    current=source;
    printf("aa\n");
//    int currento=source;
    temp=arr[current];
    //   current=source;
    int minimumlocal=0,newwtt;
    int f;
//    f=0;
    while(temp!=NULL && visited[temp->data]!=1)
    {
      //  f=1;
        printf("aaa\n");
        newwtt=min(totalweight[current]+temp->edgeweight,totalweight[temp->data]);
        printf("aaaa\n");
        printf("TEMP -> data = %d\n",temp->data);
        if(newwtt<totalweight[temp->data] && inheap[temp->data]==1)
        { 
            printf("aaaaa\n");
            totalweight[temp->data]=newwtt;
            minheapdelany(temp->data);
            printf("aaaaaa\n");
          //  temp->totalweight=newwtt;
        //    minheapins(temp->data);
            //  inheap[temp->data]=1;
            
        }
        else if(newwtt<totalweight[temp->data] && inheap[temp->data]!=1)
        {
                printf("AAAsdfggg\n");
            totalweight[temp->data]=newwtt;
                printf("1AAAsdfggg\n");
            minheapins(temp->data);
                printf("2AAAsdfggg\n");
            inheap[temp->data]=1;
                printf("3AAAsdfggg\n");
        }
        //  if(minimumlocal>(temp->totalweight))
        // { 
        // minimumlocal=temp->totalweight;
        //   nextbest=temp->data;
        // }
        printf("sdfggg\n");
        temp=temp->next;
    }
    if(minheapend<1)
        return -1;
    visited[source]=1;
//    if(minheapend>=0)
    currentnodeindex=minheapdel();
    inheap[currentnodeindex]=0;

    printf("dfhjf\n");
    return dijkstra(currentnodeindex,des);
}



int main()
{
    int N,M,u,v,w,i,j,k,l,T,S;
    long long int shortd,p;
    scanf("%d",&N);
    for(i=0;i<=N;i++)
    {
        visited[i]=0;
        inheap[i]=0;
    }
    shortd=0;
    for(i=0;i<=N;i++)
        totalweight[i]=INT_MAX;
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adjlist(u,v,w);
    }
    scanf("%d %d",&S,&T);
    totalweight[S]=0;
    arr[S]->edgeweight=0;
    printf("bghgfhgh\n");
    shortd=dijkstra(S,T);
    if(shortd==-1)
        printf("NO\n");
    else
        printf("%lld\n",shortd);

    return 0;
}
