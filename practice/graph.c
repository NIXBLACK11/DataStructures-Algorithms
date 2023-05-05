#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct Edge{
    int src;
    int dest;
    int weight;
}Edge;

typedef struct Node{
    int dest;
    int weight;
    struct Node *next;
}Node;

typedef struct Graph{
    struct Node *head[N];
    int visited[N];
    int parent[N];
}Graph;

Graph *createGraph(Edge edges[], int n)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    for(int i=0;i<N;i++)
    {
        graph->head[i] = NULL;
    }
    for(int i=0;i<n;i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->dest = dest;
        newNode->weight = weight;
        if(graph->head[src] == NULL)
        {
            graph->head[src] = newNode;
        }
        else
        {
            Node *temp = graph->head[src];
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return graph;
}

void printGraph(Graph *graph)
{
    for(int i=0;i<N;i++)
    {
        Node *temp = graph->head[i];
        while(temp!=NULL)
        {
            printf("(%d --> %d)",i,temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void graphDFS(Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("\nVisited -- %d",vertex);
    Node *ptr = graph->head[vertex];
    while(ptr!=NULL)
    {
        if(!graph->visited[ptr->dest])
        {
            graphDFS(graph, ptr->dest);
        }
        ptr = ptr->next;
    }
}

void kruskalAlgo(Edge edges[], Graph *graph, int n)
{
    Edge temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if((edges[j].weight) >(edges[j+1].weight))
            {
                temp = edges[j+1];
                edges[j+1] = edges[j];
                edges[j] = temp;
            }
        }
    }
    int mincost = 0;
    int i = 0;
    while(i<N-1)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;
        if(graph->parent[src]!=graph->parent[dest])
        {
            printf("(%d --> %d)",src,dest);
            graph->parent[dest] = graph->parent[src];
            mincost = mincost + weight;
            i++;
        }
    }
    printf("\nMincost is:%d",mincost);
}

int main()
{
    Edge edges[] = {
        {0,2}, {0,4}, {1,2}, {1,5}, {2,5}, {2,7}, {3,6}, {4,8}
    };
    int n = sizeof(edges)/sizeof(edges[0]);
    printf("\nCreating  graph -------");
    Graph *graph = createGraph(edges, n);
    printf("\nPrint graph\n");
    printGraph(graph);
    printf("\nDFS on the graph is---------\n");
    for(int i=0;i<N;i++)
    {
        graph->visited[i] = 0;
    }
    for(int i=0;i<N;i++)
    {
        if(!graph->visited[i])
        {
            graphDFS(graph,i);
        }
    }
    printf("\nKruskal algorithm\n");
    kruskalAlgo(edges, graph, n);
}