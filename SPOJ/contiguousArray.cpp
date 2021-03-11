// Length of the largest subarray with contiguous elements
// Link : https://www.geeksforgeeks.org/length-largest-subarray-contiguous-elements-set-1/

#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
    
    // length of longest contiguous array is minimum 1, so pre initialised
    int len = 1;
    
    for(int i=0;i<n-1;i++) {
        int mn = arr[i], mx = arr[i];
        
        for(int j=i+1; j<n; j++) {
            
            // calculate the min and max of each possible 
            // subarray of the given array 
            
            mn = min(mn, arr[j]);
            mx = max(mx, arr[j]);
            
            // if the len of new sub array is greater, update the len
            if((mx-mn) == (j-i)) len = max(len, j-i+1);
        }
    }
    
    return len;
}


int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    cout<<solve(arr, n);
    return 0;
}
