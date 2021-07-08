// Question : https://www.geeksforgeeks.org/stepping-numbers/

#include<bits/stdc++.h>
using namespace std;

bool isValid(int n) {
    if(n<0) return false;
    if(n<11) return true;

    int lastDigit = n%10;
    n = n/10;
    while(n) {
        int currDigit = n%10;
        if(abs(currDigit - lastDigit) != 1) return false;
        lastDigit = currDigit;
        n /= 10;
    }
    return true;
}

int steppingNumbers(int n, int m) {
    int count = 0;
    for(int i=n;i<=m;i++) {
        if(isValid(i)) {
            cout<<i<<" ";
            count++;
        }
    }
    return count;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,m;
        cin>>n>>m;
        int x = steppingNumbers(n,m);
        cout<<"\nTotal numbers : "<<x<<"\n";
    }
    return 0;
}


// Naive Solution :
// TC : O(N)
