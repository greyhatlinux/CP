#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)
#define endl "\n"


int nestedLoop(int arr[], int n) {
    int ctr = 0;
    fi(0,n-1) {
        for(int j=i+1;j<n;j++) if(arr[i]>arr[j]) ctr++;
    }
    return ctr;
}

//directly called from main
int mergeSort(int arr[], int n);

//recursively called function
int mergeSortUtil(int arr[], int left, int right);

//function to merge the arrays
int mergeArray(int arr[], int left, int mid, int right); 



int mergeSort(int arr[], int n) {
    int inversions = 0;
    inversions += mergeSortUtil(arr, 0, n-1);
    return inversions;
}

int mergeSortUtil(int arr[], int left, int right) {
    int mid, inv=0;

    //base case
    //array still has more than one element
    if(left<right){
        mid = (left+right)/2;

        inv += mergeSortUtil(arr, left, mid);
        inv += mergeSortUtil(arr, mid+1, right);
        inv += mergeArray(arr, left, mid, right);
    }

    //array is left with single elements left on left and right side
    return inv;
}

int mergeArray(int arr[], int left, int mid, int right) {
    int size = (right-left)+1, inv = 0;
    int temp[size];

    int i,j,k;

    //controls the left array
    i=left;
    //controls the right array
    j=mid+1;
    // controls the auxiliary array
    k=0;

    //supposing array has only unique values
    while(i<=mid && j<=right){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }

        //case : arr[i]>arr[j] (case of valid inversion)
        else {
            temp[k++] = arr[j++];
            inv += (mid+1-i);
        }
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];

    // copying the temp array to real array
    //this is important, since the changed array is propagated upwards, and is further computed for inversions
    int p=0;
    fi(left, right+1) arr[i] = temp[p++];

    return inv;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    fi(0,n) cin>>arr[i];
    cout<<"Inversions with :\n";
    cout<<"Nested loop approach :"<<nestedLoop(arr,n)<<endl;
    cout<<"Merge Sort approach: "<<mergeSort(arr,n)<<endl;
    return 0;
}

// nested loop approach has TC :(N^2)
// This merge sort approach has TC : O(nlogn) and SC :O(N) for temp array
//Merge sorts the original array (though this can be avoided)


// Sample input :
// 7
// 3 43 54 6 2 52 4

// answer -> 11 conversions 
