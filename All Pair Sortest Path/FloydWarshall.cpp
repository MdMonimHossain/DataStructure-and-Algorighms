#include<bits/stdc++.h>
#define INF 1000
using namespace std;

int nodeNo;

struct Node{
    int d[100][100];
    int pi[100][100];
}nodes[100];

void FloydWarshall()
{
    for(int k = 1; k <= nodeNo; k++)
    {
        for(int i = 1; i <= nodeNo; i++)
        {
            for(int j = 1; j <= nodeNo; j++)
            {
                if(nodes[k - 1].d[i][j] <= nodes[k - 1].d[i][k] + nodes[k - 1].d[k][j])
                {
                    nodes[k].d[i][j] = nodes[k - 1].d[i][j];
                    nodes[k].pi[i][j] = nodes[k - 1].pi[i][j];
                }
                else
                {
                    nodes[k].d[i][j] = nodes[k - 1].d[i][k] + nodes[k - 1].d[k][j];
                    nodes[k].pi[i][j] = nodes[k - 1].pi[k][j];
                }
            }
        }
    }
}

void PrintPath(int pi[100][100], int i, int j)
{
    if(i == j)
        cout << i << " ";
    else if(pi[i][j] == -1)
        cout << "No path from " << i << " to " << j << " exists";
    else
    {
        PrintPath(pi, i, pi[i][j]);
        cout << j << " ";
    }
}

int main()
{
    cout << "Enter number of nodes:\n";
    cin >> nodeNo;

    cout << "Enter the adjacency matrix:\n";
    for(int i = 1; i <= nodeNo; i++)
    {
        for(int j = 1; j <= nodeNo; j++)
        {
            cin >> nodes[0].d[i][j];
            if(i == j || nodes[0].d[i][j] == INF)
                nodes[0].pi[i][j] = -1;
            else
                nodes[0].pi[i][j] = i;
        }
    }

    FloydWarshall();

    for(int i = 1; i <= nodeNo; i++)
    {
        for(int j = 1; j <= nodeNo; j++)
        {
            cout << i << "->" << j <<": ";
            PrintPath(nodes[nodeNo].pi, i, j);
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

/*
5
0 3 8 1000 -4
1000 0 1000 1 7
1000 4 0 1000 1000
2 1000 -5 0 1000
1000 1000 1000 6 0
*/

