#include <stdio.h>
#include <stdlib.h>

#define N 9
struct Graph
{
    struct Node* head[N];
    int visited[N];
};
 
struct Node
{
    int dest;
    struct Node* next;
};
 
struct Edge {
    int src, dest;
};
 
struct Graph* createGraph(struct Edge edges[], int n)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
 
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
 
    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
 
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
        newNode->dest = dest;

        if(graph->head[src]==NULL)
        {
            graph->head[src] = newNode;
        }
        else
        {
            struct Node* temp = graph->head[src];
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return graph;
}
 
void printGraph(struct Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void DFS(struct Graph *graph, int vertex)
{
    graph->visited[vertex] = 1;
    printf("--Visited %d\n", vertex);
    struct Node *ptr = graph->head[vertex];
    while(ptr!=NULL)
    {
        if(graph->visited == 0)
        {
            DFS(graph, ptr->dest);
        }
        ptr = ptr->next;
    }
}


int main(void)
{
    struct Edge edges[] =
    {
        {0, 2}, {0, 4}, {1, 2}, {1, 5}, {2, 5}, {2, 7}, {3, 6}, {4, 8}
    };
 
    int n = sizeof(edges)/sizeof(edges[0]);
 
    struct Graph *graph = createGraph(edges, n);
 
    printGraph(graph);
    
    //dfs 
    
    for(int i=0;i<N;i++)
    {
        graph->visited[i] = 0;
    }
    int a = 0;
    for(int i=0;i<N;i++)
    {
        if(graph->visited[i]==0)
        {
             DFS(graph, i);
            scanf("%d", &a);
        }
    }
    return 0;
}