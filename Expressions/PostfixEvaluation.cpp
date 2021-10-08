#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int INT;
typedef struct node Node;

struct node
{
    INT data;
    Node *next;
};
Node *head;

Node* CreateNode(INT value, Node *next)
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

void Push(Node **headRef, INT value)
{
    Node *newNode = CreateNode(value, *headRef);
    *headRef = newNode;
}

INT Pop(Node **headRef)
{
    if(!isEmpty(*headRef))
    {
        INT value = (*headRef)->data;
        Node *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return value;
    }
    return -1;
}

INT Power(INT x, INT n)
{
    INT result = 1;
    while(n != 0)
    {
        result *= x;
        n--;
    }
    return result;
}

INT PostfixEvaluation(char* postExp)
{
    for(int i = 0; postExp[i] != '\0'; i++)
    {
        if(postExp[i] >= '0' && postExp[i] <= '9')
        {
            Push(&head, postExp[i] - '0');
        }
        else
        {
            INT operand2 = Pop(&head);
            INT operand1 = Pop(&head);

            switch(postExp[i])
            {
                case '+': Push(&head, operand1 + operand2);
                break;
                case '-': Push(&head, operand1 - operand2);
                break;
                case '*': Push(&head, operand1 * operand2);
                break;
                case '/': Push(&head, operand1 / operand2);
                break;
                case '^': Push(&head, Power(operand1, operand2));
                break;
            }
        }
    }
    return Pop(&head);
}

int main()
{
    head = NULL;

    char postExp[] = "231*+4^";

    printf("Postfix Expression: %s\n", postExp);
    printf("Postfix Evaluation: %lld\n", PostfixEvaluation(postExp));

    return 0;
}
