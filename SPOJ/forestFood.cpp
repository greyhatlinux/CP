#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a); i<b; i++)

int main() {
    
    int n, c;
    cin>>n>>c;
    int arr[n];
    fi(0,n) cin>>arr[i];
    
    int dp[n], mx = 0;
    fi(0,n){
        int var = 0, food = 0;
        for(int j=i;j<n;j++){
            if(food+arr[j] <= c) {
                food += arr[j];
                var++;
            }
        }
        if(mx<var) mx = var;
        dp[i] = var;
    }

    cout<<mx;

}
