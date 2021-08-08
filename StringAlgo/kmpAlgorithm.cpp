#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, int k, int *lps){
    int j = 0;
    lps[0] = 0;
    int i=1;
    while(i<k){
        if(pat[i]==pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if(j!= 0) j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int kmp(string txt, string pat){
    int tl = txt.length();
    int pl = pat.length();

    int lps[pl], ctr = 0;
    computeLPS(pat, pl, lps);

    int t = 0, p = 0;
    while(t<tl){
        if(pat[p] == txt[t]){
            p++; t++;
        }
        if(p==pl){
            cout<<"pattern found at "<<t-p;
            p = lps[p-1];
            ctr++;
        }
        else if(t < tl && pat[p] != txt[t]){
            if(p!=0) p = lps[p-1];
            else t++;
        }
    }
    return ctr;

}

int main()
{
    string txt, pat;
    cin>>txt>>pat;
    int n = kmp(txt, pat);
    cout<<"\nNo. of occurrences of pattern : "<<n;
    return 0;
}

// TC : O(N)
// N -> length of the long string given
