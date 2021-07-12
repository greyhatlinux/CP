#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int n, int *arr) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            int l = j, r = j+1;
            if(arr[l] > arr[r]) swap(&arr[l], &arr[r]);
        }
    }
}

void bubbleSortOptimised(int n, int *arr) {
    bool change = true;
    for(int i=0;i<n;i++) {
        if(change) {
            change = false;
            for(int j=0; j<n-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(&arr[j], &arr[j+1]);
                    change = true;
                }
            }
        }
        else break;
    }
}

int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];

        // bubbleSort(n, arr);
        bubbleSortOptimised(n, arr);

        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

// TC : O(N^2)
// bubble Sort takes O(N^2) for all arrays, 
// but bubble Sort optimised takes O(N) for already sorted arrays, due to just a slight modification
