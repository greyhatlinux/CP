// Graph and its representation

#include<bits/stdc++.h>
using namespace std;

// function to add an edge to the graph
void addEdge (vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// function to print the adjacency list
void printGraph(vector<int> adj[], int V) {
    for(int i=0;i<V;i++) {
        cout<<"List for "<<i<<" is : ";
        for(auto x:adj[i]) cout<<x<<" ->";
        cout<<"end\n";
    }
}

int main()
{
    int vertices = 6;
    vector<int> adj[vertices];
  
  // vector created with [] creates 2d arrays vector
  // vectors created with () creates 1d array vector
    
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 3);
    
    printGraph(adj, vertices);
    
    return 0;
}
