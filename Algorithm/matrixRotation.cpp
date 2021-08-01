#include<bits/stdc++.h>
using namespace std;

const int n = 4;

void solve(int mat[][n]){

    int mid = n/2, temp;

    //anti clockwise rotation
    // for(int i=0;i<mid;i++){
    //     for(int j=i;j<n-i-1;j++){
    //         temp = mat[i][j];
    //         mat[i][j] = mat[j][n-1-i];
    //         mat[j][n-1-i] = mat[n-1-i][n-1-j];
    //         mat[n-1-i][n-1-j] = mat[n-1-j][i];
    //         mat[n-1-j][i] = temp;
    //     }
    // }

    //clockwise rotation
    for(int i=0;i<mid;i++){
        for(int j=i;j<n-1-i;i++){
            temp = mat[i][j];
            mat[i][j] = mat[n-1-j][i];
            mat[n-1-j][i] = mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j] = mat[j][n-1-i];
            mat[j][n-1-i] = temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<mat[i][j]<<" \t";
        cout<<endl;
    }
}


int main()
{

    int mat[][n] = {{1,2,3,4},
                    {5,6,7,8},
                    {9,10,11,12},
                    {13,14,15,16}};
        
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<mat[i][j]<<" \t";
        cout<<endl;
    }
    solve(mat);
    return 0;
}
