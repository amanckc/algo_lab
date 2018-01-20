#include <stdio.h>
#include <stdlib.h>


typedef struct listnode
{
    int dest;
    struct listnode* next;
}listnode;


typedef struct list
{
    struct listnode *head;
}list;

typedef struct Graph
{
    int V;
    struct list* array;
}Graph;


struct listnode* newlistnode(int dest)
{
    struct listnode* newNode =
            (struct listnode*) malloc(sizeof(struct listnode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct list*) malloc(V * sizeof(struct list));


    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}


void addedge(struct Graph* graph, int src, int dest)
{

    struct listnode* newNode = newlistnode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;


    newNode = newlistnode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void printlist(struct Graph* graph)
{
    int v;listnode* pCrawl;
    //printf("%d",graph->V);
    for (v = 0; v < (graph->V); v++)
    {
    
        pCrawl = graph->array[v].head;
        
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
      printf("\n");
    }

}


int main()
{
    printf("Enter the number of vertices");	
    int n,i,j,ch,s,d;
    listnode* temp;
    int mat[20][20]={0};

    scanf("%d",&n);
    struct Graph* g= createGraph(n);
    while(1)
	{
	printf("Press one for adding an edge");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter source vertex");
        scanf("%d",&s);
        printf("Enter destination vertex");
        scanf("%d",&d);
        addedge(g,s,d);
        mat[s][d]=1;
        mat[d][s]=1;
    }
    else break;
    }
    printf("Adjacency list is as follows\n");
    printlist(g);
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d",mat[i][j]);
        printf("\n");
    }
     return 0;
    
}