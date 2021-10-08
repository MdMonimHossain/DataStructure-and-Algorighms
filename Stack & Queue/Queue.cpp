#include<stdio.h>
#define capacity 1000

int queue_arr[capacity];
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

void enqueue(int value)
{
    if(top + 1 < capacity)
    {
        queue_arr[++top] = value;
        printf("%d enqueued to queue\n", value);
    }
    else
        printf("Queue is full!\n");
}

int dequeue()
{
    if(!isEmpty())
    {
        int temp = queue_arr[0];

        for(int i = 0; i < Size() - 1; i++)
        {
            queue_arr[i] = queue_arr[i + 1];
        }
        top--;
        return temp;
    }

    return -1;
}

int main()
{
    enqueue(5);
    enqueue(8);
    enqueue(3);

    printf("Queue size = %d\n", Size());

    while(!isEmpty())
        printf("%d dequeued from queue\n", dequeue());

    return 0;
}
