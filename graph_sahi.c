#include <stdio.h>
#include <stdlib.h>
 
#define N 9
typedef struct Graph
{
    struct Node* head[N];
}Graph;
 
typedef struct Node
{
    int dest;
    struct Node* next;
}Node;
 
typedef struct Edge {
    int src, dest;
}Edge;
 
Graph* createGraph(Edge edges[], int n)
{
    Graph* graph = (Graph*)malloc(sizeof(Graph));
 
    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
 
    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
 
        Node* newNode = (Node*)malloc(sizeof(Node)); 
        newNode->dest = dest;

        if(graph->head[src]==NULL)
        {
            graph->head[src] = newNode;
        }
        else
        {
            Node* temp = graph->head[src];
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
 
    return graph;
}
 
void printGraph(Graph* graph)
{
    for (int i = 0; i < N; i++)
    {
        Node* ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    Edge edges[] =
    {
        {0, 2}, {0, 4}, {1, 1}, {1, 2}, {1, 5}, {2, 5}, {2, 7}, {3, 6}, {4, 8}
    };
 
    int n = sizeof(edges)/sizeof(edges[0]);
 
    Graph *graph = createGraph(edges, n);
    printGraph(graph);
    
    return 0;
}