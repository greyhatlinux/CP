// Adjacency matrix
// bi-directional graph traversal with adj matrix


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V = 5;
    bool graph[V][V] = {
    { 0, 1, 0, 0, 1 },
    { 1, 0, 1, 1, 1 },
    { 0, 1, 0, 1, 0 },
    { 0, 1, 1, 0, 1 },
    { 1, 1, 0, 1, 0 }
    };

    for(int i=0;i<V; i++) {
        cout<<i<<"->";
        for(int j=0;j<V; j++) {
            if(graph[i][j]) cout<<j<<",";
        }
        cout<<endl;
    }

}
