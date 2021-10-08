#include<bits/stdc++.h>
using namespace std;

struct Node{
    int node;
    int dist;
}nodelist[100];

struct CompareDistance{
    bool operator()(Node const& n1, Node const& n2)
    {
        return n1.dist > n2.dist;
    }
};

vector<int> nodeVec[100];
int edgeCost[100][100];
int prevNode[100];
priority_queue<Node, vector<Node>, CompareDistance> nodeQueue;
stack<int> nodeStack;

int nodeNo, edgeNo, startNode, endNode, cost;

void Dijkstra(int start)
{
    nodeQueue.push(nodelist[start]);

    while(!nodeQueue.empty())
    {
        int u = nodeQueue.top().node;
        nodeQueue.pop();

        for(int i = 0; i < nodeVec[u].size(); i++)
        {
            int v = nodeVec[u][i];

            if(nodelist[u].dist + edgeCost[u][v] < nodelist[v].dist)
            {
                nodelist[v].dist = nodelist[u].dist + edgeCost[u][v];
                nodeQueue.push(nodelist[v]);
                prevNode[v] = u;
            }
        }
    }

    for(int endNode = 0; endNode < nodeNo; endNode++)
    {
        if(endNode != startNode)
        {
            if(nodelist[endNode].dist != INT_MAX)
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
                cout << "\n" << "Cost: " << nodelist[endNode].dist << "\n";
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
        nodelist[i].node = i;
        nodelist[i].dist = INT_MAX;
    }
    nodelist[startNode].dist = 0;

    Dijkstra(startNode);

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
