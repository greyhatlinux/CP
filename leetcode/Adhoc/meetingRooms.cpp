// Question : https://www.lintcode.com/en/old/problem/meeting-rooms-ii

#include<bits/stdc++.h>
using namespace std;

int minConfTable(int n, vector<pair<int, int>> arr) {

    if(n==1) return 1;

    sort(arr.begin(), arr.end()); //O(NlogN)

    int rooms = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(arr[0].second);

    for(int i=1;i<n;i++) {
        //earliest quiz ends sometime before 
        //so no rooms added, just the end time for earliest meeting is updated
        if(pq.top() <= arr[i].first) {
            pq.pop();
            pq.push(arr[i].second);
        }

        //no room empty when arr[i] meeting starts
        //so push the end time for new meeting in the new room
        else {
            rooms ++ ;
            pq.push(arr[i].second);
        }
    }
    return rooms;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        vector<pair<int, int>> meet(n);
        for(int i=0;i<n;i++) {
            cin>>meet[i].first;
            cin>>meet[i].second;
        }

        cout<<minConfTable(n, meet)<<"\n";
    }
    return 0;
}

// TC : O(NlogN)
// SC : O(N) in min heap

// Input : 
// 3

// 3
// 0 30 
// 5 10 
// 15 20 

// 1
// 2 10

// 7
// 0 30
// 20 100
// 30 35
// 40 80
// 50 55
// 55 150
// 100 120

// Expected Output : 
// 2
// 1
// 3
