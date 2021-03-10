// Properties of set data structure in c++
// -> unique values
// -> duplicate values will not be inserted in the firse place
// -> values are inserted in increasing order
// -> set works on Balanced Binary Tree internally [T:O(log n)]

// -> unordered_set works on Hashing [T:O(1)]
// -> insertion is always randomised, and not in increasing order
// -> unique elements are retained


#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(30); // this 30 will not be added
    s.insert(50);
    s.insert(5);
    
    set<int>::iterator i;
    
    // this prints the set in increasing order
    cout<<"Set 1:\n";
    for(i=s.begin(); i!=s.end(); i++) {
        cout<<*i<<" ";
    }
    
    cout<<endl;
    // creating a new set with same values as of s1;
    set<int> s2(s.begin(), s.end());
    
    cout<<"Set 2:\n";
    for(i=s2.begin(); i!=s2.end(); i++) {
        cout<<*i<<" ";
    }    
    
    cout<<endl;
    // cout<<*(s2.find(30))<<endl;
    
    unordered_set <int> us;
    
    us.insert(100);
    us.insert(200);
    us.insert(500);
    us.insert(300);
    us.insert(200); //Multiple value of 200 will be discarded
    us.insert(900);
    us.insert(600);
    
    unordered_set<int>::iterator it;
    
    cout<<"Unordered Set 1:\n";
    for(it = us.begin(); it!=us.end(); it++) {
        cout<<*it<<" ";
    }
    
    cout<<endl;
    cout<<"set current size : "<<us.size()<<endl;
    cout<<"max size : "<<us.max_size()<<endl;
    cout<<"Removing 600 and 100 'us.erase(x)' \n";
    
    us.erase(600);
    us.erase(100);
    
    cout<<"Unordered Set after Removing 600 :\n";
    for(it = us.begin(); it!=us.end(); it++) {
        cout<<*it<<" ";
    }
    
    
    return 0;
}
