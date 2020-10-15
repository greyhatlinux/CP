#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define testcase long long tc; cin>>tc; while(tc--)
int main()
{
    testcase
    {
        ll n,k;
        cin>>n>>k;
        
        ll arr[n];
        for(ll i=0;i<n;i++) cin>>arr[i];
        
        sort(arr, arr+n);
        
        for(ll j=n-2;k!=0;j--)
        {
            arr[n-1] += arr[j];
            k--;
        }
        
        cout<<arr[n-1]<<"\n";
        
    }