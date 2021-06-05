#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic(vector<vector<int>> &lst, int curr, vector<bool> &visited, int parent) {

//     we have an adjacency list given to us as vector<vector<int>> adj;
//     we should find the cycle traversing the adjacency list

    // write recusive DFS
    visited[curr] = true;
    for(int i=0; i<lst[curr].size(); i++) {
        int vertx = lst[curr][i];

        // if not visited
        if(!visited[vertx]){
            if(isCyclic(lst, vertx, visited, curr)) return true;
        }

        // if already visited
        // we need to check whether its parent is same 
        else if(vertx != parent) return true;

    }
    return false;

}

bool isTree(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(adj.size(), false);
    int parent = -1;

    if(isCyclic(adj, 0, visited, parent)) return false;
    for(auto vis:visited) {
        if(!vis) return false;
    }

    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;

    // creating an adjacency list for all the vertex and edges of the graph
    vector<vector<int>> adj(v);

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isTree(adj, v)) cout << "True";
    else cout << "False";

    return 0;
}
