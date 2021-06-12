// Question : Given an infinite array, with first n places filled with n sorted integers, and rest with -1
// find a search value 'k' and return its index in the original array, in O(logn) time.


#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int endOfList(int arr[]) {
    int l,r;
    l=0; r=1;

    // r = r*2;
    while(arr[r]>0) {
        l = r;
        r = r*2;
    }

    while(r-l > 1) {
        int mid = (l+r)/2;
        if(arr[mid]>0) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    //0-indexed array, so return l+1;
    return l+1;
}

int binarySearch(int arr[],int l, int r, int k) {
    if(arr[l]==k) return l;
    if(arr[r]==k) return r;

    if((r-l==1) && (k>arr[l]) && (k<arr[r])) return -1;

    int mid = (l+r)/2;
    if(arr[mid] > k) r =mid;
    else if(arr[mid]<k) l = mid;
    else return mid;

    return binarySearch(arr, l, r, k);
}

int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int end = endOfList(arr);

        if(arr[end-1]<k || arr[0]>k) {
            cout<<k<<" not in the array\n";
            continue;
        }
        else {
            if(binarySearch(arr, 0, end, k)+1) cout<<binarySearch(arr, 0, end, k)+1<<endl;
            else cout<<k<<" not in the array\n";
        }
    }
    return 0;
}

// TC : O(logn)
// SC :O(1)


// Sample input 
// 5
// 20 80
// 1 2 3 4 5 60 70 80 90 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 20 55
// 1 2 3 4 5 60 70 80 90 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 20 44
// 1 2 3 4 5 60 70 80 90 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 20 5
// 1 2 3 4 5 60 70 80 90 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 20 1
// 1 2 3 4 5 60 70 80 90 100 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

