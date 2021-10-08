#include<bits/stdc++.h>
using namespace std;

int n, W;
int w[100], b[100];
int V[1000][1000];
int result[100];

void Knapsack()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= W; j++)
        {
            if(w[i] <= j)
            {
                if(b[i] + V[i-1][j-w[i]] > V[i-1][j])
                    V[i][j] = b[i] + V[i-1][j-w[i]];
                else
                    V[i][j] = V[i-1][j];
            }
            else
                V[i][j] = V[i-1][j];
        }
    }
}

void FindItems(int i, int k)
{
    if(i == 0 || k == 0)
        return;
    if(V[i][k] != V[i-1][k])
    {
        result[i] = 1;
        FindItems(i - 1, k - w[i]);
    }
    else
        FindItems(i - 1, k);
}

int main()
{
    cout << "Enter number of elements and max capacity:\n";
    cin >> n >> W;

    cout << "Enter weight and benefit of " << n << " elements:\n";
    for(int i = 1; i <= n; i++)
    {
        cin >> w[i] >> b[i];
    }

    Knapsack();

//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= W; j++)
//        {
//            cout << V[i][j] << "\t";
//        }
//        cout << "\n";
//    }


    FindItems(n, W);

    cout << "Items:\n";
    for(int i = 1; i <= n; i++)
    {
        //variable length
        //if(result[i] == 1)
        //    cout << i << " ";

        //fixed length
        cout << result[i] << " ";

        //benefit
        //if(result[i] == 1)
        //    cout << b[i] << " ";
    }

    cout << "\nMaximum value: " << V[n][W];

    return 0;
}
