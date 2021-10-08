#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    char data;
    Node *next;
};
Node *head;

Node* CreateNode(char value, Node *next)
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

void Push(Node **headRef, char value)
{
    Node *newNode = CreateNode(value, *headRef);
    *headRef = newNode;
}

char Pop(Node **headRef)
{
    if(!isEmpty(*headRef))
    {
        char value = (*headRef)->data;
        Node *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return value;
    }
    return '\0';
}

char Top(Node *headRef)
{
    return headRef->data;
}

bool isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int Precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

char* InfixToPostfix(char* infixExp)
{
    char *postExp = (char*)malloc(1000);
    int k = 0;

    for(int i = 0; infixExp[i] != '\0'; i++)
    {
        if(isOperand(infixExp[i]))
            postExp[k++] = infixExp[i];
        else if(infixExp[i] == '(')
            Push(&head, infixExp[i]);
        else if(infixExp[i] == ')')
        {
            while(!isEmpty(head) && Top(head) != '(')
                postExp[k++] = Pop(&head);

            Pop(&head);
        }
        else
        {
            while(!isEmpty(head) && Precedence(infixExp[i]) <= Precedence(Top(head)))
                postExp[k++] = Pop(&head);

            Push(&head, infixExp[i]);
        }
    }

    while(!isEmpty(head))
        postExp[k++] = Pop(&head);

    postExp[k++] = '\0';
    return postExp;
}

int main()
{
    head = NULL;

    char infixExp[] = "5+4*(2^1-2)^(3+4*1)-1";

    printf("Infix Expression: %s\n", infixExp);
    printf("Postfix Expression: %s\n", InfixToPostfix(infixExp));

    return 0;
}
