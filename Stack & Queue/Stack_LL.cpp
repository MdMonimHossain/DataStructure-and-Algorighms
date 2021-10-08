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

void Push(Node **headRef, int value)
{
    Node *newNode = CreateNode(value, *headRef);
    *headRef = newNode;
    printf("%d pushed to stack\n", value);
}

int Pop(Node **headRef)
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

    Push(&head, 5);
    Push(&head, 8);
    Push(&head, 3);

    printf("Stack size = %d\n", Size(head));

    while(!isEmpty(head))
        printf("%d popped from stack\n", Pop(&head));

    return 0;
}
