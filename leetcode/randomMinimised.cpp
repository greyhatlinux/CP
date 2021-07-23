// Question : You are given an array with random numbers [1,4,6,7,6]. Return an array in the same order but with minimized values: [1,2,3,4,3]. 
// So since 4 is greater than 1 but less than 6 it becomes 2, 6 is greater than 4 so it's value should be 3. [3,5,3,8] would become [1,2,1,3].

#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& arr) {
    
    //temporary array for sorting
    vector<int> arr2 = arr;

    sort(arr2.begin(), arr2.end());

    //map to store relative values of the elements
    map<int, int> mp;
    //value of first element
    int k = 1;

    //to insert values corresponding to the elements
    for(int i=0;i<n;i++){
        if(mp.find(arr2[i]) == mp.end()){
            mp.insert({arr2[i], k++});
        }
    }

    //modifying the main array
    for(int i=0;i<n;i++) {
        arr[i] = mp.find(arr[i])->second;
    }
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        solve(n, arr);
        for(auto x:arr) cout<<x<<" ";
        cout<<"\n";
    }
    return 0;
}

// TC : O(NlogN)
// SC : O(N)
