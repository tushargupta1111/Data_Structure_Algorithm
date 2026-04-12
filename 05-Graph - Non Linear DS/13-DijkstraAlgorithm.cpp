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
        adj[v].push_back(make_pair(u,weight));
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

    // Dijkstra Algorithm 

    vector<int> dist(n,INT_MAX);
    set<pair<int,int>> st;

    cout<<"Enter the source node to Traverse : ";
    int src;
    cin>> src;
    dist[src] =0;
    st.insert(make_pair(0,src));
    while(!st.empty())
    {
        auto top = *(st.begin());
        int nodedist = top.first;
        int topnode = top.second;

        st.erase(st.begin());

        for(auto i : g.adj[topnode])
        {
            if(nodedist + i.second <dist[i.first])
            {
                auto record =st.find(make_pair(dist[i.first],i.first));

                if(record !=st.end())
                    st.erase(record);

                // Update distance
                dist[i.first] = nodedist + i .second;
                st.insert(make_pair(dist[i.first],i.first));
            }
        }
    }

    cout<<"DIJKSTRA ALGORITHM Shortest path : ";
    for(auto in : dist)
        cout<< in << "  ";

    return 0;
}