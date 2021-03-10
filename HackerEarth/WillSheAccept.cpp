#include<bits/stdc++.h>
using namespace std;

bool isAMatch(string boy, string girl, int l1, int l2) {

	// Recursive approach exceeds time limit -----------------
	// if(l1==0) return true;
	// if(l2==0) return false;

	// if(boy[l1-1] == girl[l2-1]) {
	// 	return isAMatch(boy, girl, l1-1, l2-1);
	// }

	// return isAMatch(boy, girl, l1, l2-1);

	// Iterative approach is accepted ------------------------
	int i,j=0;
	for(i=0;i<l1 && j<l2;j++){
		if(boy[i]==girl[j]) i++;
	}

	return (i==l1);
}



int main()
{
	int tc; cin>>tc; while(tc--) {
		string guy, gal;
		cin>>guy>>gal;

		int l1 = guy.length();
		int l2 = gal.length();

		if(isAMatch(guy, gal, l1, l2)) cout<<"Love you too\n";
		else cout<<"We are only friends\n";
	
	}
	return 0;
}
