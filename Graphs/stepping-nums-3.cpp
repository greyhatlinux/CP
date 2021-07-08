#include<bits/stdc++.h>
using namespace std;

//applying DFS approach 

void dfs(int n, int m, int stepNum, int &count) {

    //if stepping num is within the range
    if(stepNum <= m & stepNum>= n) cout<<stepNum<<" ", (count)++;

    //if stepNum is greater than m, no need to explore further
    if(stepNum > m || stepNum == 0) return;

    int lastDigit = stepNum % 10;
    int num1 = stepNum*10 + lastDigit + 1;
    int num2 = stepNum*10 + lastDigit - 1;

    if(lastDigit == 0) dfs(n, m, num1, count);
    else if (lastDigit == 9) dfs(n, m, num2, count);
    else {
        dfs(n,m,num1, count);
        dfs(n,m,num2, count);
    }
}


int steppingNumbers(int n, int m) {

    if(n>m) return INT_MIN;
    if(n == m) return 0;

    int count = 0;
    for(int i=0;i<10;i++) dfs(n,m,i, count);

    return count;
}

int main()
{
    int tc; cin>>tc; while(tc--) {
        int n,m;
        cin>>n>>m;
        int x = steppingNumbers(n,m);
        cout<<"\nTotal numbers : "<<x<<"\n";
    }
    return 0;
}

//Space efficient, doesnt take up queue space
