// Question : https://www.geeksforgeeks.org/find-number-of-cavities-in-a-matrix/

#include<bits/stdc++.h>
using namespace std;

int n;

bool isValid(int x, int y){
    return (x>=0 && x <n && y>=0 && y<n);
}

bool isCavity(int k, vector<int>& nums){
    for(auto x : nums) if(x < k) return false;
    return true;
}

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int cavity(int n, int *arr){

    int ans = 0;
    vector<int> ans_arr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<int> nums;
            int k = *((arr + i*n) + j);
            for(int t=0;t<8;t++) {
                int nx = i + dx[t], ny = j + dy[t];
                if(isValid(nx, ny)) nums.push_back(*((arr + nx*n) + ny));
            }
            if(isCavity(k, nums)) {
                ans_arr.push_back(k);
                ans++;
            }
        }
    }
    // for(auto x : ans_arr) cout<<x<<" ";
    return ans;
}

int main()
{

    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    cout<<cavity(n, (int *)arr)<<"\n";
    return 0;
}

// TC : O(n*n)
// SC : O(1);
