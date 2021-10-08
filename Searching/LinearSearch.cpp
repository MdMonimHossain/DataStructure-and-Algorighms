#include<stdio.h>

int LinearSearch(int arr[], int arrSize, int key)
{
    for(int i = 0; i < arrSize; i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[1000], arrSize, key, index, i;

    printf("Input number of elements:\n");
    scanf("%d", &arrSize);

    printf("Input %d elements:\n", arrSize);
    for(i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Input an element to search:\n");
    scanf("%d", &key);

    index = LinearSearch(arr, arrSize, key);

    if(index == -1)
        printf("%d not found.\n", key);
    else
        printf("%d found at index %d.\n", key, index);

    return 0;
}
