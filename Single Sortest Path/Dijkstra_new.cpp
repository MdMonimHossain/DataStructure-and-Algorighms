#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[100];
vector<int> costVec[100];
vector<pair<int, int>> nodes;
int prevNode[100];
priority_queue<pair<int, int>> nodeQueue;
stack<int> nodeStack;

int nodeNo, edgeNo, startNode, endNode, cost;

void Dijkstra(pair<int, int> start)
{
    nodeQueue.push(start);

    while(!nodeQueue.empty())
    {
        int u = nodeQueue.top().second;
        nodeQueue.pop();

        for(int i = 0; i < nodeVec[u].size(); i++)
        {
            int v = nodeVec[u][i];

            if(nodes[u].first + costVec[u][i] < nodes[v].first)
            {
                nodes[v].first = nodes[u].first + costVec[u][i];
                nodeQueue.push(make_pair(-1 * nodes[v].first, v));
                prevNode[v] = u;
            }
        }
    }

    for(int endNode = 0; endNode < nodeNo; endNode++)
    {
        if(endNode != startNode)
        {
            if(nodes[endNode].first != INT_MAX)
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
                cout << "\n" << "Cost: " << nodes[endNode].first << "\n";
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
        costVec[nodeA].push_back(cost);
    }

    cout << "Enter Starting Node:\n";
    cin >> startNode;

    for(int i = 0; i < 100; i++)
    {
        nodes.push_back(make_pair(INT_MAX, i));
    }
    nodes[startNode].first = 0;

    Dijkstra(nodes[startNode]);

    return 0;
}

/*
Enter no of Node:
5
Enter no of Edge:
10
Enter 10 Edges:
0 1 10
0 3 5
1 2 1
1 3 2
2 4 4
3 1 3
3 2 9
3 4 2
4 0 7
4 2 6
Enter Starting Node:
0
*/

