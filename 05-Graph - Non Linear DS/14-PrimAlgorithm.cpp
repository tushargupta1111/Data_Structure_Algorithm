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
        adj[v].push_back(make_pair(u, weight));
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


// Prim's Algorithm (Time complexity : o(n^2))
void Prim(vector<int> &key,vector<bool> &MST,vector<int> &parent,unordered_map<int, list<pair<int, int>>> &adj)
{
    key[0] = 0;
    int n =adj.size();

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int v = 0; v < n; v++)
        {
            if (!MST[v] && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        MST[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!MST[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
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

    vector<bool> MST(n, false);
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);

    Prim(key,MST,parent,g.adj);

    cout<<"Spanning Tree : "<<endl;
    cout << "Edge \tWeight"<<endl;
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;

    return 0;
}