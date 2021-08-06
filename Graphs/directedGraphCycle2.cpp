#include<bits/stdc++.h>
using namespace std;

bool dfsUtil(list<int> adj[], int u, vector<bool>& recStack, vector<bool>& vis){
    if(!vis[u]){
        vis[u] = true;
        recStack[u] = true;
        for(auto x : adj[u]){
            if(!vis[x] && dfsUtil(adj, x, recStack, vis)) return true;
            else if(recStack[x]) return true;            
        }
    }
    recStack[u] = false;
    return false;
}

bool hasCycle(list<int> adj[], int v, int e){
    vector<bool> vis(v, false);
    vector<bool> recStack(v, false);
    return(dfsUtil(adj, 0, recStack, vis));
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
    }

    if(hasCycle(adj, v, e)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

// input : 
// 5 5
// 0 2 
// 2 3 
// 2 4
// 1 4
// 4 1
// Output : YES
