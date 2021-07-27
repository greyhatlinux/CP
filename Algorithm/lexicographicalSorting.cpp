#include<bits/stdc++.h>
using namespace std;

bool myComp(string a, string b){
    if(a.compare(0, b.length(), b) == 0 || b.compare(0, a.length(), a) == 0) return a.size() < b.size();
    else return a < b;
}

vector<string> mySort(vector<string> str){
    sort(str.begin(), str.end(), myComp);
    return str;
}

int main()
{
    vector<string> str;
    str = {"apple", "app", "application", "moon", "motion", "sun", "actor", "hit"};
    auto x = mySort(str);
    for(auto m : x) cout<<m<<" ";
    return 0;
}

// each compare funtion takes O(m*n) for sorting
