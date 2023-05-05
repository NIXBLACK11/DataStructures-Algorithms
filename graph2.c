#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int vertex;
    struct Node* next;
}Node;

typedef struct Graph{
    int numVertices;
    struct Node ** adjLists;
}Graph;

Node* createNode(int v)
{
    Node *node;
    node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

Graph* createGraph(int vertices)
{
    Graph *graph;
    graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Graph*));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph,int s,int d)
{
    Node * node = createNode(d);
    node->next = graph->adjLists[s];
    graph->adjLists[s] = node;
    node = createNode(s);
    node->next = graph->adjLists[d];
    graph->adjLists[d] = node;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node * temp = graph->adjLists[i];
        printf("\n Vertex %d :  ",i);
        while(temp)
        {
            printf("%d ->",temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph* graph = createGraph(6);
    //{0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,2,1);
    addEdge(graph,3,2);
    addEdge(graph,4,5);
    addEdge(graph,5,4);
    printGraph(graph);
    return 0;
}