// sum of all possible pairs from an array of numbers.
// Totally mathematics
// for a,b,c,
// ab+bc+ca = ((a+b+c)^2 - (a^2 + b^2 + c^2))/2

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int arr[n];
    cin>>n;
    int sum=0, sq=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        sum += arr[i];
        sq += arr[i]*arr[i];
    }
     cout<<(((sum*sum)-(sq))/2);
    
    return 0;
}
