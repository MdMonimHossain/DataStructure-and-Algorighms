#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int n;
    char from, aux, to;
    Node *next;
};
Node *head;

Node* CreateNode(int n, char from, char aux, char to, Node *next)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->n = n;
    newNode->from = from;
    newNode->aux = aux;
    newNode->to = to;
    newNode->next = next;
    return newNode;
}

bool isEmpty(Node *headRef)
{
    if(headRef == NULL)
        return true;
    return false;
}

void Push(Node **headRef, int n, char from, char aux, char to)
{
    Node *newNode = CreateNode(n, from, aux, to, *headRef);
    *headRef = newNode;
}

Node* Pop(Node **headRef)
{
    Node *tower = CreateNode((*headRef)->n, (*headRef)->from, (*headRef)->aux, (*headRef)->to, NULL);
    Node *temp = *headRef;
    *headRef = (*headRef)->next;
    free(temp);
    return tower;
}

void Tower(int n, char from, char aux, char to)
{
    Push(&head, n, from, aux, to);

    while(!isEmpty(head))
    {
        Node *tower = Pop(&head);
        n = tower->n;
        from = tower->from;
        aux = tower->aux;
        to = tower->to;
        free(tower);

        if(n == 1)
            printf("Move disc from %c to %c\n", from, to);
        else
        {
            Push(&head, n - 1, aux, from, to);
            Push(&head, 1, from, aux, to);
            Push(&head, n - 1, from, to, aux);
        }
    }
}

int main()
{
    head = NULL;

    Tower(3, 'A', 'B', 'C');

    return 0;
}

