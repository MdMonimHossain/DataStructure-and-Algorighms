#include<bits/stdc++.h>
#define INF 1000
using namespace std;

int nodeNo, startNode, n;
int adjMatrix[100][100];

struct Node{
    int node;
    int cost;
    int reducedMatrix[100][100];
    vector<Node> path;
}nodes[1000];

priority_queue<pair<int, int>> nodeQueue;

int getNodeCost(int node, int RCL, Node *prev)
{
    if(prev == NULL)
        return RCL;
    else
    {
        return (prev->cost + prev->reducedMatrix[prev->node][node] + RCL);
    }
}

void PrintMatrix(int matrix[100][100])
{
    for(int i = 1; i <= nodeNo; i++)
    {
        for(int j = 1; j <= nodeNo; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

pair<int, int> ColumnReduce(int node, int matrix[100][100], int RCL, Node *prev)
{
    for(int j = 1; j <= nodeNo; j++)
    {
        int minValue = INF;

        for(int i = 1; i <=nodeNo; i++)
        {
            if(matrix[i][j] < minValue)
            {
                minValue = matrix[i][j];
            }
        }
        if(minValue != INF && minValue != 0)
        {
            for(int i = 1; i <=nodeNo; i++)
            {
                if(matrix[i][j] != INF)
                {
                    matrix[i][j] -= minValue;
                }
            }
            RCL += minValue;
        }
    }

    nodes[n].node = node;
    nodes[n].cost = getNodeCost(node, RCL, prev);
    if(prev != NULL)
        nodes[n].path = prev->path;
    nodes[n].path.push_back(nodes[n]);

    for(int i = 1; i <= nodeNo; i++)
    {
        for(int j = 1; j <= nodeNo; j++)
        {
            nodes[n].reducedMatrix[i][j] = matrix[i][j];
        }
    }

    cout << "\nNode: " << nodes[n].node << "\n";
    cout << "Cost: " << nodes[n].cost << "\n";
    cout << "Path: ";
    vector<Node>::iterator it;
    for(it = nodes[n].path.begin(); it < nodes[n].path.end(); it++)
    {
        cout << it->node << "->";
    }
    cout << "\n";
    PrintMatrix(nodes[n].reducedMatrix);

    n++;

    return make_pair(-1 * nodes[n - 1].cost, n - 1);
}

pair<int, int> RowReduce(int node, int matrix[100][100], Node *prev)
{
    int totalCost = 0;

    for(int i = 1; i <= nodeNo; i++)
    {
        int minValue = INF;

        for(int j = 1; j <=nodeNo; j++)
        {
            if(matrix[i][j] < minValue)
            {
                minValue = matrix[i][j];
            }
        }
        if(minValue != INF && minValue != 0)
        {
            for(int j = 1; j <=nodeNo; j++)
            {
                if(matrix[i][j] != INF)
                {
                    matrix[i][j] -= minValue;
                }
            }
            totalCost += minValue;
        }
    }

    return ColumnReduce(node, matrix, totalCost, prev);
}

bool getVisitable(int i, int prev, int reducedMatrix[100][100])
{
    if(reducedMatrix[prev][i] != INF)
        return true;
    return false;
}

void PrintPath(Node n)
{
    cout << "\nCost = " << n.cost << "\n";
    cout << "Path: ";

    vector<Node>::iterator it;
    for(it = n.path.begin(); it < n.path.end(); it++)
    {
        cout << it->node << "->";
    }
    cout << startNode << "\n";
}

void TSP(int start)
{
    bool done = false;

    nodeQueue.push(RowReduce(start, adjMatrix, NULL));

    while(!done)
    {
        bool pathCompleted = true;
        Node u = nodes[nodeQueue.top().second];
        nodeQueue.pop();

        for(int i = 1; i <= nodeNo; i++)
        {
            if(getVisitable(i, u.node, u.reducedMatrix))
            {
                pathCompleted = false;
                int preparedMatrix[100][100];

                for(int j = 1; j <= nodeNo; j++)
                {
                    for(int k = 1; k <= nodeNo; k++)
                    {
                        if(j == u.node || k == i)
                            preparedMatrix[j][k] = 1000;
                        else
                            preparedMatrix[j][k] = u.reducedMatrix[j][k];
                    }
                }
                preparedMatrix[i][start] = 1000;

                nodeQueue.push(RowReduce(i, preparedMatrix, &u));
            }
        }
        if(pathCompleted)
        {
            if(u.cost <= -1 * nodeQueue.top().first)
            {
                done = true;
                PrintPath(u);
            }
        }
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
            cin >> adjMatrix[i][j];
        }
    }

    cout << "Enter Starting Node:\n";
    cin >> startNode;

    TSP(startNode);

    return 0;
}

/*

5
1000 20 30 10 11
15 1000 16 4 2
3 5 1000 2 4
19 6 18 1000 3
16 4 7 16 1000
1


4
1000 10 15 20
5 1000 9 10
6 13 1000 12
8 8 9 1000
1

*/

