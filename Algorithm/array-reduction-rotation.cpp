#include<bits/stdc++.h>
using namespace std;

int lastElement(int arr[], int n, int k) {
    if(n==1) return 1;

    long long nextPower = 1;
    while(nextPower <= n) nextPower *= 2;

    //right rotate
    if(k==1) return nextPower - n;

    //left rotate
    else if (k ==2 ) return 2*(n-(nextPower/2)) + 1;

    else return INT_MAX;

}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<lastElement(arr, n, k)<<endl;
    }
    return 0;
}

// TC :O(N)

// Sample input : 
// 2
// 5 2
// 1 2 3 4 5 
// 6 1
// 1 2 3 4 5 6

// expected output 
// 3
// 2
