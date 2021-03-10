#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	sort(arr, arr+n);

	int ctr=0;

	cout<<endl;
	for(int i=0;i<n;i++) {

		if(i==0) {
			if(arr[i+1]<arr[i]+k) ctr++;
		}

		else if (i==n-1) {
			if(arr[i-1]>arr[i]-k) ctr++;
		}
		
		else {
			if((arr[i-1]>=arr[i]-k) || (arr[i+1]<=arr[i]+k)) ctr++;
		}
	}

	cout<<ctr<<" students need to worry!\n";
	cout<<n-ctr<<" students should relax!";

	return 0;
}
