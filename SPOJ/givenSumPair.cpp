// Count pairs with given sum


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int sum;
    
    cin>>n;
    cin>>sum;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;
    
    int ctr = 0;
    for(int i=0;i<n;i++) {
        ctr += mp[sum-arr[i]];
        if(sum-arr[i] == arr[i]) ctr--;
    }
    
    cout<<ctr/2;
    return 0;
}
