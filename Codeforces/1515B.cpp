#include<bits/stdc++.h>
using namespace std;

 
bool isSquare(int x) {
    long long sr;
    sr = sqrt(x);
    return sr*sr == x;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n; cin>>n;

        if(n&1) {
            cout<<"NO\n";
            continue;
        }

        n = n/2;
        if(isSquare(n)){
            cout<<"YES\n"; 
            continue;
        }

        if(!(n&1) && isSquare(n/2)) {
            cout<<"YES\n"; 
            continue;
        }
        cout<<"NO\n";


    }
    return 0;
}
