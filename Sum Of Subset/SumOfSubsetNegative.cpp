#include<bits/stdc++.h>
using namespace std;

int n, m, total;
int arr[100], arrOutput[100], c;

void PrintSubset()
{
    for(int i = 0; i < n; i++)
        cout << arrOutput[i];
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
    SumOfSubset(i + 1, sum + arr[i], remaining - arr[i]);
    arrOutput[i] = 0;
    SumOfSubset(i + 1, sum, remaining - arr[i]);
}

int main()
{
    cout << "Enter value of n and m:\n";
    cin >> n >> m;
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    if(m > total)
        cout << "Solution not possible\n";

    cout << "\nDesired Subsets:\n";
    SumOfSubset(0, 0, total);
    //cout << "Total solution = " << c << "\n";

    return 0;
}

