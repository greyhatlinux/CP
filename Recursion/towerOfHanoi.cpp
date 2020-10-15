#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void towerOfHanoi(long long num, char init, char aux, char fin)
{
    // base case
    if(num==1)
    {
        cout<<"Moving disk 1 from "<<init<<" to "<<fin<<"\n";
        return;
    }

    towerOfHanoi(num-1, init, fin, aux);
    cout<<"Moving disk "<<num<<" from "<<init<<" to "<<fin<<"\n";
    towerOfHanoi(num-1, aux, init, fin);
    
}

int main()
{
    fast
    
    long long n;
    cin>>n;
    
    char a='A',b='B',c='C';
    towerOfHanoi(n, a,b,c);
    
}