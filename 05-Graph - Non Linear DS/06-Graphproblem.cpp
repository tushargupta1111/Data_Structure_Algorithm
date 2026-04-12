#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdges(int u, int v, bool direction)
    {
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
                cout << j << ", ";
            cout << endl;
        }
    }
};

// Cyclic Detection using DFS Treverse in graph

bool iscyclicdfs(int src,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{   
    // unordered_map<int,int> parent;
    visited[src] = true;
    // parent[src] =-1;
    for(auto i:adj[src])
    {
        if(!visited[i])
        {
            // parent[i] = src;
            if(iscyclicdfs(i,src,visited,adj))
            return true;
        }
        else if(parent!=i)
            return true;
    }
    return false;     
}

bool isCyclicdetection(unordered_map<int,list<int>> &adj)
{
    unordered_map<int, bool> visited(false);
    for (int i = 0; i < adj.size(); i++)
        if (!visited[i] && iscyclicdfs(i,-1,visited,adj))
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
        g.addEdges(u, v, 0);
    }

    cout << "Printing the Adjacency list of graph : " << endl;
    g.printgraph();

    if (isCyclicdetection(g.adj))
        cout << "Graph is cyclic" << endl;
    else
        cout<< "Graph is Acyclic" << endl;
   
    return 0;
}
