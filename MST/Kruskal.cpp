#include<bits/stdc++.h>
using namespace std;

int nodeNo, edgeNo, cost, minCost;
vector<pair<int, pair<int, int>>> edges;
int rep[100];

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

    sort(edges.begin(), edges.end());

    cout << "Edges:\n";

    for(int i = 0; i < edgeNo; i++)
    {
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if(FindSet(u) != FindSet(v))
        {
            cout << u << "-" << v << "\n";
            minCost += edges[i].first;
            Union(FindSet(u), FindSet(v));
        }
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
        edges.push_back(make_pair(cost, make_pair(nodeA, nodeB)));
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

