// Link : https://leetcode.com/problems/backspace-string-compare/
// Time comp : O(N)
// Space Comp : O(1)

#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    int l1 = a.size()-1, l2 = b.size()-1;
    
    int tag1=0, tag2=0;
    

    while(l1>=0 || l2>=0) {
        while(l1>=0){
            if (a[l1] == '#') {tag1++; l1--; }
            else if (tag1>0) {tag1--; l1--;}
            else break;
        }
        
        while(l2>=0) {
            if (b[l2] == '#') {tag2++; l2--;}
            else if (tag2>0) {tag2--; l2--;}
            else break;
        }
        
        if( l1>=0 && l2>=0 && a[l1]!=b[l2]) return false;
        
        if( (l1>=0) != (l2>=0)) return false;
        
        l1--; l2--; 
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
