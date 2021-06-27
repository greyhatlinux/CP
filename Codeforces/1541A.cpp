#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve(int n){
    
    if (n<2) {
        cout<<1<<endl;
        return;
    }

    int arr[n] = {0};
    int l=0, r=1;

    //if n is dd
    if(n%2){
        while(r<(n-1)-2){
            arr[r]=l+1;
            arr[l]=r+1;
            l = r+1;
            r = r+2;
        }

        //we'll have last 3 empty cells
        arr[l] = n; l++;
        arr[l] = l; l++;
        arr[l] = l;
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        return;
    }

    //if n is even
    else {
        while(r<n){
            arr[l] = r+1;
            arr[r] = l+1;
            l = r+1;
            r = r+2;
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        return;
    }
}

int main()
{
    int tc; cin>>tc; while(tc--){
        int n;
        cin>>n;
        solve(n);
        cout<<endl;
    }
    return 0;
}

// drawbacks:
// 1. separate codes for even and odd
// 2. storing numbers in array unnecessarily, when just printing can work
// 3. very long code, can be done in few lines
