#include<stdio.h>
#define capacity 1000

int stack_arr[capacity];
int top = -1;

bool isEmpty()
{
    if(top == -1)
        return true;
    return false;
}

int Size()
{
    return top + 1;
}

void push(int value)
{
    if(top + 1 < capacity)
    {
        stack_arr[++top] = value;
        printf("%d pushed to stack\n", value);
    }
    else
        printf("Stack is full!\n");
}

int pop()
{
    if(!isEmpty())
        return stack_arr[top--];
    return -1;
}

int main()
{
    push(5);
    push(8);
    push(3);

    printf("Stack size = %d\n", Size());

    while(!isEmpty())
        printf("%d popped from stack\n", pop());

    return 0;
}
