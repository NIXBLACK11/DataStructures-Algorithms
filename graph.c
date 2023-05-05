#include<stdio.h>
#include<stdlib.h>

typedef struct Edge{
    int info;
    struct Edge *next;
}Edge;

typedef struct Vertex{
    struct Edge* next;
}Vertex;

void addEdge(Vertex vertex[], int v, int e)
{
    Edge *edge = (Edge*)malloc(sizeof(Edge));
    edge->info = e;
    edge->next = NULL;
    if(vertex[v].next == NULL)
    {
        vertex[v].next = edge;
    }
    else
    {
        Edge *temp = vertex[v].next;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = edge;
    }
}

void printGraph(Vertex vertex[],int n)
{
    for(int i=0;i<n;i++)
    {
        Edge *temp = vertex[i].next;
        printf("%d",i);
        while(temp!=NULL)
        {
            printf(" -> %d",temp->info);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    Vertex vertex[4];
    for (int i = 0; i < 4; i++)
    {
        vertex[i].next = NULL;
    }
    
    int v=0, e=0;
    for(int i=0;i<6;i++)
    {
        scanf("%d",&v);
        scanf("%d",&e);
        addEdge(vertex, v, e);
    }
    printGraph(vertex,4);
}