#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};
Node *head;

Node* create_node(int value, Node *next)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Error!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = next;
    return newNode;
}

Node* insert_at_first(Node *headRef, int value)
{
    Node *newNode = create_node(value, headRef);
    return newNode;
}

Node* insert_at_end(Node *headRef, int value)
{
    Node *newNode = create_node(value, NULL);
    Node *current = headRef;
    if(current == NULL)
    {
        return newNode;
    }
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return headRef;
}

Node* insert_at_position(Node *headRef, int pos, int value)
{
    Node *newNode = create_node(value, NULL);
    Node *temp1 = headRef;
    if(temp1 == NULL)
    {
        return newNode;
    }
    if(pos == 1)
    {
        newNode->next = headRef;
        return newNode;
    }
    for(int i = 1; i <= pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = newNode;
    newNode->next = temp2;
    return headRef;
}

Node* sorted_insert(Node *headRef, int value)
{
    Node *newNode = create_node(value, NULL);
    Node *current = headRef, *prev = NULL;

    if(current == NULL)
        return newNode;
    while(current != NULL)
    {
        if(current->data < value)
        {
            prev = current;
            current = current->next;
        }
        else
            break;
    }
    if(prev == NULL)
    {
        newNode->next = headRef;
        return newNode;
    }
    else
    {
        newNode->next = prev->next;
        prev->next = newNode;
        return headRef;
    }
}

Node* delete_first(Node *headRef)
{
    Node *temp = headRef;
    if(temp != NULL)
    {
        headRef = headRef->next;
        free(temp);
    }
    return headRef;
}

Node* delete_last(Node *headRef)
{
    Node *current = headRef, *prev = NULL;
    if(current != NULL)
    {
        if(current->next == NULL)
        {
            headRef = NULL;
            return headRef;
        }
        while(current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
        prev->next = NULL;
        free(current);
    }
    return headRef;
}

Node* delete_data(Node *headRef, int value)
{
    Node *current = headRef, *prev = NULL;

    if(current != NULL && current->data == value)
    {
        headRef = current->next;
        free(current);
        return headRef;
    }
    while(current != NULL)
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
    return headRef;
}

Node* delete_at_position(Node *headRef, int pos)
{
    Node *temp1 = headRef;
    if(pos == 1)
    {
        headRef = temp1->next;
        free(temp1);
        return headRef;
    }
    for(int i = 1; i <= pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return headRef;
}

void search_data(Node *headRef, int value)
{
    Node *temp = headRef;
    //int _count = 0;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            //_count++;
            printf("Value found.\n");
            return;
        }
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Value not found.\n");
    }
    /*
    if(_count == 0)
    {
        printf("Value not found.\n");
    }
    else
    {
        printf("%d found %d times.\n", value, _count);
    }
    */
}

Node *search_data_recursive(Node *headRef, int value)
{
    if(headRef == NULL)
    {
        return headRef;
    }
    else
    {
        if(headRef->data == value)
        {
            return headRef;
        }
        search_data_recursive(headRef->next, value);
    }
}

int number_of_elements(Node *headRef)
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

void print_list(Node *headRef)
{
    Node *temp = headRef;
    printf("List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_list_reverse(Node *headRef)
{
    if(headRef != NULL)
    {
        print_list_reverse(headRef->next);
        printf("%d ", headRef->data);
    }
}

Node* reverse_list(Node *headRef)
{
    Node *prev = headRef, *current = NULL;

    if(prev != NULL)
    {
        while(prev->next != NULL)
        {
            current = prev->next;
            prev->next = current->next;
            current->next = headRef;
            headRef = current;
        }
    }
    return headRef;
}

Node* sort_list(Node* headRef)
{
    Node* sortedHead = NULL;
    Node* current = headRef;
    while(current != NULL)
    {
        sortedHead = sorted_insert(sortedHead, current->data);
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return sortedHead;
}

int main()
{
    head = NULL;
    int x, value, pos;

    while(1)
    {
        printf("\n1.Insert at first\n2.Insert at end\n3.Print list\n4.Print list reversely\n5.Number of elements in the list\n");
        printf("6.Search a value\n7.Search a value recursively\n8.Reverse list\n9.Delete first\n10.Delete last\n");
        printf("11.Delete value\n12.Delete at position\n13.Insert at position\n14.Sorted insert\n15.Sort List\n16.Exit\n\n");
        scanf("%d",&x);

        switch(x)
        {
        case 1:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            head = insert_at_first(head, value);
            print_list(head);
            break;

        case 2:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            head = insert_at_end(head, value);
            print_list(head);
            break;

        case 3:
            print_list(head);
            break;

        case 4:
            printf("List: ");
            print_list_reverse(head);
            printf("\n");
            break;

        case 5:
            printf("Number of elements in the list = %d\n", number_of_elements(head));
            break;

        case 6:
            printf("Enter a value to search:\n");
            scanf("%d", &value);
            search_data(head, value);
            break;

        case 7:
            printf("Enter a value to search:\n");
            scanf("%d", &value);
            if(search_data_recursive(head, value) != NULL)
                printf("Value found.\n");
            else
                printf("Value not found.\n");
            break;

        case 8:
            head = reverse_list(head);
            printf("List reversed!\n");
            break;

        case 9:
            head = delete_first(head);
            print_list(head);
            break;

        case 10:
            head = delete_last(head);
            print_list(head);
            break;

        case 11:
            printf("Enter a value to delete:\n");
            scanf("%d", &value);
            head = delete_data(head, value);
            print_list(head);
            break;

        case 12:
            printf("Enter a position to delete:\n");
            scanf("%d", &pos);
            if(pos >= 1 && pos <= number_of_elements(head))
            {
                head = delete_at_position(head, pos);
                print_list(head);
            }
            else
                printf("Invalid position.\n");
            break;

        case 13:
            printf("Enter a position to insert:\n");
            scanf("%d", &pos);
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            if(pos >= 1 && pos <= number_of_elements(head))
            {
                head = insert_at_position(head, pos, value);
                print_list(head);
            }
            else
                printf("Invalid position.\n");
            break;

        case 14:
            printf("Enter a value to insert:\n");
            scanf("%d", &value);
            head = sorted_insert(head, value);
            print_list(head);
            break;

        case 15:
            head = sort_list(head);
            printf("List Sorted.\n");
            print_list(head);
            break;

        case 16:
            exit(0);

        default:
            printf("Wrong Input. Try again!\n");
        }
    }

    return 0;
}
