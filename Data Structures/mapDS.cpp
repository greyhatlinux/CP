// difference between map, unordered map, and multimap
// Maps in c++ are implemented using red/black trees

#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Difference between map, unordered map, and multimap \n\n";
    
    cout<<"Map\n";
    map<string, int> cart;
    cart["apple"] = 100;
    cart["samsung"] = 80;
    cart["tesla"] = 110;
    cart.insert({"amazon", 110});
    cart.insert({"google", 100});
    cart.insert({"apple", 150});
    cart.insert({"amazon", 90});
    
    
    cout<<"Iterating over the map\n";
    for(auto it:cart) cout<<it.first<<" -> "<<it.second<<"\n";
    
    cout<<"Note : The keys are ordered alphabetically in map ds. Also, Duplicate entries are automatically removed\n\n\n";
    
    
    cout<<"Unordered Map\n";
    unordered_map <string, int> un_cart;
    un_cart["apple"] = 100;
    un_cart["samsung"] = 80;
    un_cart["tesla"] = 110;
    un_cart.insert({"google", 100});
    un_cart.insert({"google", 200});
    un_cart.insert({"amazon", 90});
    
    for(auto it:un_cart) cout<<it.first<<" -> "<<it.second<<"\n";
    
    cout<<"Note : In this unordered_map, the keys aren't sorted alphabetically. Also, Duplicate entries are automatically removed\n\n\n";
    
    
    cout<<"Multimap\n";
    multimap <string, int> multi_cart;

    // Direct assignment liske this doesn't work
    // multi_cart["apple"] = 100;

    multi_cart.insert({"apple", 250});
    multi_cart.insert({"google", 100});
    multi_cart.insert({"amazon", 90});
    multi_cart.insert({"apple", 150});
    multi_cart.insert({"amazon", 110});
    
    for(auto it:multi_cart) cout<<it.first<<" -> "<<it.second<<"\n";
    
    cout<<"Note : Alphabetically sorted keys. Duplicate entries are allowed. Have to use the insert method to put in values, no direct assignment\n\n";
    
    return 0;
}
