#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    // Weighted Undirected Graph
    unordered_map<int, list<pair<int, int>>> adj;

    void addedges(int u, int v, int weight)
    {
        adj[u].push_back(make_pair(v, weight));
        // adj[v].push_back(make_pair(u, weight));
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

// Shortest Path -> weighted directed graph
// Dijkstra's algorithm ->> doesn't work on negative weight and also with negative cycle
void bellmanford(int src, int dest, unordered_map<int, list<pair<int, int>>> &adj)
{
    vector<int> dist(adj.size()+2, INT_MAX);
    dist[src] = 0;

    // N-1 times
    for (int i = 0; i <= adj.size() - 1; i++)
        for (auto j : adj[i])
            if (dist[i] != INT_MAX && dist[i] + j.second < dist[j.first])
                dist[j.first] = dist[i] + j.second;

    // Check for Negative Cycle is Occur on not
    bool flag = false;
    for (auto i : dist)
        if (i == INT_MAX)
            cout << "INF ";
        else
            cout << i << " ";
}

int main()
{
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

    bellmanford(0,2,g.adj);

    return 0;
}