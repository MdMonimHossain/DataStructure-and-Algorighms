#include<stdio.h>

void InsertionSort(int arr[], int arrSize)
{
    int i, j, temp;

    for(i = 1; i < arrSize; i++)
    {
        temp = arr[i];

        for(j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    int arr[1000], arrSize, i;

    printf("Input the number of elements:\n");
    scanf("%d", &arrSize);

    printf("Input %d elements:\n", arrSize);

    for(i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }

    InsertionSort(arr, arrSize);

    printf("Sorted Array:\n");

    for(i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
