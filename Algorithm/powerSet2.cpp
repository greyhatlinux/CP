#include<bits/stdc++.h>
using namespace std;

int binToDec(int x) {
    int base = 1;
    int dec = 0;
    while(x){
        int rem = x%10;
        if(rem) dec = dec + base;
        base *= 2;
        x /= 10;
    }
    return dec;
}

void powerSet(int n) {
    int digits = 0;
    int temp = n;
    while(temp) {
        digits++;
        temp /= 10;
    }

    int arr[digits];

    for(int i=digits-1; i>=0; i--) {
        arr[i] = n%10;
        n /= 10;
    }

    long long limit = pow(2, digits);
    set<int> s;
    for(long long i = 0; i < limit; i++) {
        int num = 0;
        for(int j=0;j<digits;j++) {
            if( (i & (1 << j)) > 0) {
                num *= 10;
                num += arr[j];
            }
        }
        s.insert(num);
    }

    //binary to deciman conversion
    for(auto x : s) {
        cout<<binToDec(x)<<"\n";
    }


}

int main()
{
    int n;
    cin>>n;
    powerSet(n);
    return 0;
}

// Generates subsets of a binary numbers, and outputs all its decimal representation
// TC : O(n2^n)

// Input : 1011
// Output : 
// 0
// 1
// 2
// 3
// 5
// 7
// 11
