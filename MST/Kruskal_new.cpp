#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[100];
vector<int> costVec[100];
priority_queue<pair<int, pair<int, int>>> nodeQueue;
int rep[100];

int nodeNo, edgeNo, cost, minCost;

void MakeSet(int v)
{
    rep[v] = v;
}

int FindSet(int v)
{
    if(rep[v] == v)
        return v;
    rep[v] = FindSet(rep[v]);
    return rep[v];
}

void Union(int r1, int r2)
{
    rep[r1] = r2;
}

void MST_Kruskal()
{
    for(int v = 1; v <= nodeNo; v++)
    {
        MakeSet(v);
    }

    for(int u = 1; u <= nodeNo; u++)
    {
        for(int v = 0; v < nodeVec[u].size(); v++)
        {
            nodeQueue.push(make_pair(-1 * costVec[u][v], make_pair(u, nodeVec[u][v])));
        }
    }

    cout << "Edges:\n";

    while(!nodeQueue.empty())
    {
        int u = nodeQueue.top().second.first;
        int v = nodeQueue.top().second.second;

        if(FindSet(u) != FindSet(v))
        {
            cout << u << "-" << v << "\n";
            minCost += -1 * nodeQueue.top().first;
            Union(FindSet(u), FindSet(v));
        }
        nodeQueue.pop();
    }

    cout << "Minimum Cost: " << minCost << "\n";
}

int main()
{
    cout << "Enter no of Nodes:\n";
    cin >> nodeNo;
    cout << "Enter no of Edges:\n";
    cin >> edgeNo;

    int nodeA, nodeB;
    cout << "Enter " << edgeNo << " Edges:\n";
    for(int i = 1; i <= edgeNo; i++)
    {
        cin >> nodeA >> nodeB >> cost;
        nodeVec[nodeA].push_back(nodeB);
        nodeVec[nodeB].push_back(nodeA);
        costVec[nodeA].push_back(cost);
        costVec[nodeB].push_back(cost);
    }

    MST_Kruskal();

    return 0;
}

/*
Enter no of Node:
8
Enter no of Edge:
10
Enter 10 Edges:
1 2 3
1 8 14
2 3 8
2 8 10
3 4 15
3 6 2
5 6 9
6 7 4
6 8 5
7 8 6
*/


