#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fi(a,b) for(int i=(a); i<b;i++)

int solve(int n, int arr[]) {
    int local_max[n];
    int global_max = INT_MIN;
    local_max[0] = arr[0];
    fi(1,n) {
        local_max[i] = max(arr[i], arr[i]+local_max[i-1]);
        global_max = max(global_max, local_max[i]);
    }
    
    return global_max;
}

int main() 
{   
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];
        cout<<solve(n,arr)<<endl;
    }

    return 0;
}
