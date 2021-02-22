// Link : https://leetcode.com/problems/backspace-string-compare/


#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
   stack <char> s1, s2;
   
   int l1 = a.size(), l2 = b.size();
   
   for(int i=0;i<l1;i++){
       if(a[i]!='#') s1.push(a[i]);
       else {
           if(!s1.empty()) s1.pop();
       }
   }
   
   for(int i=0;i<l2;i++){
       if(b[i]!='#') s2.push(b[i]);
       else {
           if(!s2.empty()) s2.pop();
       }
   }
    
    int sz1 = s1.size();
    int sz2 = s2.size();
    
    if(sz1==sz2) {
        for(int i=0;i<sz1;i++) {
            if(s1.top()==s2.top()) {
                s1.pop(); s2.pop();
                continue;
            }
            else {
                return false;
            }
        }
    }
    else {
        return false;
    }
    
    return true;
}


int main()
{
    string s,t;
    cin>>s;
    cin>>t;
    
    if(compare(s,t)) cout<<"True";
    else cout<<"False";
    
    return 0;
}
