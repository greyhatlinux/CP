#include<bits/stdc++.h>
using namespace std;

#define NAX 1000001

void uni(int n, int *a1, int m, int *a2){
    int arr[NAX] = {0};
    for(int i=0;i<n;i++) arr[a1[i]]++;
    for(int i=0;i<m;i++) arr[a2[i]]++;

    cout<<"Union : ";
    for(int i=0;i<NAX;i++)  if(arr[i] > 0) cout<<i<<" ";
    cout<<"\n";
}

void intersection(int n, int *a1, int m, int *a2) {
    int arr[NAX] = {0};
    for(int i=0;i<n;i++) arr[a1[i]]++;
    for(int i=0;i<m;i++) arr[a2[i]]++;

    cout<<"Intersection : ";
    for(int i=0;i<NAX;i++) if(arr[i] > 1) cout<<i<<" ";
    cout<<"\n";   
}


int main()
{
    int n,m;
    cin>>n>>m;
    int a1[n], a2[m];
    for(int i=0;i<n;i++) cin>>a1[i];
    for(int i=0;i<m;i++) cin>>a2[i];
    uni(n, a1, m, a2);
    intersection(n,a1, m, a2);
    return 0;
}

// TC : O(N)
// SC : O(N)
