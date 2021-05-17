#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int subseq(string s1, string s2, int l1, int l2) {

    if(l1==0 || l2==0) return 0;
    if(s1[l1-1] == s2[l2-1]) return 1+subseq(s1, s2, l1-1, l2-1);
    else {
        return max(subseq(s1, s2, l1-1, l2), subseq(s1, s2, l1, l2-1));
    }

}

int subseqDP(string s1, string s2, int l1, int l2) {

    int col, row;
    l1>l2? (col=l1+1, row = l2+1) : (col=l2+1, row=l1+1);
    int dp[row][col];

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1]; //considering s1.length < s2.length; ie, s1 is in the row, amd s2 is in the col
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

        // string s3;
        // for(int i=row-1;i>0;i--) {
        //     for(int j=col-1;j>col;j--) {
        //         if(dp[i-1][j] == dp[i][j-1]) s3.push_back(s1[j]);
        //     }
        // cout<<endl;
        // }
        // cout<<s3<<endl;


    return dp[row-1][col-1];
}


int main()
{
    string str1, str2;
    cin>>str1>>str2;
    
    int l1 = str1.length();
    int l2 = str2.length();


    cout<<subseqDP(str1, str2, l1, l2)<<endl;
    return 0;
}
