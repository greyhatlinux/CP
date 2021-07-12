#include<bits/stdc++.h>
using namespace std;

// bool subsetSum(int *arr, int n, int sum) {
    
//     if(sum == 0) return true;
//     if(n == 0) return false;

//     if(arr[n-1] > sum) return subsetSum(arr, n-1, sum);

//     return (subsetSum(arr, n-1, sum-arr[n-1]) || subsetSum(arr, n-1, sum));
// }

bool subsetSum(int *arr, int n, int sum, int begin) {

    //base cases
    if(sum == 0) return true;
    if(begin == n) return false;

    //if current element is greater than thge required sum, ignore it 
    if(arr[begin] > sum) return subsetSum(arr, n, sum, begin+1);

    //two cases, 
    //either take the number, or do not take the number
    return (subsetSum(arr, n, sum-arr[begin], begin+1) || subsetSum(arr, n, sum, begin+1) );
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        if(subsetSum(arr, n, k, 0)) cout<<"True\n";
        else cout<<"False\n";
    }
    return 0;
}

// This is recursion
// TC O(2^n) 
