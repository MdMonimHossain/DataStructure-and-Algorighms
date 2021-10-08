#include<stdio.h>

void SelectionSort(int arr[], int arrSize)
{
    int i, j, min_index, temp;

    for(i = 0; i < arrSize - 1; i++)
    {
        min_index = i;

        for(j = i + 1; j < arrSize; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if(min_index != i)
        {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
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

    SelectionSort(arr, arrSize);

    printf("Sorted array:\n");

    for(i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;

}
