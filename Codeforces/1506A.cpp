#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll n, ll m, ll cell) {
    ll r, c, row, col;
    c = ceil((float)cell/n);
    r = cell%n;

    if(r==0) r = n; 

    row = r-1;
    col = c-1;

    return (row*m + col + 1);
}

int main()
{

    int tc; cin>>tc; while(tc--){
        ll n,m,x;
        cin>>n>>m>>x;
        cout<<solve(n,m,x)<<endl;

    }
    return 0;
}
