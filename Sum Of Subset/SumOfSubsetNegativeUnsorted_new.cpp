#include<bits/stdc++.h>
using namespace std;

int n, m, total;
int arr[100], sortedArr[100], arrOutput[100], c;

void QuickSort(int f, int l)
{
    int i, j;

    if(f < l)
    {
        i = f + 1;
        j = l;
        while(sortedArr[i] < sortedArr[f])
            i++;
        while(sortedArr[j] > sortedArr[f])
            j--;
        while(i < j)
        {
            swap(sortedArr[i], sortedArr[j]);
            while(sortedArr[i] < sortedArr[f])
                i++;
            while(sortedArr[j] > sortedArr[f])
                j--;
        }
        swap(sortedArr[j], sortedArr[f]);
        QuickSort(f, j - 1);
        QuickSort(j + 1, l);
    }
}

void PrintSubset()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i] == sortedArr[j])
            {
                cout << arrOutput[j];
                break;
            }
        }
    }
    cout << "\n";
}

bool isEmpty()
{
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        if(arrOutput[i] == 1)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void SumOfSubset(int i, int sum, int remaining)
{
    if(sum == m && !isEmpty())
    {
        //c++;
        PrintSubset();
        return;
    }
    if(sum > m || sum + remaining < m || i == n) // i==n is checked to stop for the last case where no element is taken (for negative elements when m=0)
    {
        return;
    }

    arrOutput[i] = 1;
    SumOfSubset(i + 1, sum + sortedArr[i], remaining - sortedArr[i]);
    arrOutput[i] = 0;
    SumOfSubset(i + 1, sum, remaining - sortedArr[i]);
}

int main()
{
    cout << "Enter value of n and m:\n";
    cin >> n >> m;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sortedArr[i] = arr[i];
        total += arr[i];
    }

    if(m > total)
        cout << "Solution not possible\n";

    QuickSort(0, n - 1);

    cout << "\nDesired Subsets:\n";
    SumOfSubset(0, 0, total);
    //cout << "Total solution = " << c << "\n";

    return 0;
}

