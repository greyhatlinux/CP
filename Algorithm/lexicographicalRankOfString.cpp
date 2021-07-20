#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
   int res = 1;
   for(int i=2;i<=n;i++) res *= i;
   return res; 
}

int findSmaller(string s, int st, int end){
    int num=0;
    for(int i=st+1; i<=end; i++) {
        if(s[i] < s[st]) num++;
    }
    return num;
}

int lexicoRank(string s) {
    int len = s.length();
    int mul = fact(len);
    int rank = 1;
    int countRight;

    int i;
    for(i=0;i<len;i++){
        mul /= len-i;

        countRight = findSmaller(s, i, len-1);
        rank += countRight * mul;
    }
    return rank;
}

int main()
{
    string s ;
    cin>>s;

    cout<<lexicoRank(s)<<"\n";
   
    return 0;
}
