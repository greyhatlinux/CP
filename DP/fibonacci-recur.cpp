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
    
    // fibonacci with recursion -------
    
    ll n;
    cin>>n;
    for(int i=0;i<n;i++) cout<<fib(i)<<" ";
    
    
    // fibonacci with recursion -------
    
    return 0;
}