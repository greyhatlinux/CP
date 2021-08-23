#include<bits/stdc++.h>
using namespace std;

void computelps(string pat, int l, int *lps){
    int i = 1, j = 0;
    while(i<l){
        if(pat[i] == pat[j]) lps[i++] = ++j;
        else {
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
}

int kmp(string txt1, string txt2, string pat){
    int tl1 = txt1.length();
    int tl2 = txt2.length();
    int pl = pat.length();

    int lps[pl] = {0};
    computelps(pat, pl, lps);

    // // considering only txt2
    // int t2 = 0, p = 0,idx = INT_MAX, ctr = 0;
    // while(t2<tl2){
    //     if(txt2[t2] == pat[p]) t2++, p++;
    //     if(p==pl){
    //         ctr++;
    //         idx = min(idx, t2-p);
    //         p = lps[p-1];
    //     }
    //     else if(t2<tl2 && txt2[t2] != pat[p]){
    //         if(p!=0) p = lps[p-1];
    //         else t2++;
    //     }
    // }
    // if(ctr) return idx; 
    // return -1;   

    //taking t1
    int t1 = 0, p = 0, ctr = 0, idx = INT_MAX;
    while(t1<tl1){
        if(txt1[t1] == pat[p]) p++, t1++;
        if(p==pl) {
            ctr++;
            idx = min(idx, t1-pl);
            p = lps[p-1];
        }
        else if (t1 < tl1 && txt1[t1] != pat[p]){
            if(p!=0) p = lps[p-1];
            else t1++;
        }
    }
    if(ctr) return idx;
    return -1;
}


int main()
{
    string txt1, txt2, pat;
    getline(cin, txt1);
    getline(cin, txt2);
    getline(cin, pat);
    cout<<kmp(txt1, txt2, pat)<<"\n";
    return 0;
}

// input :  
// iamgoingtopartygoing
// i am going to party and he is goinggoing home
// going
