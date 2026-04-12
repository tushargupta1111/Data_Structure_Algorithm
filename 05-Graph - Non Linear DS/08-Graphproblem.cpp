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

// Topological Sort using DFS
// DAG :- Direct Acyclic Graph

void TopologicalSort(int src, unordered_map<int, bool> &visited,
                     unordered_map<int, list<int>> &adj, stack<int> &result)
{
    visited[src] = true;

    for (auto i : adj[src])
        if (!visited[i])
            TopologicalSort(i, visited, adj, result);
    result.push(src);
}

void DFS(unordered_map<int, list<int>> &adj)
{
    unordered_map<int, bool> visited;
    stack<int> result;
    for (int i = 1; i < adj.size(); i++)
        if (!visited[i])
            TopologicalSort(i, visited, adj, result);

    while (!result.empty())
    {
        cout << result.top() << "  ";
        result.pop();
    }
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

    cout<< "Topological Sort : ( Using DFS )" << endl;
    DFS(g.adj);

    return 0;
}