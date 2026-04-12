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
                cout << j << " , ";
            cout << endl;
        }
    }
};

void dfs(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto i : adj[node])
        if (!visited[i])
            dfs(i, visited, st, adj);
    st.push(node);
}

void ADFS(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto i : adj[node])
        if (!visited[i])
            ADFS(i, visited, adj);
}

int kosaraju(unordered_map<int, list<int>> &adj)
{
    // Topological Sort
    vector<bool> visited(adj.size(), false);
    stack<int> st;
    for (int i = 0; i < adj.size(); i++)
        if (!visited[i])
            dfs(i, visited, st, adj);

    // Transpose Graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = 0;
        for (auto neighbour : adj[i])
            transpose[neighbour].push_back(i);
    }

    // DfS call using above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!visited[top])
            count++, ADFS(top, visited, transpose);
    }

    return count;
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

    cout<<"Strongly Connected Component In Directed Graph : "<< kosaraju(g.adj) << endl;

    return 0;
}