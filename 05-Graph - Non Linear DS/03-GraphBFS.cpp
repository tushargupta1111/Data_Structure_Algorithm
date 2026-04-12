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

void bfs(unordered_map<int,list<int>> &adj,int node,vector<bool>& visited,vector<int> &ans)
{
    queue<int> q;
    visited[node]=true;
    q.push(node);
    while(!q.empty())
    {
        int frontnode =q.front();
        q.pop();
        ans.push_back(frontnode);

        for(auto i:adj[frontnode])
        {
            if(!visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
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
    vector<bool> visited(n, false);
    bfs(g.adj,0,visited,ans);
    cout<<"BFS traversal of graph : "<<endl;
    for(auto i : ans)
        cout<<i<<" ";


}
