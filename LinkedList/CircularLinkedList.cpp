#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};
Node *head;

Node* CreateNode(int value, Node* next)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = next;
    return newNode;
}

Node* InsertAtFirst(Node* headRef, int value)
{
    Node *newNode = CreateNode(value, headRef);
    Node *current = headRef;

    if(headRef == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    while(current->next != headRef)
    {
        current = current->next;
    }
    current->next = newNode;
    return newNode;
}

Node* InsertAtEnd(Node* headRef, int value)
{
    Node *newNode = CreateNode(value, headRef);
    Node *current = headRef;

    if(headRef == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    while(current->next != headRef)
    {
        current = current->next;
    }
    current->next = newNode;
    return headRef;
}

Node* DeleteFirst(Node* headRef)
{
    Node *current = headRef, *next = NULL;
    if(headRef == NULL)
        return NULL;
    if(current->next == headRef)
        return NULL;
    while(current->next != headRef)
    {
        current = current->next;
        next = current->next;
    }
    current->next = next->next;
    free(next);
    return current->next;
}

Node* DeleteLast(Node* headRef)
{
    Node *current = headRef, *prev = NULL;
    if(headRef == NULL)
        return NULL;
    if(current->next == headRef)
        return NULL;
    while(current->next != headRef)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    return prev->next;
}

Node* DeleteAtPosition(Node* headRef, int pos)
{
    Node *current = headRef;
    if(pos == 1)
    {
        return DeleteFirst(headRef);
    }
    for(int i = 1; i <= pos - 2; i++)
    {
        current = current->next;
    }
    Node *next = current->next;
    current->next = next->next;
    free(next);
    return headRef;
}

Node* DeleteValue(Node* headRef, int value)
{
    Node *current = headRef, *prev = NULL;

    if(headRef == NULL)
    {
        return headRef;
    }
    if(current->data == value)
    {
        return DeleteFirst(headRef);
    }
    if(current->next != headRef)
    {
        while(current->next != headRef)
        {
            prev = current;
            current = current->next;
            if(current->data == value)
            {
                prev->next = current->next;
                free(current);
                return headRef;
            }
        }
    }
    return headRef;
}

int NumberOfNodes(Node* headRef)
{
    Node* temp = headRef;
    int count = 0;

    if(temp != NULL)
    {
        do
        {
            count++;
            temp = temp->next;
        }while(temp != headRef);
    }
    return count;
}

void PrintList(Node* headRef)
{
    Node* temp = headRef;
    printf("List: ");
    if(temp != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != headRef);
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int x, value, pos;

    while(1)
    {
        printf("\n1.Insert at first\n2.Insert at end\n3.Print list\n4.Number of nodes in the list\n");
        printf("5.Search a value\n6.Delete first\n7.Delete last\n8.Delete value\n");
        printf("9.Delete at position\n10.Insert at position\n11.Sorted insert\n12.Exit\n\n");
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            head = InsertAtFirst(head, value);
            PrintList(head);
            break;

        case 2:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            head = InsertAtEnd(head, value);
            PrintList(head);
            break;

        case 3:
            PrintList(head);
            break;

        case 4:
            printf("Number of Nodes in the list = %d\n", NumberOfNodes(head));
            break;

//        case 5:
//            printf("Enter a value to search:\n");
//            scanf("%d", &value);
//            search_data(head, value);
//            break;

        case 6:
            head = DeleteFirst(head);
            PrintList(head);
            break;

        case 7:
            head = DeleteLast(head);
            PrintList(head);
            break;

        case 8:
            printf("Enter a value to delete:\n");
            scanf("%d", &value);
            head = DeleteValue(head, value);
            PrintList(head);
            break;

        case 9:
            printf("Enter a position to delete:\n");
            scanf("%d", &pos);
            if(pos >= 1 && pos <= NumberOfNodes(head))
            {
                head = DeleteAtPosition(head, pos);
                PrintList(head);
            }
            else
                printf("Invalid position.\n");
            break;

//        case 10:
//            printf("Enter a position to insert:\n");
//            scanf("%d", &pos);
//            printf("Enter a value to insert:\n");
//            scanf("%d", &value);
//            if(pos >= 1 && pos <= number_of_elements(head))
//            {
//                head = insert_at_position(head, pos, value);
//                print_list(head);
//            }
//            else
//                printf("Invalid position.\n");
//            break;
//
//        case 11:
//            printf("Enter a value to insert:\n");
//            scanf("%d", &value);
//            head = sorted_insert(head, value);
//            print_list(head);
//            break;

        case 12:
            exit(0);

        default:
            printf("Wrong Input. Try again!\n");
        }
    }

    return 0;
}
