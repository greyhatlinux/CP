//Undirected graph 

#include<bits/stdc++.h>
using namespace std;

#define V 9

int minDistance(int dist[], bool sptSet[]) {
    int mn = INT_MAX, mnIndex;

    for(int i=0;i<V;i++) {
        if(dist[i] <= mn && !(sptSet[i])) mn = dist[i], mnIndex = i; 
    }

    return mnIndex;
}

void printDistances(int distance[], int src) {
    cout<<"distance from "<<src<<" to "<<endl;
    for(int i=0;i<V;i++) cout<<"\t\t\t"<<i<<" -> "<<distance[i]<<endl;
}

void dijkstra(int graph[][V], int src) {
    
    //to store the min distance from src to i of distance[i]
    int distance[V];

    bool sptSet[V] = {false};

    for(int i=0;i<V;i++) distance[i] = INT_MAX;

    distance[src] = 0;

    for(int vert = 0; vert < V; vert++) {

        //pick the min distance vertex which is not yet processed 
        int u  = minDistance(distance, sptSet);
        
        //picked vertex is processed
        sptSet[u] = true;

        //update the distance values for all the adjacent vertices in distance array
        for(int i=0; i<V; i++) {

            //update only if it is not already in sptSet
            //if there exists an edge to another vertex
            //distance od picked vertex is non infinity
            //distance to i, from source is < previous distance
            if(!sptSet[i] && graph[u][i] && distance[u] != INT_MAX && distance[u] + graph[u][i] < distance[i]) {
                distance[i] = distance[u] + graph[u][i];
            }
        }
    }
    printDistances(distance, src);
}

int main()
{
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
    dijkstra(graph, 0);
    return 0;
}

// TC : O(V^2)
