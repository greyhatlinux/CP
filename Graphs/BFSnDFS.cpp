// BFS traversal in a graph

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    list<int> *adj;
    
    void DFSutil(int v, bool visited[]);
    
    public:
    
    Graph (int v) {
        vertices = v;
        
        // taking a linked list for creating adjacency list of the Graph
        adj = new list<int> [v];
    }
    
    void addEdge(int i, int j) {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    void BFS(int s);
    void DFS(int s);
};

void Graph::BFS(int s) {
        
        // creating a new visited array with all initially 0
        bool *visitedBFS = new bool[vertices];
        for(int i=0;i<vertices;i++) visitedBFS[i] = false;
        
        // taking queue DS for storing traversed elements
        list<int> queue;
        
        visitedBFS[s] = true;
        queue.push_back(s);
        
        list<int>::iterator i;
        
        cout<<"BFS traversal of the graph from vertex : "<<s<<" -> ";
        
        while(!queue.empty()) {
            
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();
            
            for(i=adj[s].begin(); i!=adj[s].end(); i++) {
                if(!visitedBFS[*i]) {
                    visitedBFS[*i] = true;
                    queue.push_back(*i);
                }
            }
            
        }
    cout<<"\n";
         
}

// Utility function for recursive DFS calls
void Graph::DFSutil(int v, bool visitedDFS[]) {
    
    visitedDFS[v] = true;
    cout<<v<<" ";
    
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++) {
        if(!visitedDFS[*i]) 
            DFSutil(*i, visitedDFS);
    }
    
}

void Graph::DFS (int s) {
    
    // creating a new visited array with all initially 0 (ie, not visited)
    bool *visitedDFS = new bool[vertices];
    for(int i=0;i<vertices;i++) visitedDFS[i] = false;
    
    cout<<"DFS traversal of the graph from vertex : "<<s<<" -> ";
    
    // calling DFSutil function for traversal 
    DFSutil(s, visitedDFS);
    
    cout<<"\n";
}



int main()
{
    Graph g(6);
    
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(0,2);
    
    g.addEdge(1,0);
    g.addEdge(1,2);
    
    g.addEdge(2,0);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    
    g.addEdge(3,0);
    g.addEdge(3,2);
    
    g.addEdge(4,0);
    g.addEdge(4,2);
    
    g.addEdge(5,2);
    
    g.BFS(4);
    g.DFS(4);
    
    
    
    
    return 0;
}
