#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
            while(!isEmpty(head) && ((Precedence(infixExp[i]) < Precedence(Top(head))) || ((Precedence(infixExp[i]) <= Precedence(Top(head))) && infixExp[i] == '^')))
                postExp[k++] = Pop(&head);

            Push(&head, infixExp[i]);
        }
    }

    while(!isEmpty(head))
        postExp[k++] = Pop(&head);

    postExp[k++] = '\0';
    return postExp;
}

char* InfixToPrefix(char* infixExp)
{
    char* preExp = strrev(infixExp);

    for(int i = 0; preExp[i] != '\0'; i++)
    {
        if(preExp[i] == '(')
        {
            preExp[i] = ')';
            i++;
        }
        else if(preExp[i] == ')')
        {
            preExp[i] = '(';
            i++;
        }
    }

    preExp = InfixToPostfix(preExp);

    preExp = strrev(preExp);

    return preExp;
}

int main()
{
    head = NULL;

    char infixExp[] = "(P+(Q*R)/(S-T))";

    printf("Infix Expression: %s\n", infixExp);
    printf("Prefix Expression: %s\n", InfixToPrefix(infixExp));

    return 0;
}

