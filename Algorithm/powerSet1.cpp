#include<bits/stdc++.h>
using namespace std;

void powerSet(int n) {
    int digits = 0;
    int temp = n;
    while(temp) {
        digits++;
        temp /= 10;
    }
    // cout<<"digits "<<digits;

    int arr[digits];

    for(int i=digits-1; i>=0; i--) {
        arr[i] = n%10;
        n /= 10;
    }

    // for(int i=0;i<digits;i++) cout<<arr[i]<<" ";

    long long limit = pow(2, digits);
    for(long long i = 0; i < limit; i++) {
        int num = 0;
        for(int j=0;j<digits;j++) {
            if( (i & (1 << j)) > 0) {
                num *= 10;
                num += arr[j];
            }
        }
        cout<<num<<" ";
        cout<<endl;
    }


}

int main()
{
    int n;
    cin>>n;
    powerSet(n);
    return 0;
}

// Generates subsets of a number
// 0  means null subset

// TC : O(n2^n)

// Input : 2341
// Output :
// 0 
// 2 
// 3 
// 23 
// 4 
// 24 
// 34 
// 234 
// 1 
// 21 
// 31 
// 231 
// 41 
// 241 
// 341 
// 2341 

