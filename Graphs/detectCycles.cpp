#include<bits/stdc++.h>
using namespace std;

bool dfsUtil(list<int> adj[], int u, int parent, vector<bool>& vis){
    vis[u] = true;
    for(auto x : adj[u]) {
        if(vis[x] && x!=parent) return true;
        if(!vis[x]) dfsUtil(adj, x, u, vis);
    }
    return false;
}

bool hasCycle(list<int> adj[], int v, int e){
    vector<bool> vis(v, false);
    return(dfsUtil(adj, 0, -1, vis));
}

int main()
{
    int v, e;
    cin>>v>>e;
    list<int> adj[v];
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(hasCycle(adj, v, e)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
