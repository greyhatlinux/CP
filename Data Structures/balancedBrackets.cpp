#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fi(a,b) for(ll i=(a); i<b; i++)

bool isValidParenthesis(string expression)
{
    int len = expression.length();
    int i=0;
    stack<char> s;

    while(i<len){
        char ch = expression[i];
        if(ch=='(' || ch=='{' || ch=='[') s.push(ch);
        else {
            if(s.empty()) return false;
            char ch2 = s.top();
            s.pop();
            if(ch2=='(' && ch !=')' || ch2=='{' && ch !='}' || ch2=='[' && ch !=']') return false;
        }
        i++;
    }
    if(!s.empty()) return false;

    return true;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        // cout<<tc;
        string str;
        cin>>str;
        cout<<str<<endl;
        cout<<isValidParenthesis(str)<<endl;
    }
    return 0;
}
