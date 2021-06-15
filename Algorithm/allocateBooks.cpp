#include<bits/stdc++.h>
using namespace std;

#define fi(a,b) for(int i=(a);i<b;i++)
#define endl "\n"

bool possible(vector<long long int> &A, long long int mid, int stud) {
    long long int sum = mid;
    int n = 1, ctr = 0; //no. of students would be atleast 1

    while(ctr<A.size()){
        if(sum-A[ctr]<0){
            n++;
            sum = mid;
        }
        else {
            sum -= A[ctr]; 
            ctr++;
        }
        if(n>stud) return false;
    }
    return true;
}

int minimumPages(vector<long long int> &arr, int stud) {
    long long totalPages = 0;
    int s = arr.size();
    fi(0,s) totalPages += arr[i];

    long long int lo, hi, mid, ans;
    lo = 0;
    hi = totalPages;
    cout<<"total pages "<<totalPages<<endl;
    while(lo<=hi) {
        mid = (lo+hi)/2;

        //if this mid value satisfies book allocation
        //we try with greater value of mid, until hi==lo
        if(possible(arr, mid, stud)) {
            // cout<<"high "<<hi<<" mid "<<mid<<" low "<<lo<<endl;
            ans = mid;
            hi = mid-1;
        }
        //if books cannot be allocated with this mid
        else {
            // cout<<"high "<<hi<<" mid "<<mid<<" low "<<lo<<endl;
            lo = mid+1;
        }
    }
    return ans;
}


int main()
{

    int n,st;
    cin>>n>>st;
    vector<long long int> arr(n);
    fi(0,n) cin>>arr[i];
    cout<<minimumPages(arr, st)<<endl;
    // cout<<books(arr, n);
    return 0;
}

// works on Binary Search to find optimum middle value

// Sample Input : 
// 4 2 
// 12 34 67 90
