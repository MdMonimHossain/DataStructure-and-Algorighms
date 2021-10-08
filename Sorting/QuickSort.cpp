#include<stdio.h>

void Swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
//1st element pivot

void QuickSort(int arr[], int f, int l)
{
    int i, j;

    if(f < l)
    {
        i = f + 1;
        j = l;
        while(arr[i] < arr[f])
            i++;
        while(arr[j] > arr[f])
            j--;
        while(i < j)
        {
            Swap(&arr[i], &arr[j]);
            while(arr[i] < arr[f])
                i++;
            while(arr[j] > arr[f])
                j--;
        }
        Swap(&arr[j], &arr[f]);
        QuickSort(arr, f, j - 1);
        QuickSort(arr, j + 1, l);
    }
}

//last element pivot
/*
void QuickSort(int arr[], int f, int l)
{
    int i, j;

    if(f < l)
    {
        i = f;
        j = l - 1;
        while(arr[i] < arr[l])
            i++;
        while(arr[j] > arr[l])
            j--;
        while(i < j)
        {
            Swap(&arr[i], &arr[j]);
            while(arr[i] < arr[l])
                i++;
            while(arr[j] > arr[l])
                j--;
        }
        Swap(&arr[i], &arr[l]);
        QuickSort(arr, f, i - 1);
        QuickSort(arr, i + 1, l);
    }
}
*/
//middle element as pivot
/*
void QuickSort(int arr[], int f, int l)
{
    int i, j;

    if(f < l)
    {
        i = f;
        j = l;
        int p = (f + l) / 2;
        while(arr[i] < arr[p])
            i++;
        while(arr[j] > arr[p])
            j--;
        while(i < j)
        {
            Swap(&arr[i], &arr[j]);
            while(arr[i] < arr[p])
                i++;
            while(arr[j] > arr[p])
                j--;
        }
        QuickSort(arr, f, p - 1);
        QuickSort(arr, p + 1, l);
    }
}
*/
int main()
{
    int arr[] = {8,29,41,14,92,17,62,87}, arrSize, i;
    arrSize = 8;
//    printf("Input the number of elements:\n");
//    scanf("%d", &arrSize);

//    printf("Input %d elements:\n", arrSize);
//    for(i = 0; i < arrSize; i++)
//    {
//        scanf("%d", &arr[i]);
//    }

    QuickSort(arr, 0, arrSize - 1);

    printf("Sorted array:\n");

    for(i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
