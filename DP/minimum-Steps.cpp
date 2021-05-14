// Question : Fine the minimum no of steps taken to reach the nth stair(from 0th) in a staircase
// if one can step 1-step or 3-steps at a time.
// Like one can go like :
// 0-1-2-5-8...
// 0-1-2-3-4...
// 0-3-6-9-10..

// Input -> N (Destination stair)
// Output -> x (Minimum no. of steps taken)

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fi(a,b) for(int i=(a); i<b; i++)

int minSteps(int n) {
    
    if(n<=0) return 0;
    int steps = 0;
    steps++;
    steps += min(minSteps(n-1), minSteps(n-3));
    return steps;
}

int minStepsDP(int n) {
    int DP[n];
    DP[0]=0; DP[1]=1; DP[2]=2; DP[3]=1;

    if(n<4) return DP[n];
    fi(4,n+1) DP[i] = min(DP[i-1]+1, DP[i-3]+1);
    return DP[n];
}



int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    string str;
    cout<<minStepsDP(n)<<endl;
    return 0;
}


// minSteps function forms the recursion tree
// it recurses down the tree, calling the function with same input multiple times

// to avoid this extra overhead, we form the DP array
