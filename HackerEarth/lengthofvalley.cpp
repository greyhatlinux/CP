#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi(a,b) for(ll i=(a); i<b; i++)


void solveM1(int n, int arr[]) {
    int left, right;
    fi(0,n) {

        // left pattern
        left = i;
        while(left>0 && arr[left-1] > arr[left]) {
            left--;
        }
        // right pattern 
        right = i;
        while(right<n-1 && arr[right] < arr[right+1]) {
            right++;
        }
        cout<<right-left+1<<" ";
    }
    cout<<"\n";

}

void solveM2(int n, int arr[]) {
    int pref[n], suff[n];

    // building the prefix array
    pref[0]=1;
    fi(1,n) {
        if(arr[i-1] > arr[i]) pref[i] = pref[i-1]+1;
        else pref[i]=1;
    }

    // building the suffix array
    suff[n-1]=1;
    for(int j=n-2;j>=0;j--){
        if(arr[j] < arr[j+1]) suff[j] = suff[j+1] + 1;
        else suff[j]=1;
    }
    
    fi(0,n) cout<<suff[i]+pref[i]-1<<" ";
    cout<<"\n";
}


int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];

        // solveM1(n, arr);
        solveM2(n, arr);
    }

    return 0;
}

// M1 is brute force approach, taking O(n^2) time
// for every index i, it tries to match the left and right pattern for the valley condition

// M2 is the optimised version, using DP
// it makes the prefix and suffix array for each index, 
// and then simply calculates the span of prefix and suffix for each index
