#include<stdio.h>

void BubbleSort(int arr[], int arrSize)
{
    int i, j, temp, flag;

    for(i = 0; i < arrSize - 1; i++)
    {
        flag = 0;

        for(j = 0; j < arrSize - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                if(flag == 0)
                    flag = 1;
            }
        }

        if(flag == 0)
            break;
    }
}

int main()
{
    int arr[] = {2, 5, 4, 10, 8, 1, 3, 9, 7, 6};
    int arrSize = 10;

    BubbleSort(arr, arrSize);

    printf("Sorted Array:\n");

    for(int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
