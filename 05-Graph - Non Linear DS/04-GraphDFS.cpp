#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj;

        void addEdges(int u,int v,bool direction)
        {
            // direction = 0 --> undirected graph
            // direction = 1 --> directed graph
            adj[u].push_back(v);
            if(direction == 0)
                adj[v].push_back(u);
        }

        void printgraph()
        {
            for(auto i:adj)
            {
                cout<<i.first<<" -> ";
                for(auto entry:i.second)
                    cout<<entry<<",";
                cout<<endl;
            }
        }
};

void dfs(unordered_map<int,list<int>> &adj,int node,unordered_map<int,bool>& visited,vector<int> &ans)
{
    visited[node]=true;
    ans.push_back(node);
    for(auto i : adj[node])
    {
        if(!visited[i])
            dfs(adj,i,visited,ans);
    }
}

int main()
{
    int n,m;
    cout<<"Enter the numbers of nodes & edges : ";
    cin>>n>>m;

    int u,v;
    graph g;
    for(int i=0;i<m;i++)
    {   cin>>u>>v;
        g.addEdges(u,v,0);
    }
    cout<<"Print the adjacencey list of graph : "<<endl;
    g.printgraph();

    
    vector<int> ans;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
       {
        vector<int> comp;
        dfs(g.adj,i,visited,comp);
        ans.insert(ans.end(),comp.begin(),comp.end());
       }
    }
    cout<<"DFS traversal of graph : "<<endl;
    for(auto i : ans)
        cout<<i<<" ";   
    return 0;
}