// Question : https://www.geeksforgeeks.org/count-substrings-that-contain-all-vowels-set-2/#:~:text=Given%20a%20string%20str%20containing,present%20in%20the%20sub%2Dstrings.

#include<bits/stdc++.h>
using namespace std;

bool isVowel(char ch) {
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    return false;
}

int countSubsUtil(string str) {
    int len = str.length();
    map<char, int> mp;
    int num = 0;

    for(int i=0;i<len;i++) {
        mp[str[i]]++;

        int start = 0;
        while(mp['a']>0 && mp['e']>0 && mp['i']>0 && mp['o']>0 && mp['u']>0) {
            num += len-i;
            mp[str[start]]--;
            start++;
        }
    }
    return num;
}

int countSubs(int n, string str) {

    string subs = "";
    int count = 0;

    int i = 0;

    //this loop finds the longest substring of all continous vowels
    while(i<n) {
        if(isVowel(str[i])) {
            subs += str[i];
        }

        else {
            if(subs.length() > 0) {
                count += countSubsUtil(subs);
                subs = "";
            }
        }
        i++;
    }

    //if the string ends with a vowel-only subs, this has to be separately processed
    //because the counter exhausts, but subs is non empty string
    if(subs.length() > 0) count += countSubsUtil(subs);

    return count;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        string str; 
        cin>>str;
        int n = str.length();
        cout<<countSubs(n, str)<<"\n";
    }
    return 0;
}

// TC : O(N)
