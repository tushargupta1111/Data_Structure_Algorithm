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

// Cyclic detection using BFS Traverse in Graph

bool iscyclicbfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, int> parent;

    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
            else if (visited[front]== true && neighbour != parent[front])
                return true;
            
        }
    }
    return false;
}

bool isCyclicdetecction(unordered_map<int,list<int>> &adj)
{
    unordered_map<int, bool> visited(false);
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i] && iscyclicbfs(i,visited,adj))
        {
            return true;
        }
    }
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

    if (isCyclicdetecction(g.adj))
        cout << "Graph is cyclic" << endl;
    else
        cout<< "Graph is Acyclic" << endl;
   
    return 0;
}
