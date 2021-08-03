#include<bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int prefix[maxn] = {0};

int isRepeat(int n){
    if(n<11 && n >0) return 1;

    unordered_set<int> s;
    while(n){
        int d = n%10;
        if(s.find(d) != s.end()) return 0;

        s.insert(d);
        n /= 10; 
    }
    return 1;
}


int digits(int l, int r){
    return prefix[r] - prefix[l-1];
}

int main()
{
    for(int i=1;i<maxn;i++){
        prefix[i] = isRepeat(i) + prefix[i-1];
    }

    int tc; cin>>tc; while(tc--){
        int l,r;
        cin>>l>>r;
        cout<<digits(l,r)<<"\n";
    }
    return 0;
}

// TC : O(N) for pre-computation once
// then, it is O(1) for all ranges
