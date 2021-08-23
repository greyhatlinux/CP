#include<bits/stdc++.h>
using namespace std;

void solve(int n, int *arr){
    int i=0, j = n-1;
    while(i<j){
        while(i<j && arr[i] < 0) i++;
        while(i<j && arr[j] > 0) j--;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(n, arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}

// input : 
// 8
// 2 3 -5 6 8 -2 -1 5

// TC : O(N)
// SC : O(1)
