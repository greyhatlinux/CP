#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;

        //if n is odd
        if(n%2){
            cout<<"3 1 2 ";
            for(int i=4; i<=n; i+=2) cout<<i+1<<" "<<i<<" ";
        }   
        else {
            for(int i=1;i<=n;i+=2) cout<<i+1<<" "<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Advantage : 
// 1. No storage required
// 2. TC : O(N)
// 3. Minimal lines of code
