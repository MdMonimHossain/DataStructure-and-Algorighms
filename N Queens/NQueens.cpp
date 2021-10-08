#include<bits/stdc++.h>
using namespace std;

int n;
int x[100];

void PrintSol()
{
    for(int i = 1; i <= n; i++)
        cout << x[i] << " ";
    cout << "\n";
}

bool Place(int k, int i)
{
    for(int j = 1; j <= k - 1; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void NQueens(int k, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(Place(k, i))
        {
            x[k] = i;
            if(k == n)
            {
                PrintSol();
            }
            else
                NQueens(k + 1, n);
        }
    }
}

int main()
{
    cout << "Enter number of queens:\n";
    cin >> n;

    NQueens(1, n);

    return 0;
}
