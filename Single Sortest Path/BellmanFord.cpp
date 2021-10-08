#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[100];
int edgeCost[100][100];
int prevNode[100];
int dist[100];
stack<int> nodeStack;

int nodeNo, edgeNo, startNode, endNode, cost;
bool flag;

void BellmanFord(int start)
{
    for(int i = 1; i <= nodeNo - 1; i++)
    {
        flag = false;
        for(int u = 0; u < nodeNo; u++)
        {
            for(int j = 0; j < nodeVec[u].size(); j++)
            {
                int v = nodeVec[u][j];

                if(dist[u] != INT_MAX)
                {
                    if(dist[u] + edgeCost[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + edgeCost[u][v];
                        prevNode[v] = u;
                        flag = true;
                    }
                }
            }
        }
        if(!flag)
        {
            break;
        }
    }

    for(int u = 0; u < nodeNo; u++)
    {
        for(int j = 0; j < nodeVec[u].size(); j++)
        {
            int v = nodeVec[u][j];

            if(dist[u] != INT_MAX)
            {
                if(dist[u] + edgeCost[u][v] < dist[v])
                {
                    cout << "Negative cycle exists. Shortest Path Undefined.\n";
                    return;
                }
            }
        }
    }

    for(int endNode = 0; endNode < nodeNo; endNode++)
    {
        if(endNode != startNode)
        {
            if(dist[endNode] != INT_MAX)
            {
                nodeStack.push(endNode);
                int p = endNode;
                while(p != startNode)
                {
                    p = prevNode[p];
                    nodeStack.push(p);
                }

                cout << "\nPath: ";
                while(!nodeStack.empty())
                {
                    cout << nodeStack.top() << " ";
                    nodeStack.pop();
                }
                cout << "\n" << "Cost: " << dist[endNode] << "\n";
            }
        }
    }
}

int main()
{
    cout << "Enter no of Node:\n";
    cin >> nodeNo;
    cout << "Enter no of Edge:\n";
    cin >> edgeNo;

    int nodeA, nodeB;
    cout << "Enter " << edgeNo << " Edges:\n";
    for(int i = 0; i < edgeNo; i++)
    {
        cin >> nodeA >> nodeB >> cost;
        nodeVec[nodeA].push_back(nodeB);
        edgeCost[nodeA][nodeB] = cost;
    }

    cout << "Enter Starting Node:\n";
    cin >> startNode;

    for(int i = 0; i < 100; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[startNode] = 0;

    BellmanFord(startNode);

    return 0;
}

/*
Enter no of Node:
5
Enter no of Edge:
10
Enter 10 Edges:
1 2 5
1 3 8
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 0 2
4 2 7
0 1 6
0 3 7
Enter Starting Node:
0
*/
