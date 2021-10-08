#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[100];
vector<int> costVec[100];
vector<pair<int, int>> nodes;
int prevNode[100];
bool visited[100];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodeQueue;
stack<int> nodeStack;

int nodeNo, edgeNo, cost, minCost;

void MST_Prim(pair<int, int> start)
{
    nodeQueue.push(start);

    cout << "Edges:\n";

    while(!nodeQueue.empty())
    {
        int u = nodeQueue.top().second;
        nodeQueue.pop();
        visited[u] = true;

        for(int i = 0; i < nodeVec[u].size(); i++)
        {
            int v = nodeVec[u][i];

            if(!visited[v])
            {
                if(costVec[u][i] < nodes[v].first)
                {
                    nodes[v].first = costVec[u][i];
                    nodeQueue.push(nodes[v]);
                    prevNode[v] = u;
                }
            }
        }
    }

    for(int u = 0; u < nodeNo; u++)
    {
        if(prevNode[u] != -1)
            cout << prevNode[u] << "-" << u << "\n";
        minCost += nodes[u].first;
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
    for(int i = 0; i < edgeNo; i++)
    {
        cin >> nodeA >> nodeB >> cost;
        nodeVec[nodeA].push_back(nodeB);
        nodeVec[nodeB].push_back(nodeA);
        costVec[nodeA].push_back(cost);
        costVec[nodeB].push_back(cost);
    }

    for(int i = 0; i < nodeNo; i++)
    {
        nodes.push_back(make_pair(INT_MAX, i));
    }
    nodes[0].first = 0;
    prevNode[0] = -1;

    MST_Prim(nodes[0]);

    return 0;
}

/*
Enter no of Node:
8
Enter no of Edge:
10
Enter 10 Edges:
0 1 3
0 7 14
1 2 8
1 7 10
2 3 15
2 5 2
4 5 9
5 6 4
5 7 5
6 7 6
*/
