#include<bits/stdc++.h>
using namespace std;

//uses dp array, hence takes up O(N) space
int solve1(int *arr, int n) {

    //our aim is to fill the dp array

    //filling up base cases 
    if(n==0) return 0; 
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);

    //1D dp array
    int dp[n];

    //initals of dp array
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i=2;i<n;i++) {
        dp[i] = max(dp[i-2]+arr[i], dp[i-1]);
    }
    
    return dp[n-1];
}

//doesn't use dp array, just 2 variables to track the last values, thus Space is O(1)
int solve2(int *arr, int n){

    //instead of dp array, we'll maintain 2 variables
    int dp2, dp1;

    int loot = 0;

    //base cases
    if(n==0) return 0;
    if(n==1) return arr[0];
    if(n==2) return max(arr[0],arr[1]);

    dp2 = arr[0];
    dp1 = max(arr[0], arr[1]);

    for(int i=2;i<n;i++) {
        loot = max(dp2+arr[i], dp1);
        dp2 = dp1;
        dp1 = loot;
    }

    return loot;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve1(arr, n)<<endl;
    cout<<solve2(arr, n)<<endl;
    return 0;
}

// TC :O(N) for both appraches

// Sample input : 
// 6
// 5 5 10 100 10 5
// output : max loot should be 110 
