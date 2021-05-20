// Find the subarray with continuous non-negative and having elements maximum sum

#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a); i<b; i++)
#define endl "\n"

void solve(int arr[], int n){
    int ans[n];
    fi(0,n) ans[i] = 0;


    int currMax = 0, globalMax = 0, ansIndex;

    if(arr[0]>=0) ans[0] = arr[0];
    else ans[0] = 0;

    fi(1,n) {
        if(arr[i]>0){
            ans[i] = max(arr[i], arr[i]+ans[i-1]);
            currMax = max(ans[i], currMax);
            
        }
        else {
            ans[i] = 0;
            currMax = 0;
        }

        if(globalMax<=currMax) {
            globalMax = max(currMax, globalMax);
            ansIndex = i;
        }
    }
    cout<<globalMax<<endl;

}

int main()
{
    int tc; cin>>tc; while(tc--){
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];
        solve(arr, n);
        
    }
    return 0;
}
