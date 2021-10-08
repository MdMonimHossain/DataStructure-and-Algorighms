#include<bits/stdc++.h>
using namespace std;

int m[100][100], s[100][100];

void MatrixChainOrder(int n, int p[])
{
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;

            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(int k = i + 1; k < j; k++)
            {
                int minValue = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(minValue < m[i][j])
                {
                    m[i][j] = minValue;
                    s[i][j] = k;
                }
            }
        }
    }

}

void PrintOptimalParens(int i, int j)
{
    if(i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        PrintOptimalParens(i, s[i][j]);
        PrintOptimalParens(s[i][j] + 1, j);
        cout << ")";
    }
}

int main()
{
    int n, p[100];
    cout << "Enter the number of matrices:\n";
    cin >> n;
    cout << "Enter matrix dimensions array:\n";
    for(int i = 0; i <= n; i++)
        cin >> p[i];

    MatrixChainOrder(n, p);
    cout << "Minimum cost: " << m[1][n] << "\n";
    cout << "Optimal parenthesization:\n";
    PrintOptimalParens(1, n);

    return 0;
}
