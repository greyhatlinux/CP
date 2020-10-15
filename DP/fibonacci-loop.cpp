#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long


int main()
{
    fast
    
    // fibonacci without dp-----

    ll n;
    cin>>n;
    
    ll prev=1;
    ll curr=1;
    
    cout<<0<<" ";
    cout<<prev<<" ";
    for(ll i=0;i<n;i++)
    {
        i++;
        cout<<curr<<" ";
        
        curr = prev+curr;
        prev = curr-prev;
        
    }
    
    // fibonacci without dp -------

    
    return 0;
}