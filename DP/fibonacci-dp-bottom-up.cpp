#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long

int fib(long long num)
{
    if(num==0) return 0;
    if(num==1) return 1;
    return fib(num-2)+fib(num-1);
    
}

int main()
{
    fast
    
    // fibonacci with dp - bottom-up memoisation
    
    ll n;
    cin>>n;
    
    ll arr[n] = {};
    
    for(ll i=0;i<n;i++)
    {
        if(arr[i]==0) arr[i]=fib(i);
        cout<<arr[i]<<" ";
    }
    
    return 0;
}