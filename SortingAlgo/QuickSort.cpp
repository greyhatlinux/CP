#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a); i<b; i++)

//variable names declared in function definition doesn't matter  
void quickSort(vector<int> &array, int lowindex, int highindex);

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        fi(0,n) cin>>arr[i];
        quickSort(arr, 0, n-1);
        fi(0,n) cout<<arr[i]<<" ";
        cout<<endl;

    }
    return 0;
}

//left and right are 0-indexed
int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left-1;

    // j<right, because arr[right] is pivot itself
    for(int j=left; j<right; j++) {
        if(arr[j]<pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;

}

void quickSort(vector<int> &arr, int low, int high) {
    if(low<high) {
        int pointOfPartition = partition(arr, low, high);
        quickSort(arr, low, pointOfPartition-1);
        quickSort(arr, pointOfPartition+1, high);
    }
}




// TC ->
// worst case  : O(n^2)
// best case   : O(nlogn)
// average case: O(nlogn)

// SC : O(1) because it performs in-place sorting, space is only for recursive calls


// Sample Input : 
// 2
// 7
// 10 2 5 12 25 4 8
// 6
// 5 6 54 32 9 8
