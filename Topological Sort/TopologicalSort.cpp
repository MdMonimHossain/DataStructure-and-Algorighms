#include<bits/stdc++.h>
using namespace std;

vector<int> nodeVec[200];
vector<int> timeVec[200];
list<int> nodeList;
int visited[200];
int nodeNo;
int t;

void DFS_VISIT(int start)
{
    visited[start] = 1;
    t += 1;
    timeVec[start].push_back(t);

    for(int i = 0; i < nodeVec[start].size(); i++)
    {
        int node = nodeVec[start][i];
        if(visited[node] == 0)
        {
            DFS_VISIT(node);
        }
    }

    t += 1;
    timeVec[start].push_back(t);
    nodeList.push_front(start);
}

void DFS()
{
    for(int v = 1; v <= nodeNo; v++)
    {
        if(visited[v] == 0)
            DFS_VISIT(v);
    }
}

void TopologicalSort()
{
    DFS();

    while(!nodeList.empty())
    {
        int node = nodeList.front();
        cout << node << " - " << timeVec[node][0] << "/" << timeVec[node][1] << "\n";
        nodeList.pop_front();
    }
}

int main()
{
    nodeNo = 6;
    nodeVec[6].push_back(3);
    nodeVec[6].push_back(1);
    nodeVec[5].push_back(1);
    nodeVec[5].push_back(2);
    nodeVec[3].push_back(4);
    nodeVec[4].push_back(2);

    TopologicalSort();

    return 0;
}
