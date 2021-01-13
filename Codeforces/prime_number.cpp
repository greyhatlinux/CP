// code to generate 'n' prime numbers

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l;
    cin>>l;
    
    // sieve of eratosthanese - 1
    
    // vector<int> arr(l,0);
    // arr[0]=arr[1]=1;
    
    // for(int i=2;i<l;i++) {
    //     if(arr[i]==0 && (long long)i*i<=l) {
    //       for(int j=i*i; j<l ; j+=i) {
    //           arr[j]=1;
    //       }  
    //     }
    // }
    
    // for(int i=0;i<l;i++) {
    //     if(arr[i]==0) cout<<i<<" ";
    // }
    
    
    
    // sieve of eratosthanese - 2
    
    // vector<char> arr(l,false);
    // arr[0] = arr[1] = true;
    // for(int i=2;i<l;i++) {
    //     if(arr[i]==false && (long long) i*i <= l) {
    //         for(int j=i*i; j<=l; j+=i) {
    //             arr[j]=true;
    //         }
    //     }
    // }
    
    // for(int i=0;i<l;i++) {
    //     if(arr[i]==false) cout<<i<<" ";
    // }
    
    // sieve of eratosthenes - 3
    
    vector<char> is_prime(l,true);
    is_prime[0]=is_prime[1]=false;
    
    for(int i=2;i<l;i++) {
        if(is_prime[i]) {
            for(int j=i*i;j<=l;j+=i) {
                is_prime[j]=false;
            }
        }
    }
    
    for(int i=0;i<l;i++){
        if(is_prime[i]) cout<<i<<" ";
    }
    
    return 0;
}
