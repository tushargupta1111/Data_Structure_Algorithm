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

// Shortest Path in undirected Graph

void shortestpath(unordered_map<int, list<int>> &adj, int src, int dest)
{
    unordered_map<int, bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    parent[src] = -1;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        for (auto i : adj[frontnode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = frontnode;
                q.push(i);
            }
        }
    }

    // Prepare shortest path
    vector<int> ans;
    int currentnode =dest;
    ans.push_back(dest);
    while(currentnode != src)
    {
        currentnode =parent[currentnode];
        ans.push_back(currentnode);
    }

    // Printing the shortest path
    reverse(ans.begin(),ans.end());
    for(auto i : ans)
        cout<<i<<" ";
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

    cout<<"Shortest Path using BFS : "<<endl;
    shortestpath(g.adj,1,8);


    return 0;
}