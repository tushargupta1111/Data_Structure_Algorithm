#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int src, dest, weight;
};

class DisjointSet
{
public:
    vector<int> parent, rank;
    int n;
    //  Disjoint Set
    DisjointSet(int N)
    {
        this->n = N;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {    parent[i] = i;
             rank[i] = 0;
        }
    }

    // Find the parent of a set (with path compression)
    int findparent(int node)
    {
        if (parent[node] != node)
            parent[node] = findparent(parent[node]);
        return parent[node];
    }

    // Union of two sets (with union by rank)
    void unionset(int u, int v)
    {
        u = findparent(u);
        v = findparent(v);

        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[u] > rank[v])
            parent[v] = u;
        else
            parent[v] = u, rank[u]++;
    }
};
// Kruskal's Algorithm
vector<graph> Kruskal(vector<graph> g)
{
    vector<graph> A;
    sort(g.begin(), g.end(), [](graph a, graph b)
         { return a.weight < b.weight; });

    // Make_set
    DisjointSet ds(g.size());
    // int Total = 0;
    for (auto i : g)
    {
        int u = i.src;
        int v = i.dest;
        int w = i.weight;

        int setU = ds.findparent(u);
        int setV = ds.findparent(v);

        // Add the edge to the result if it doesn't create a cycle
        if (setU != setV)
        {
            // Total += w;
            A.push_back(i);
            ds.unionset(setU, setV);
        }
    }
    return A;
}

int main()
{
    int n, m;
    cout << "Enter the numbers of nodes & edges : ";
    cin >> n >> m;

    int u, v, w;
    vector<graph> g;
    cout << "Entering format of (u v weight) : " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    cout<<"Edge\tWeight"<<endl;
    for (graph i : g)
        cout << i.src << " - " << i.dest << "\t" << i.weight << endl;

    vector<graph> tree = Kruskal(g);
    cout<<"Minimum Spanning Tree : "<<endl;
    for(auto i : tree)
        cout<<i.src<<" - "<<i.dest<< " : "<<i.weight<<endl;

        
    return 0;
}