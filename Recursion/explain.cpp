#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int recur(int num)
{
    if(num==0) return 0;
    if(num==1) return 1;
    cout<<"recur "<<num-1<<" and "<<num-2<<"\n";
    return recur(num-1)+recur(num-2);
    
}

int main()
{
    fast
    
    int n;
    cin>>n;
    
    cout<<recur(n);
    return 0;
    
    
}