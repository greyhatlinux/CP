#include<bits/stdc++.h>
using namespace std;

int minCost(int n, int *arr){
    if(n<=2) return arr[0]+arr[1];

    priority_queue<int> pq;
    //note : pq by default is max heap, to turn it into min heap, we push -ve numbers
    for(int i=0;i<n;i++) pq.push(-arr[i]);

    int cost = 0;
    while(pq.size()> 1){
        int r1 = pq.top(); pq.pop();
        int r2 = pq.top(); pq.pop();
        int rope = r1+r2;
        cost += -(rope);
        pq.push(rope);
    }
    return cost;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<minCost(n, arr)<<"\n";
    return 0;
}

// TC : O(NlogN)
