https://leetcode.com/discuss/interview-question/406031/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[]) {
    set<int> s1;

    int ans = 0;
    for(int i=0;i<n;i++) {
        if(s1.find(arr[i]) == s1.end()) s1.insert(-arr[i]);
        else if(abs(arr[i]) > ans) ans = abs(arr[i]);
    }    
    return ans;                                                                                                       
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<solve(n, arr)<<"\n";
    }
    return 0;
}

// TC : O(N)
// SC : O(N)

// Another method with TC O(NlogN) can be applied, with SC O(1)
