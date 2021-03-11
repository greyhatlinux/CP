#include<bits/stdc++.h>
using namespace std;

int solve(int a1[], int a2[], int l1, int l2) {
    
    int dp[l1+1][l2+1] = {0};

    // for(int i=0;i<=l1;i++) {
    //     for(int j=0;j<=l2;j++) {
    //         dp[i][j]=0;
    //     }
    // }

    for(int i=1;i<=l1; i++) {
        for(int j=1; j<=l2; j++) {
            if(a1[i]==a2[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = dp[i][j-1];
        }
    }
    
    int max_len=0;
    for(int i=0;i<=l1;i++) {
        for(int j=0;j<=l2;j++) {
            max_len = max(max_len, dp[i][j]);
        }
    }
    
    // max_len++; //ambiguous
    return max_len;
}


int main()
{
    int n1, n2;
    cin>>n1>>n2;
    
    int arr1[n1], arr2[n2];
    
    for(int i=0;i<n1;i++) cin>>arr1[i];
    for(int i=0;i<n2;i++) cin>>arr2[i];
    
    cout<<solve(arr1, arr2, n1, n2);
    
    return 0;
}
