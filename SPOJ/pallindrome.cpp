#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define testcase long long tc; cin>>tc; while(tc--)
#define ll long long
#define nl "\n"

void nextPall(string str)
{
    string tmp = str;
    ll len=str.length();
    ll mid=len/2,bt;
    
    for(ll i=0;i<mid;i++) tmp[len-1-i]=str[i];
    
    if(tmp<=str)
    {
        if(len%2==0) bt=mid-1;
        else bt=mid;
    
        while(bt>=0)
        {
            if(str[bt]!='9')
            {
                str[bt]++;
                break;
            }
            else 
            {
                str[bt]='0';
                bt--;    
            }
        }
        
        // if the initial digit is 0, it should have been 9++ and not 9->0
        // but doing this would break other logic, so we hardcode this.
        
        if(str[0]=='0') str = '1'+str;
        len = str.length();
        mid = len/2;
        
        tmp = str;
        for(ll i=0;i<mid;i++) tmp[len-1-i]=str[i];
        cout<<tmp<<nl;
        return;

        
    }
    else 
    {
        cout<<tmp<<nl;
        return;
    }

    
}

int main()
{
    fast
    testcase
    {
        string s;
        cin>>s;

        nextPall(s);
        
    }
    return 0;
}