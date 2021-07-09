// Question : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

#include<bits/stdc++.h>
using namespace std;

int solve(string s1) {
    int n = s1.length();
    int arr[27] = {0};
    int ctr = 0;
    
    for(int i=0;i<n;i++) arr[s1[i] - 97]++;
    // for(int i=0;i<27;i++) cout<<arr[i]<<" ";
    
    set<int> s;
    for(int i = 0; i<27; i++) {
        if(arr[i]) {
            while(arr[i] > 0) {
                
                //unique
                if(s.find(arr[i]) == s.end()) {
                    s.insert(arr[i]); 
                    break;
                }
                
                //that value already exists, so remove
                else {
                    arr[i]--;
                    ctr++;
                }
            }
        }
    }
    return ctr;
}

int main()
{
    int tc; cin>>tc; while(tc--){
        string s;
        cin>>s;
        cout<<solve(s)<<"\n";
    }
}

// TC : O(N)
// SC : O(1)
