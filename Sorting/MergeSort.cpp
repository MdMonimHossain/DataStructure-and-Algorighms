#include<stdio.h>

void Merge(int arr[], int f, int mid, int l)
{
    int n1, n2, i, j, k;

    n1 = mid - f + 1;
    n2 = l - mid;

    int arrL[n1], arrR[n2];

    for(i = 0; i < n1; i++)
    {
        arrL[i] = arr[f + i];
    }
    for(j = 0; j < n2; j++)
    {
        arrR[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = f;
    while(i < n1 && j < n2)
    {
        if(arrL[i] < arrR[j])
        {
            arr[k] = arrL[i];
            i++;
        }
        else
        {
            arr[k] = arrR[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = arrL[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = arrR[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int f, int l,int  arrSize)
{
    if(f < l)
    {
        int mid;
        mid = (f + l) / 2;
        MergeSort(arr, f, mid, arrSize);
        MergeSort(arr, mid + 1, l, arrSize);
        Merge(arr, f, mid, l);
    }
}

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

    MergeSort(arr, 0, arrSize - 1, arrSize);

    printf("Sorted array:\n");

    for(i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
