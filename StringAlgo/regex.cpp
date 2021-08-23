#include<bits/stdc++.h>
using namespace std;

bool regexMatch(string txt, string pat){
    int tl = txt.length();
    int pl = pat.length();

    bool dp[tl+1][pl+1] = {0};

    //empty pattern mathes empty string 
    dp[0][0] = 1;

    //* matches all empty strings 
    for(int i=1;i<=pl;i++){
        if(pat[i-1] == '*') dp[0][i] = dp[0][i-1];
    }

    for(int i=1;i<=tl;i++){
        for(int j=1;j<=pl;j++){
            //if we encounter *,
            //1. we skip the pattern, or skip the txt
            if(pat[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];

            //pat and txt matches exactly
            else if (pat[j-1] == '?' || pat[j-1] == txt[i-1]) dp[i][j] = dp[i-1][j-1];

            else //no match 
            dp[i][j] = 0;
        }
    }

    // for(int i=0;i<=tl;i++){
    //     for(int j=0;j<=pl;j++) cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }

    return dp[tl][pl];
}

int main()
{
    string txt, pat;
    cin>>txt>>pat;
    cout<<regexMatch(txt, pat)<<"\n";
    return 0;
}
