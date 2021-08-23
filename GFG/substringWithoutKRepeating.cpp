#include<bits/stdc++.h>
using namespace std;

int valid(int *arr){
    int k = 0;
    for(int i=0;i<26;i++){
        if(arr[i] > 0) k++;
    }
    return k;
}

bool unique(int *arr, int num){
    int k=0;
    for(int i=0;i<26;i++){
        if(arr[i] > 0) k++;
    } 
    if(k <= num) return true;
    return false;
}

int func(string str, int k){
    int n = str.length();
    int arr[26] = {0};

    for(int i=0;i<n;i++) arr[str[i]-'a']++;
    int un = valid(arr);

    if(un < k) return -1;

    int i=0, j=0, ans = 1;
    int count[26] = {0};


    while(i<n){
        count[str[i]-'a']++;
        i++;

        while(!unique(count, k)){
            count[str[j]-'a']--;
            j++;
        }

        ans = max(ans, i-j);

    }
    return ans;
}

int main()
{
    string str;
    int k;
    cin>>str>>k;
    cout<<func(str, k)<<"\n";
    return 0;
}
