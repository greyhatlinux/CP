// Question :Construct lexicographically smallest palindrome
// Link : https://www.geeksforgeeks.org/construct-lexicographically-smallest-palindrome/


#include<bits/stdc++.h>
using namespace std;

string makeLexPall(string s) {
    long long len, r,l;
    len = s.length();
    l=0;r=len-1;
    while(l<=r) {
        if(s[l]==s[r] && s[l]=='*') {
            s[l]='a';
            s[r]='a';
            l++; r--;
        }
        else if(s[l]==s[r]) {
            l++; r--;
        }
        else if(s[l]=='*' && s[r]!='*') {
            s[l]=s[r];
            l++; r--;
        }
        else if(s[r]=='*' && s[l]!='*') {
            s[r]=s[l];
            l++; r--;
        }
        else
            return "Not Possible";
    }
    return s;

}


void solve() {
    string str;
    cin>>str;
    cout<<makeLexPall(str)<<"\n";
}


int main()
{
    int tc;
    cin>>tc;
    while(tc--) {
        solve();
    }
    return 0;
}
