#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct Edge{
    int src;
    int dest;
}Edge;

typedef struct Graph{
    int v;
    int visited[N];
    int **Adj;
}Graph;

Graph* createGraph(Edge edges[], int n)
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->v = N;
    graph->Adj = (int **)malloc(graph->v * sizeof(int*));
    for(int i=0;i<graph->v;i++)
    {
        graph->Adj[i] = (int *)malloc(graph->v * sizeof(int));
    }
    for(int i=0;i<graph->v;i++)
    {
        for(int j=0;j<graph->v;j++)
        {
            graph->Adj[i][j] == 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        graph->Adj[src][dest] = 1;
        graph->Adj[dest][src] = 1;
    }
    return graph;
}

void printGraph(Graph *graph)
{
    for(int i=0;i<graph->v;i++)
    {
        for(int j=0;j<graph->v;j++)
        {
            if(graph->Adj[i][j]==1)
            {
                printf("(%d -->  %d)",i,j);
            }
        }
    }
}

void DFS(Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("\n--Visited--%d",vertex);
    for(int i=0;i<graph->v;i++)
    {
        if(!graph->visited[i] && graph->Adj[vertex][i]==1)
        {
            DFS(graph, i);
        }
    }
}

void BFS(Graph *graph, int value)
{
    for(int i=0;i<graph->v;i++)
    {
        graph->visited[i] = 0;
    }
    int queue[N];
    int front = 0, rear = 0;
    queue[rear++] = value;
    graph->visited[value] = 1;
    while(front!=rear)
    {
        value = queue[front++];
        printf("\n--Visited--%d",value);
        for(int i=0;i<graph->v;i++)
        {
            if(!graph->visited[i] && graph->Adj[value][i])
            {
                graph->visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
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
    printf("\nDFS alogorithm");
    for(int i=0;i<graph->v;i++)
    {
        graph->visited[i] = 0;
    }
    for(int i=0;i<graph->v;i++)
    {
        if(!graph->visited[i])
        {
            DFS(graph, i);
        }
    }
    printf("\nBFS algorithm");
    printf("\nEnter the element to start with:");
    int val;
    scanf("%d",&val);
    BFS(graph,val);
}