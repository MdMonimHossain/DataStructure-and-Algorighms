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

int Size(Node *headRef)
{
    int _count = 0;
    Node *temp = headRef;
    while(temp != NULL)
    {
        _count++;
        temp = temp->next;
    }
    return _count;
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
    printf("%d enqueued to queue\n", value);
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

int main()
{
    head = NULL;

    Enqueue(&head, 5);
    Enqueue(&head, 8);
    Enqueue(&head, 3);

    printf("Queue size = %d\n", Size(head));

    while(!isEmpty(head))
        printf("%d dequeued from queue\n", Dequeue(&head));

    return 0;
}
