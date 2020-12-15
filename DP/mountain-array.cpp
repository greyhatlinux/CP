
// Minumum removal for making a mountain array
// Link to Question : https://www.geeksforgeeks.org/minimum-removals-required-to-convert-given-array-to-a-mountain-array/


#include<bits/stdc++.h>
using namespace std;

#define testcase int tc; cin>>tc; while(tc--)

int MountainArray(int A[], int len)
{
    int leftinc[len] = {0}, rightinc[len] = {0};
    
    // composing left increasing array
    for(int i=1;i<len-1;i++){
        if(A[i]>A[i-1]) leftinc[i] += leftinc[i-1]+1;
        else leftinc[i] = leftinc[i-1];
    }

    // composing right increasing
        for(int i=len-2;i>0;i--){
        if(A[i]>A[i+1]) rightinc[i] += rightinc[i+1]+1;
        else rightinc[i] = rightinc[i+1];
    }
    
    // summing up inc arrays and finding length of mountain array
    int mx=0;
    for(int i=0;i<len;i++){
        if(leftinc[i]>0 && rightinc[i]>0) mx = max(mx, leftinc[i]+rightinc[i]);
    }
    
    return ((len-1)-mx);
}

int main()
{
    testcase
    {
        int l;
        cin>>l;
        
        int arr[l];
        for(int i=0;i<l;i++) cin>>arr[i];
        
        int res = MountainArray(arr, l);
        cout<<res<<"\n";
    }
    return 0;
}
