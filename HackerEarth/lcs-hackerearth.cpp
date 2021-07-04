// link : https://www.hackerearth.com/problem/algorithm/lcs-1/

#include<bits/stdc++.h>
using namespace std;

int lcs(string a, int l1, string b, int l2) {
    int dp[l1+1][l2+1];
    int i,j;
    for(i=0;i<=l1;i++) {
        for(j=0;j<=l2;j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[l1][l2];
}

void longestSubs(vector<string> s, int n, vector<string> t, int q) {
    vector<string>::iterator nit;
    vector<string>::iterator qit;

    for(qit = t.begin(); qit != t.end(); qit++) {
        int mx = 0, len = 0;
        string a = *qit; 
        int l1 = a.length();
        for(nit = s.begin(); nit != s.end(); nit++) {
            string b = *nit;
            int l2 = b.length();
            len  = lcs(a, l1, b, l2);
            mx = max(mx, len);
            if(mx == l1) break;
        }
        cout<<mx<<"\n";        
    }

}

int main() 
{
	int n; cin>>n;
    vector<string> str(n);
	for(int i=0;i<n;i++) cin>>str[i];

	int q; cin>>q;
    vector<string> strq(q);
    for(int i=0;i<q;i++) cin>>strq[i];

    longestSubs(str, n, strq, q);

	return 0;
}
