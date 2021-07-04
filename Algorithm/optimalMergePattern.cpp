#include<bits/stdc++.h>
using namespace std;

int optimalMerge(vector<int> arr, int n) {
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0;i<n;i++) q.push(arr[i]);

    int merge = 0, ans = 0;
    while(q.size() >1) { 
        merge = 0;
        merge += q.top(); q.pop();
        merge += q.top(); q.pop();
        ans += merge;
        q.push(merge);
    }
    return ans;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<optimalMerge(arr, n)<<"\n";
    }
    return 0;
}

