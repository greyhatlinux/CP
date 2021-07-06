// Directed graph dfs traversal
// cycle detection and connection detection

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int size;

    public:
    Graph(int s) {
        size = s;
    }

    map<int, list<int>> adj;

    void addEdge(int i, int j) {
        adj[i].push_back(j);
    }


    bool isCyclic(int i, bool *visited) {
        visited[i] = true;
        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            if(adj.find(*it) != adj.end()){
                if(!visited[*it]) isCyclic(*it, visited);
                else return true;
            }
        }
        return false;
    }

    void dfsUtil(int i, bool *visited) {
        visited[i] = true;
        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            if(!visited[*it]) dfsUtil(*it, visited);
        }
    }


    //perform dfs for all nodes in the graph
    void dfs() {
        bool visited[size+1] = {false};
        if(isCyclic(1, visited)) cout<<"Has cycle\n";
        else cout<<"Doesn't has cycle\n";

        int conn = 0;
        visited[size+1] = {false};
        dfsUtil(1, visited);
        for(int i=1;i<=size;i++) {
            if(!visited[i]) conn++;
        }
        if(conn) cout<<"Not a connected graph\n";
        else cout<<"Graph is connected\n";
        
    }

    void printGraph() {
        cout<<"Adjacency List : \n";
        for(auto i=adj.begin();i != adj.end();i++){
            cout<<i->first<<" -> ";
            for(auto j = adj[i->first].begin(); j != adj[i->first].end(); j++) cout<<*j<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    int u,v;
    // cin>>u;

    u = 8;
    Graph g(u);

    // Cyclic graph and connected 
    // g.addEdge(1,2);
    // g.addEdge(1,3);
    // g.addEdge(1,5);
    // g.addEdge(2,4);
    // g.addEdge(3,6);
    // g.addEdge(3,5);
    // g.addEdge(4,3);
    // g.addEdge(4,1);
    // g.addEdge(6,1);

    //Non cyclic graph and not connected graph
    // 7->8 is a separate graph
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(6,5);
    g.addEdge(3,1);
    g.addEdge(3,6);
    g.addEdge(7,8);
   
    g.dfs();
    g.printGraph();

    return 0;
}
