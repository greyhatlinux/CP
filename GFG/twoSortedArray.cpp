// Question : https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

#include<bits/stdc++.h>
using namespace std;

// -------------------------------M1--------------------------------------
// TC : O(m+n)
// SC : O(1)


// int median(int n, int *arr1, int *arr2){
//     int merge[2*n];
//     int p1 = 0, p2 = 0, i = 0;
//     while(p1 < n && p2 < n) {
//         if(arr1[p1] <= arr2[p2]) merge[i] = arr1[p1], p1++;
//         else merge[i] = arr2[p2], p2++;
//         i++;
//     }

//     while(p1 != n) {
//         merge[i] = arr1[p1];
//         i++; p1++; 
//     }

//     while(p2 != n) {
//         merge[i] = arr2[p2];
//         i++; p2++;
//     }

//     return (merge[n] + merge[n-1])/2;
// }


// -------------------------------M1--------------------------------------

// -------------------------------M2--------------------------------------

// TC : O(logN)
// SC : O(1)

int getMedian(int *arr, int n) {
    if(n&1) return arr[n/2];
    else return (arr[n/2] + arr[n/2 -1])/2;
}

int median(int n, int *arr1, int *arr2) {

    if(n<=0) return -1;
    if(n==1) return (arr1[0] + arr2[0])/2;
    if(n==2) return ((max(arr1[0], arr2[0]) + min(arr1[1], arr2[1]))/2);

    int m1, m2;

    m1 = getMedian(arr1, n);
    m2 = getMedian(arr2, n);

    if(m1 == m2) return m1;

    if(m1 < m2) {
        if(n&1) return median(n - n/2, arr1 + n/2, arr2 );
        else return median(n - n/2 + 1, arr1 + n/2 -1, arr2);
    }

    //if m1>m2, median must lie between a1[0...m1] ans a2[m2...n]
    else {
        if(n&1) return median(n - n/2, arr1, arr2 + n/2);
        else return median(n - n/2 + 1, arr1, arr2 + n/2 - 1);
    }
}

// -------------------------------M2--------------------------------------

// -------------------------------M3--------------------------------------

// TC:O(NlogN)
// SC : O(1)

// int median(int n, int *arr1, int *arr2) {
//     int p1 = n-1;
//     int p2 = 0;

//     while(arr1[p1] > arr2[p2] && p1 >-1 && p2 < n) swap(arr1[p1--], arr2[p2++]);

//     sort(arr1, arr1+n);
//     sort(arr2, arr2+n);

//     return (arr1[n-1]+arr2[0])/2;
// }

// -------------------------------M3--------------------------------------


int main()
{
    int n;
    cin>>n;
    int arr1[n], arr2[n];
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];
    cout<<median(n, arr1, arr2)<<"\n";
    return 0;
}
