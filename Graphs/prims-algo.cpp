#include<bits/stdc++.h>
using namespace std;

#define V 5

int minKey(int MST[], int dist[]) {
    int mn = INT_MAX, index;
    for(int i=0;i<V;i++) {
        if(!MST[i] && dist[i] < mn) {
            mn = dist[i];
            index = i;
        }
    }

    //returns the index which is to be included in the MST 
    return index;
}

void printMST(int parent[], int graph[][V]) {
    cout<<"fr -> to : weight\n";
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" -> "<<i<<" : "<<graph[i][parent[i]]<<endl;
    }
}

void primsMST(int graph[][V]) {

    //to store set of vertices in MST
    int MST[V];

    int dist[V];

    int parent[V];

    //initially no vertex in mst, and all distances are infinite
    for(int i=0;i<V;i++) dist[i] = INT_MAX, MST[i] = false;

    dist[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++) {
        
        //next minimum node
        int u = minKey(MST, dist);

        //inluded in the MST
        MST[u] = true;

        for(int i=0;i<V;i++) {
            if(graph[i][u] && !MST[i] && graph[u][i] < dist[i]) {
                parent[i] = u, dist[i] = graph[u][i];
            }
        }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 

    primsMST(graph);
    return 0;
}

// expected output : 
// fr -> to : weight
// 0 -> 1 : 2
// 1 -> 2 : 3
// 0 -> 3 : 6
// 1 -> 4 : 5

// TC : O(V^2)
