#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool solve (ll red, ll blue, ll d) {
    if(max(red,blue)<=min(red,blue)*(d+1)) return true;
    else return false;

}

int main()
{
    int tc; cin>>tc; while(tc--) {
        ll r,b,d;
        cin>>r>>b>>d;
        if(solve(r,b,d)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
