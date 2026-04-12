#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction =0 ->undirected graph
        // direction =1 ->directed graph
        // create an edges from u to v
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
                cout << j << ",";
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of nodes & edges : ";
    cin >> n >> m;
    graph g;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }
    cout << "Print the Adjacency list of graph : " << endl;
    g.printgraph();

    return 0;
}