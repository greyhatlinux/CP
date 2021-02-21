// Giv the length of the longest substring 
// with adjacent element difference atmost 1


#include<bits/stdc++.h>
using namespace std;

void solve(int a[], int len) {
    int currlen=1, mxlen=1;
    sort(a, a+len);
    for(int i=1;i<len;i++) {
        if(a[i]-a[i-1] <= 1) {
            currlen++;
            mxlen = max(currlen, mxlen);
        }
        else 
            currlen = 1;
    }
    
    cout<<mxlen<<endl;
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    solve(arr, n);
    return 0;
}
