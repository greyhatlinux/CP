#include<bits/stdc++.h>
using namespace std;

class Hash
{
    // By default, the variables in a class are private
    int bucket;
    list<int> *table;
    
    public:
    
    // Constructor for Hash Class (taking no.of buckets as agr)
    Hash(int b) {  
        this->bucket = b;
        table = new list<int>[bucket];
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    
    void deleteItem(int key) {
        int index = hashFunction(key);
        list<int>::iterator i;
        for(i = table[index].begin(); i!=table[index].end(); i++) {
            if(*i == key) break;
        }
        
        if(i!=table[index].end()) {
            table[index].erase(i);  
        }
    }

    // Implementing Hash Function (x%n)
    int hashFunction(int x) {
        return (x%bucket);
    }
    
    void displayHash(){
        for(int i=0;i<bucket; i++) {
            cout<<i<<" : ";
            for(auto x:table[i]) cout<<x<<" --> ";
            cout<<endl;
        }
    }
};

int main()
{
    // Array 'a' contains keys to be inserted
    int a[] = {2,54,7,4,6,14,16};
    int n = sizeof(a)/sizeof(a[0]);
    
    Hash func(7);
    
    for(int i=0;i<n;i++)
        func.insertItem(a[i]);
        
    cout<<endl;
    func.displayHash();
    
    func.deleteItem(14);
    cout<<endl;
    func.displayHash();
    
    return 0;
}

