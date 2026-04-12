#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int edges;
    vector<vector<int>> adj;

    graph(int n)
    {
       this->edges =n;
       adj.resize(edges,vector<int>(edges,0)); 
    }

    void addEdge(int u, int v, bool direction)
    {
        // direction =0 ->undirected graph
        // direction =1 ->directed graph
        // create an edges from u to v
        adj[u][v] = 1;
        if (direction == 0)
            adj[v][u]=1;
    }

    void printgraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void printgraphlist()
    {
        for(int i=0;i<adj.size();i++)
        {
            cout<< i << " -> ";
            for(int j=0;j < adj[i].size();j++)
            {
                if(adj[i][j])
                    cout<< j << ", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Enter the number of nodes & edges : ";
    cin >> n >> m;
    graph g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }
    cout << "Print the Adjacency Matrix of graph : " << endl;
    g.printgraph();


    cout<< "Printing the Adjacency List of graph : " <<endl;
    g.printgraphlist();

    return 0;
}