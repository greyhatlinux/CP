#include<bits/stdc++.h>
using namespace std;

void dfsUtil(vector<vector<int>> mat, int u, int n, vector<int>& vis){
    vis[u] = true;
    for(int i=0;i<n;i++){
        if(!vis[i] && mat[u][i]) {
            dfsUtil(mat, i, n, vis);
            cout<<i<<" ";
        }
    }
}

void printDFS(vector<vector<int>> mat, int m, int n){
    vector<int> vis(m, false);
    dfsUtil(mat, 0, n, vis);
    cout<<0<<endl;
}

int main()
{
    int m,n;
    // cin>>m>>n;
    m = n = 5;
    vector<vector<int>> mat(m, vector<int>(n,0));
    mat = {{0,1,1,0,0,},
            {1,0,0,0,0},
            {1,0,0,1,1},
            {0,0,1,0,0},
            {0,0,1,0,0}};
    printDFS(mat, m, n);
    return 0;   
}

// Expected Output : 1 3 4 2 0
