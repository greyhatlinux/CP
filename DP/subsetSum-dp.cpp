#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int *arr, int n, int sum) {

    bool dp[n+1][sum+1];

    //if required sum is 0, it is always possible
    for(int i=0;i<n+1;i++) dp[i][0] = true;

    //any required sum is not possible with subset with 0 elements
    for(int i=0;i<sum+1; i++) dp[0][i] = false;

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<sum+1;j++) {

            //if the current element value is greater than the required sum, here j
            //we copy the previous value's result
            if( j < arr[i-1])
            dp[i][j] = dp[i-1][j];

            //else if sum > current element
            //we will see if any previous states have experienced sum = j, or sum = j - arr[i]
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][sum];
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        if(subsetSum(arr, n, k)) cout<<"True\n";
        else cout<<"False\n";
    }
    return 0;
}
