#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};
Node *head, *tail;

Node* CreateNode(int value, Node* prev, Node* next)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = prev;
    newNode->next = next;
    return newNode;
}

void InsertAtFirst(Node **headRef, Node **tailRef, int value)
{
    Node *newNode = CreateNode(value, NULL, NULL);
    Node *current = *headRef;

    if(*headRef == NULL)
    {
        *headRef = newNode;
        *tailRef = newNode;
        return;
    }
    newNode->next = *headRef;
    (*headRef)->prev = newNode;
    *headRef = newNode;
}

void DeleteAtPosition(Node **headRef, Node **tailRef, int pos)
{

}

void PrintList(Node **headRef)
{
    Node *temp = *headRef;
    printf("List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrintList(Node **tailRef)
{
    Node *temp = *tailRef;
    printf("Reverse List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    int x, value, pos;

    while(1)
    {
        printf("\n1.Insert at first\n2.Insert at end\n3.Print list\n4.Reverse print list\n4.Number of nodes in the list\n");
        printf("5.Search a value\n6.Delete first\n7.Delete last\n8.Delete value\n");
        printf("9.Delete at position\n10.Insert at position\n11.Sorted insert\n12.Exit\n\n");
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            InsertAtFirst(&head, &tail, value);
            PrintList(&head);
            break;

//        case 2:
//            printf("Enter a value to insert:\n");
//            scanf("%d", &value);
//            head = InsertAtEnd(head, value);
//            PrintList(head);
//            break;
//
        case 3:
            PrintList(&head);
            break;

        case 4:
            ReversePrintList(&tail);
            break;
//
//        case 4:
//            printf("Number of Nodes in the list = %d\n", NumberOfNodes(head));
//            break;
//
//        case 5:
//            printf("Enter a value to search:\n");
//            scanf("%d", &value);
//            search_data(head, value);
//            break;
//
//        case 6:
//            head = DeleteFirst(head);
//            PrintList(head);
//            break;
//
//        case 7:
//            head = DeleteLast(head);
//            PrintList(head);
//            break;
//
//        case 8:
//            printf("Enter a value to delete:\n");
//            scanf("%d", &value);
//            head = DeleteValue(head, value);
//            PrintList(head);
//            break;
//
//        case 9:
//            printf("Enter a position to delete:\n");
//            scanf("%d", &pos);
//            if(pos >= 1 && pos <= NumberOfNodes(head))
//            {
//                head = DeleteAtPosition(head, pos);
//                PrintList(head);
//            }
//            else
//                printf("Invalid position.\n");
//            break;
//
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
