#include<bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    if(n==1) return 1;
    return n*factorial(n-1);
}
        
class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        long long fact;

        fact = factorial(N);
        // cout<<fact<<" ";
        
        int ctr = 0;
        while(fact%10 == 0) {
            ctr++;
            fact /= 10;
        }
        return ctr;
    }
};

int solve(int n) {
    
    int div = 5, ans = 0;
    while(div<n) {
        ans += floor(n/div);
        div *= div;
    }
    return ans;
}

int main()
{
    // M1:----------------------------------
    // inefficient with large input
    
    // int t;
    // cin>>t;
    // Solution a;
    // int ans;
    // ans = a.trailingZeroes(t);
    // cout<<ans;
    
    
    // M2:----------------------------------
    int t;
    cin>>t;
    cout<<solve();
    
    return 0;
}
