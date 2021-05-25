#include<bits/stdc++.h>
using namespace std;

void solve(string str, int l) {
    unordered_set<char> s;
    int ctr=0, mx=0;
    string s1, smax;

    for(int i=0;i<l;i++) {
        if(s.find(str[i])==s.end()) {
            s.insert(str[i]);
            ctr++;
            mx = max(ctr, mx);
            s1 = s1 + str[i];
        }
        else {
            smax = s1;
            ctr = 0;
            s.clear();
            s1 = "";
        }
    }
    smax.length() > s1.length() ? smax = smax : smax = s1;
    cout<<mx<<" : "<<smax<<endl;
}

int main() {
    int tc; cin>>tc; while(tc--) {
        string str;
        cin>>str;
        int l = str.length();
        solve(str, l);
    }
    return 0;
}
