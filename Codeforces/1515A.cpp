#include<bits/stdc++.h>
using namespace std;

void solve(int n, int x, int arr[]){
    int rw=x, sum=0, len=0;
    for(int i=0;i<n;i++) sum += arr[i];
    if(sum == x) {
        cout<<"NO\n"; 
        return;
    }
    else 
        cout<<"YES\n";
    while(len<n) {
        if(arr[len]==rw) swap(arr[len], arr[len+1]);
        rw -= arr[len];
        len++;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return;

}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        solve(n,x,arr);
    }
    return 0;
}
