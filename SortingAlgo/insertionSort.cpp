#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, int *arr) {
    for(int i=1; i<n;i++) {
        int key = arr[i];
        int k = i-1;

        while(k >= 0 && arr[k]>key) {
            arr[k+1] = arr[k];
            k--;
        }

        arr[k+1] = key;        
    }
}

int main() 
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        insertionSort(n, arr);
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
