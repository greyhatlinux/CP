// Link : https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/weighted-string/

#include<bits/stdc++.h>
using namespace std;

int solve(int k, string str) {
    
    int len = str.length();
    int ctr = 0, sum = 0;

    for(int i=0;i<len;i++){
        sum = 0;
        for(int j=i;j<len;j++){
            sum += (int)str[j]-96;
            if(sum == k) ctr++;
            if(sum>k) break;    
        }
    }
    return ctr;
}


int main()
{
    int tc; cin>>tc; while(tc--){
        int k;
        string str;
        
        cin>>k>>str;
        cout<<solve(k, str)<<endl;
    }
    return 0;
}
