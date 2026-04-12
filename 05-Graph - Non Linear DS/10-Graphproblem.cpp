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

// Cyclic detection in Directed graph using BFS (topological sort)

bool cyclicdetection(unordered_map<int, list<int>> &adj)
{
    // Finding indegree of all nodes
    // take original size of graph nodes
    vector<int> indegree(adj.size() + 2, 0);
    for (auto i : adj)
        for (auto j : i.second)
            indegree[j]++;

    // Queue -> 0 indegree node push in queue
    queue<int> q;
    for (int i = 1; i < adj.size(); i++)
        if (indegree[i] == 0)
            q.push(i);
    // do BFS
    int count = 0;
    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        count++;

        for (auto i : adj[frontnode])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    // comment on it : -
    if (count == adj.size())
        return false;
    return true;
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

    if (cyclicdetection(g.adj))
        cout << "Directed graph is cyclic";
    else
        cout << "Directed graph is acyclic";
    return 0;
}
