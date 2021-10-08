#include<bits/stdc++.h>
#define diagonal 1
#define upper 2
#define left 3
using namespace std;

int b[100][100], c[100][100];

void LCS_Length(string x, string y)
{
    int m = x.length();
    int n = y.length();

    for(int i = 1 ; i <= m; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = diagonal;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = upper;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = left;
            }
        }
    }

}

void Print_LCS(string x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == diagonal)
    {
        Print_LCS(x, i - 1, j - 1);
        cout << x[i-1];
    }
    else if(b[i][j] == upper)
        Print_LCS(x, i - 1, j);
    else
        Print_LCS(x, i, j - 1);
}

int main()
{
    string x, y;
    cout << "Enter two sequences:\n";
    cin >> x >> y;

    int m = x.length();
    int n = y.length();

    LCS_Length(x, y);
    cout << "LCS: ";
    Print_LCS(x, m, n);
    cout << "\nLength: " << c[m][n];

    return 0;
}
