// Check whether two strings are equivalent or not, one of them being an abbreviation of the other. (Case-Insensitive)
// For example String: 

// Internationalization Abbr: I18n 
// where 18 are the number of characters between I and N

// String: Poster Abbr: P1s2r 
// where 2 characters are between P and s, and then 1 character between s and r

#include<bits/stdc++.h>
using namespace std;

bool solve(string a, int l1, string b, int l2) {
    if(a[0]!=b[0]) return false;



    for(int i=1, j=1; i<l2; i++, j++) {

        int num=0, curr=0;
        while(b[i]>48 && b[i]<58) {
            curr = b[i]-48;
            num = (num*10)+curr;
            i++;
        }

        j+=num;
        if(b[i]!=a[j]) return false;

    }
    return true;
}

int main() 
{
    int tc; cin>>tc; while(tc--) {
        string str, abbr;
        cin>>str>>abbr;
        int l1 = str.length(), l2 = abbr.length();
        if (solve(str, l1, abbr, l2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
