#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void wordCount(string str) {
    stringstream w(str);
    string word;
    map<string, int> mp;

    int ctr = 0;
    while(w >> word) mp[word]++;
    map<string, int> :: iterator it;
    for(it = mp.begin(); it!=mp.end(); it++) cout<<it->first<<" : "<<it->second<<endl;
    
}

int main()
{
        string s;
        getline(cin, s);
        wordCount(s);
        return 0;
}

// input : 
// alia goes to market but sid goes to the shop
