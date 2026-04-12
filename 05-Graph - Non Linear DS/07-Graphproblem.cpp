#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction)
    {
        // direction = 0 --> undirected graph
        // direction = 1 --> directed graph
        adj[u].push_back(v);
        if (direction == 0)
            adj[v].push_back(u);
    }

    void printgraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
                cout << j << " , ";
            cout << endl;
        }
    }
};

//  Cyclic detection in Directed graph using DFS

bool iscyclicdfs(int src, unordered_map<int, bool> &visited, 
    unordered_map<int, bool> &dfsvisit, unordered_map<int, list<int>> &adj)
{
    visited[src] = dfsvisit[src] = true;

    for (auto i : adj[src])
    {
        if (!visited[i] && iscyclicdfs(i, visited, dfsvisit, adj))
            return true;
        else if (dfsvisit[i])
            return true;
    }
    dfsvisit[src] = false;
    return false;
}


bool isCyclicdetection(unordered_map<int, list<int>> &adj)
{
    unordered_map<int, bool> visited(false);
    unordered_map<int, bool> dfsvisit(false);
    for (int i = 0; i < adj.size(); i++)
        if (!visited[i] && iscyclicdfs(i, visited, dfsvisit, adj))
            return true;
    return false;
}

int main()
{
    int n, m;
    cout << "Enter the numbers of nodes & edges : ";
    cin >> n >> m;

    int u, v;
    graph g;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g.addEdges(u, v, 1);
    }

    cout << "Printing the Adjacency list of graph : " << endl;
    g.printgraph();

    if (isCyclicdetection(g.adj))
        cout << "Directed graph is cyclic";
    else
        cout << "Directed graph is acyclic";
    return 0;
}