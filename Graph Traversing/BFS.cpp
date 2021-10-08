#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};
Node *head;

Node* CreateNode(int value, Node *next)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = next;
    return newNode;
}

bool isEmpty(Node *headRef)
{
    if(headRef == NULL)
        return true;
    return false;
}

void Enqueue(Node **headRef, int value)
{
    Node *newNode = CreateNode(value, NULL);
    Node *current = *headRef;
    if(current == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

int Dequeue(Node **headRef)
{
    if(!isEmpty(*headRef))
    {
        int value = (*headRef)->data;
        Node *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return value;
    }
    return -1;
}

int graph[100][100];
int visited[100];
int node, edge, start;

void BFS(int start)
{
    Enqueue(&head, start);
    visited[start] = 1;

    while(!isEmpty(head))
    {
        int frnt = Dequeue(&head);
        printf("%d ", frnt);
        for(int i = 1; i <= node; i++)
        {
            if(graph[frnt][i] == 1 && visited[i] == 0)
            {
                Enqueue(&head, i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    head = NULL;
    printf("Enter no of Node:\n");
    scanf("%d", &node);
    printf("Enter no of Edge:\n");
    scanf("%d", &edge);

    int so, des;
    printf("Enter %d Edges:\n", edge);
    for(int i = 1; i <= edge; i++)
    {
        scanf("%d%d",&so, &des);
        graph[so][des] = 1;
        graph[des][so] = 1;
    }

    printf("Enter Starting Node:\n");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
