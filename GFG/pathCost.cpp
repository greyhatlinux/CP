// Question : https://www.geeksforgeeks.org/calculate-cost-of-visiting-all-array-elements-in-increasing-order/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int x;
    map<int, int> mp;
    
    for(int i=0;i<n;i++) {
        cin>>x;
        mp[x] = i;
    }
    
    int cost = 0, ptr = 1, curr, prev;

    for(int i=0;i<n;i++, ptr++){
        auto itr = mp.find(ptr);
        curr = itr->second;
        cost = cost + abs(curr-prev);
        prev = curr;
    }
    
    cout<<cost<<endl;
    return 0;
}

// Searching in a map takes O(log n) time, and for n elements it will take n*logn
// Time complexity : O(nLogn)
