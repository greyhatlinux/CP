#include<bits/stdc++.h>
using namespace std;

void swapNum(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int n, int *arr) {
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[i]) swapNum(&arr[i], &arr[j]);     
        }   
    }
}

int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        selectionSort(n, arr);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

// TC : O(N^2)
//maintains two sub-arrays, a sorted and an unsorted array
