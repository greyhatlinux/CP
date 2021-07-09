// Question : https://leetcode.com/discuss/interview-question/364618/

#include<bits/stdc++.h>
using namespace std;


int minSteps(int n, int arr[]) {

    sort(arr, arr+n);

    int digits = 1, answer = 0, curr = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        if(curr > arr[i]) {
            answer += digits; 
            curr = arr[i];
        }
        digits++;
    }
    return answer;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<minSteps(n, arr)<<"\n";
    }
    return 0;
}

// TC : O(NlogN)
// SC : O(N)
