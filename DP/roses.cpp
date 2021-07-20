// Question : https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roses-for-valentine-4a795f72/


#include<bits/stdc++.h>
using namespace std;
 
int solve(int n, vector<int>& arr) {

    //prefix array tells the length of max subarray ending at ith position
    //suffix array tells the length of max subarray if that element is chosen
	vector<int> pre(n,1), suf(n,1);
 
	for(int i=1;i<n;i++) pre[i] = arr[i] > arr[i-1] ? 1 + pre[i-1] : 1;
	for(int i=n-2; i>=0; i--) suf[i] = arr[i] < arr[i+1] ? 1 + suf[i+1] : 1;
 
	int res = INT_MIN;
	for(int i=0;i<n;i++) res = max(res, pre[i]);
 
	for(int i=0;i+2<n;i++) res = max(pre[i] + suf[i+2], res);
    
	return res;
}
 
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<solve(n, arr)<<"\n";
	return 0;
}

// TC : O(N)
