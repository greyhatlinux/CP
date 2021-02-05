#include<bits/stdc++.h>
using namespace std;

// Checking if a string is a pallingdrome or not.
// Among 'n' input strings, output the strings which are pallindromes.

int ifPallindrome(string s){
    long long len, r, l;
    len = s.length();
    
    l=0; r=len-1;
    while(l<=r) {
        if(s[l]!=s[r]) return 0;
        l++; r--;
    }
    return 1;
    
}


void solve(){
    string str;
    cin>>str;
    
    if(ifPallindrome(str)) cout<<str<<"\n";
}


int main()
{
    int tc;
    cin>>tc;
    
    while(tc--){
        solve();
    }
    
    return 0;
    
}
