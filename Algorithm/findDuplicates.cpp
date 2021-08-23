#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // m1 -> don't know the range
    // TC : O(N) SC : O(N)
    // unordered_map<int, int> mp;
    // for(int i=0;i<n;i++){
    //     if(mp.count(arr[i])) cout<<arr[i]<<" ";
    //     else mp[arr[i]]++;
    // }

    //m2 -> know the range
    //TC : O(N) SC : O(1)
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])] >= 0) arr[abs(arr[i])] = -arr[abs(arr[i])];
        else cout<<abs(arr[i])<<" ";
    }

    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";



    return 0;
}
