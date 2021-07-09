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


// Sample input : 
// 3
// 5
// 1 2 3 4 5 
// 4
// 1 1 1 2 
// 10
// 1 1 2 2 2 3 3 3 4 4

// Output : 
// 10
// 1
// 15


// TC : O(NlogN)
// SC : O(N)
