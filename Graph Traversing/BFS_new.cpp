#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[100];
//vector<int> nodeCost[100];
int visited[100];
queue<int> nodeQueue;
int nodeNo, edgeNo, startNode;
//int nodeNo, edgeNo, startNode, cost;

void BFS(int start)
{
    nodeQueue.push(start);
    visited[start] = 1;

    while(!nodeQueue.empty())
    {
        int frnt = nodeQueue.front();
        nodeQueue.pop();

        cout << frnt << " ";

        for(int i = 0; i < nodeVec[frnt].size(); i++)
        {
            int node = nodeVec[frnt][i];
            if(visited[node] == 0)
            {
                nodeQueue.push(node);
                visited[node] = 1;
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
    for(int i = 1; i <= edgeNo; i++)
    {
        cin >> nodeA >> nodeB;
        //cin >> nodeA >> nodeB >> cost;
        nodeVec[nodeA].push_back(nodeB);
        //nodeCost[nodeA].push_back(cost);
        //nodeVec[nodeB].push_back(nodeA);
    }

    cout << "Enter Starting Node:\n";
    cin >> startNode;

    BFS(startNode);

    return 0;
}
