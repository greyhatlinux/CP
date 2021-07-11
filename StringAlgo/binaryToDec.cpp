#include<bits/stdc++.h>
using namespace std; 

// int decimal(char n[]) {
//     return stoi(n, 0, 2);
// }

int decimal(int n) {
    int temp, num;
    temp = num = n;

    int dec = 0, base = 1;

    while(temp){
        int last = temp % 10;
        if(last) dec += base;
        base *= 2;

        temp /= 10;
    }
    return dec;
}

int decimal(string s) {
    int dec = 0, base = 1;
    int n = s.length()-1;
    while(n>-1){
        if(s[n] == '1') dec += base;
        base *= 2;
        n--;
    }
    return dec;
}


int main()
{   
    cout<<decimal("1011")<<"\n";
    cout<<decimal(1101)<<"\n";
    return 0;
}
