#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n) {
    int profit = 0;
    int buy, sell;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[j] - arr[i] > profit) {
                buy = arr[i]; sell = arr[j];
                profit = arr[j]-arr[i];
            }

        }
    }

    // cout<<"Buy on : "<<buy<<" Sell on : "<<sell<<endl;
    return profit;
}

int stockProfit(int arr[], int n) {
    //maxDiff and minElement so far
    int profit = -1, maxDiff = 0, minElem = arr[0];
    for(int i=1;i<n;i++) {
        minElem = min(arr[i], minElem);
        maxDiff = max(profit, arr[i]-minElem);
        if(maxDiff>profit) profit = maxDiff;
    }

    // cout<<maxDiff<<" "<<minElem<<endl;
    return profit;

}

int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<stockProfit(arr,n)<<endl;
    // cout<<maxProfit(arr,n)<<endl;
    return 0;
}

// TC for maxProfit is O(n^2)
// TC fpr stockProfit is O(N)

// SC : O(1) for both

// Sample Input
// 7
// 10 250 800 6 1 16 120
