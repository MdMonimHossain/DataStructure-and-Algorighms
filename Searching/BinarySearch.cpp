#include<stdio.h>

int BinarySearch(int arr[], int left, int right, int key)
{
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(mid < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[1000], arrSize, key, index, i;

    printf("Input number of elements:\n");
    scanf("%d", &arrSize);

    printf("Input %d elements:(ascending order)\n", arrSize);
    for(i = 0; i < arrSize; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Input an element to search:\n");
    scanf("%d", &key);

    index = BinarySearch(arr, 0, arrSize - 1, key);

    if(index == -1)
        printf("%d not found.\n", key);
    else
        printf("%d found at index %d.\n", key, index);

    return 0;

}
