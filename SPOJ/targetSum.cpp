#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a); i<b; i++)
#define endl "\n"

void solve1(int arr[], int n, int sum) {
    if(n<2) return;
    unordered_set<int> s;
    fi(0,n) {
        int x = sum-arr[i];
        if(s.find(x)==s.end()) s.insert(arr[i]);
        else {
            cout<<arr[i]<<" + "<<*s.find(x)<<" = "<<sum<<endl;
            return;
        }
    }
}

void solve2(int arr[], int n, int sum){
    if(n<2) return;
    unordered_set<int> s;
    fi(0,n){
        int x = sum-arr[i];
        if(s.find(x)==s.end()) s.insert(arr[i]);
        else cout<<arr[i]<<" + "<<x<<" = "<<sum<<endl;
    }
    cout<<endl;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n, sum;
        cin>>n>>sum; 
        int arr[n];
        fi(0,n) cin>>arr[i];
        
        // solve1(arr, n, sum);
        solve2(arr, n, sum);
        
    }
    return 0;
 }

//  solve1 is considering that only one pair would add upto the target sum
//  solve2 would find out all pairs whose sum would add up to the target sum from the array
