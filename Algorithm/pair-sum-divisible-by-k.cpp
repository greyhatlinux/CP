// Question :https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,k;
        cin>>n>>k;
        int arr[n], rem[k] = {0};
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            rem[arr[i]%k]++;
        }

        int pairs = 0;

        //all pairs for numbers already divisble by k
        pairs += (rem[0] * (rem[0]-1))/2;


        //pairs of sums divisible by k
        for(int i=1;i <= k/2 && i != (k-i); i++) {
            pairs += rem[i]*rem[k-i];
        }

        //if k is even
        if(k%2==0) 
            pairs += (rem[k/2]*(rem[k/2]-1))/2;

        cout<<pairs<<"\n";
    }

    return 0;
}

// TC : O(N)
