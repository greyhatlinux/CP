// Question : https://leetcode.com/discuss/interview-question/351783/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n = s.length();
    int arr[27] = {0};

    for(int i=0;i<n;i++) arr[s[i]-'a']++;

    int sum = 0, odd = 0;
    for(int i=0;i<27;i++) {
        if(arr[i]&1) odd++;
    }
    return odd <= 1;
}

void swap(string &s, int i, int k) {
    char x = s[i];
    s[i] = s[k];
    s[k] = x;
}

int solve(string str) {
    if(!isValid(str)) return -1;

    int n = str.length();
    int p1 = 0, p2 = n-1;

    int count = 0;
    while(p1<p2) {

        //if chaaracters are same
        if(str[1] == str[p2]) p1++, p2--;

        //if not same
        else {
            int k = p2;
            while(k > p1 && str[k] != str[p1]) k--;

            //no match found
            if(k == p1) swap(str, p1, p1+1), count++;
            else {
                while(k<p2){
                    swap(str, k, k+1);
                    k++;
                    count++;
                }
            }
            p1++; p2--;
        }
    }
    // cout<<str<<"\n";
    return count;
}

int main()
{
    int tc; cin>>tc; while(tc--){
        string s;
        cin>>s;
        cout<<solve(s)<<"\n";
    }
}
