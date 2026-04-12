#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    // Weighted Directed Graph
    unordered_map<int, list<pair<int, int>>> adj;

    void addedges(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printgraph()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
                cout << "[" << j.first << "," << j.second << "] ,";
            cout << endl;
        }
    }
};

void DFS(int src, unordered_map<int, bool> &visited, stack<int> &topo, unordered_map<int, list<pair<int, int>>> &adj)
{
    visited[src] = true;

    for (auto i : adj[src])
        if (!visited[i.first])
            DFS(i.first, visited, topo, adj);
    topo.push(src);
}

int main()
{
    // Input :- 6 9
    // 0 1 5
    // 0 2 3
    // 1 2 2
    // 1 3 6
    // 2 3 7
    // 3 4 -1
    // 2 4 4
    // 2 5 2
    // 4 5 -2
    int n, m;
    cout << "Enter the numbers of nodes & edges : ";
    cin >> n >> m;

    int u, v, w;
    graph g;
    cout << "Entering format of (u v weight) : " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.addedges(u, v, w);
    }
    cout << "Printing the Adjacency list of graph : " << endl;
    g.printgraph();

    // topological Sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(i, visited, s, g.adj);

    // Linear Order - Distance Array
    vector<int> dist(n, INT_MAX);
    cout << "Enter the source node to Traverse : ";
    int src;
    cin >> src;
    // int src=1;

    dist[src] = 0;
    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        if (dist[top] != INT_MAX)
            for (auto i : g.adj[top])
                if (dist[top] + i.second < dist[i.first])
                    dist[i.first] = dist[top] + i.second;
    }
    // Printing the all distance fromt source node
    cout << "Shortest Path in DAG : " << endl;
    for (auto i : dist)
    {
        if (i == INT_MAX)
            cout << "INT ";
        else
            cout << i << " ";
    }

    return 0;
}
