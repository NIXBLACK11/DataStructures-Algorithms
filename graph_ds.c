#include<stdio.h>
#include<stdlib.h>
#define N 9

typedef struct Edge{
    int src, dest;
}Edge;

typedef struct Node{
    int dest;
    struct Node *next;
}Node;

typedef struct Graph{
    struct Node *head[N];
    int visited[N];
}Graph;

Graph *createGraph(Edge edges[], int n)
{
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < N; i++)
    {
        graph->head[i] = NULL;
    }
    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->dest = dest;
        if (graph->head[src] == NULL)
        {
            graph->head[src] = newNode;
        }
        else
        {
            Node *temp = graph->head[src];
            while (temp->next!=NULL)
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
        Node *ptr = graph->head[i];
        while(ptr != NULL)
        {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
    
}

typedef struct node{
    int info;
    struct node* next;
}node;

node * insert(node *rear)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->next = NULL;
    printf("\nEnter the value:");
    scanf("%d",&(p->info));
    if(rear==NULL)
    {
        rear = p;
    }
    else
    {
        rear->next = p;
        rear = p;
    }
    return rear;
}

node * delete(node * front)
{
    if(front == NULL)
    {
        printf("\nempty");
    }
    else
    {
        node *temp = front;
        front = front->next;
        free(temp);
    }
    return front;
}

void display(node *front)
{
    if(front==NULL)
    {
        printf("\nempty");
    }
    else
    {
        while(front!=NULL)
        {
            printf("%d,",front->info);
            front = front->next;
        }
    }
}

BFS(Graph *graph)
{
    graph->visited[vertex] = 1;
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

    for(int i=0;i<N;i++)
    {
        graph->visited[i] = 0;
    }
}