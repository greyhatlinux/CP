// Find whether a no. is divisible by 11 or not

#include<bits/stdc++.h>
using namespace std;

bool isDivisible(string str){
    int odd = 0, even = 0;
    int n = str.length();

    for(int i=0;i<n;i++){
        if(i&1) odd += (str[i]-'1');
        else even += (str[i]-'1');
    }

    if((even-odd)%11) return false;
    return true;

}

int main()
{
    string str;
    cin>>str;
    if(isDivisible(str)) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}

// O(k), k-> no.of digits in the string ~ O(N)
