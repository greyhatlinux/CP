// Question : From the given array of numbers
// find the number with max frequency, in case of multiple numbers with max freq, print the one which occurs first


#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)
#define endl "\n"

int maxFreqNumber(int arr[], int n) {
    unordered_map<int, int> umap;
    unordered_map<int, int> :: iterator it;
    int maxFreq = 0;

    //loop 1 to insert all values and fins max frequency number
    fi(0,n) {
        umap[arr[i]]++;
        it = umap.find(arr[i]); 
        if(it->second > maxFreq) maxFreq = it->second; 
    }

    //loop 2 to find the first occuring number with max frequency
    fi(0,n) {
        it = umap.find(arr[i]);
        if(it->second == maxFreq) return arr[i];
    }
}

int main()
{

    int n;
    cin>>n;
    int arr[n];
    fi(0,n) cin>>arr[i];
    cout<<maxFreqNumber(arr, n)<<endl;
    return 0;
}


// Sample Input :
// 7
// 1 5 3 2 3 4 2 
  
// Output : 3
