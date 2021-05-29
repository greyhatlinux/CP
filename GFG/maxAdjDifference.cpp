// Question : https://www.geeksforgeeks.org/maximum-adjacent-difference-array-sorted-form/

#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a); i<b; i++)
#define endl  "\n"

int solve(int arr[], int n){
    sort(arr, arr+n);
    int diff = 0;
    fi(0,n-1) if(arr[i+1]-arr[i] > diff) diff = arr[i+1]-arr[i];
    return diff;
}

int solve2(int arr[], int n) {
    int mx=-1, diff=0, prev, curr;
    fi(0,n) if(arr[i]>mx) mx = arr[i];

    int a[mx] = {0};
    fi(0,n) a[arr[i]] = 1;

    int i=0;
    while(!a[i]) i++;
    prev = i; i++;

    for(; i<mx;i++) {
        while(!a[i]) i++;
        curr = i;
        if(curr-prev > diff) diff = curr - prev;
        prev = curr;

    }
    return diff;
}


int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        fi(0,n) cin>>arr[i];
        // cout<<solve(arr, n)<<endl;
        cout<<solve2(arr, n)<<endl;
    }

    return 0;
}

// solve does the job in O(nlogn) since this involves sorting the array
// solve2 does the job in O(n) since this doesn't do the sorting of the array
