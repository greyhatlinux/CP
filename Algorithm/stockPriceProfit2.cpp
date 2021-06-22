#include<bits/stdc++.h>
using namespace std;

// int solve(int *arr, int size) {
    
//     int buy, sell, profit = 0;

//     //setting tentative buy at arr[0]
//     //if the 1st pos is local maxima, then only this will be executes, else this will be dropped
//     buy = arr[0];
//     cout<<"maxima "<<buy<<" "<<sell<<endl;
//     //int the array, we need to find local minima, and maxima
//     for(int i=1;i<size-1; i++) {

//         //if arr[i-1]<arr[i]>arr[i+1] -> local maxima
//         if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) {
//             sell = arr[i];
//             profit += (sell-buy);

//             //this indicates executed transaction 
//             buy = sell = -1;
//         }

//         //if arr[i-1]>arr[i]<arr[i+1] -> local minima
//         if(arr[i-1]>arr[i] && arr[i]<arr[i+1]) {
//             buy = arr[i];
//             while(!(arr[i-1]<arr[i] && arr[i]>arr[i+1])) i++;
//             sell = arr[i];
//             profit += (sell-buy);
               //this indicates executed transaction 
//             buy = sell = -1;
//         }
//     }
    
//     //sell is pending
//     if(buy != -1) {
//         sell = arr[size-1];
//         if(sell>buy) profit += (sell-buy);
//     }
//     return profit;
// }

int solve(int arr[], int n) {
    
    //tackiling edge cases
    if(n<2) return 0;

    int buy, sell, profit = 0;

    //tentaive buy at first price
    buy = sell = arr[0];

    for(int i=1;i<n;i++) {
        //at every loop iteration, buy == sell
        //only two possible cases with arr[i]

        if(arr[i]>buy) {
            //then we'll sell the stock
            sell = arr[i];
            profit += (sell-buy);
            buy = arr[i];
        }

        else if(arr[i]<sell){
            //we'll find new buy point
            buy = sell = arr[i];
        }
    }
    return profit;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(arr, n)<<endl;
    return 0;
}

// TC : O(N)
// SC : O(1)
// with both the implementations

// Sample input : 
// 7
// 1 7 17 5 3 6 4

// Output : 17
